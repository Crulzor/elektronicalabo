#include "dds.h"
#include "amp.h"
#include <math.h>
#include "cap.h"

namespace Bodeplot{

    //initialize DDS with pointer
    void Dds::DDSInit(SPI * DDS, DigitalOut * CS_DDS){
        this->DDS = DDS;
        this->CS_DDS = CS_DDS;  
        DDS->format(8,2);    //Mode 2 
        DDS->frequency(1000000);
        CS_DDS->write(1);

    }
    void Dds::setFrequency(float frequency){

        //start with 32bits, calc frequency
        uint32_t freqReg = frequency * 16.777216;
        CS_DDS->write(0);

        char tx[2] = {0x21, 0x00};
        DDS->write(tx, 2, nullptr, 0);
        
        //split the registry in 2 x 16 bits, AND + shift to select bits.
        uint16_t LSB = freqReg & 0x0003FFF;
        uint16_t MSB = (freqReg >> 14) & 0x0003FFF;


        //split it even further in 4 x 8 bits.
       char firstWord[2] = {((LSB >> 8) + 0x40) , (LSB & 0x00FF) };
       char secondWord[2] = {((MSB >> 8) + 0x40) ,(MSB & 0x00FF) };
       char reset[2] = {0x00, 0x00};

        //write(pointer to byte array, nr of bytes to write, ptr of array to read from, nr of bytes to read)
       DDS->write(firstWord, 2, nullptr, 0);
       DDS->write(secondWord, 2, nullptr, 0);
       DDS->write(reset, 2, nullptr, 0);

       CS_DDS->write(1);



    }



void Dds::sweepDDS(uint32_t steps, float min_frequency, float max_frequency, Adc adc, Amp amp, Cap cap) {
    
   
    float log_range =  log10(max_frequency/min_frequency);
    float min_value = log10(min_frequency);
    for(int i = 0; i <= log_range*steps; i++) {
        float frequency = pow(10, (min_value+((i/(log_range*steps)))*log_range));
        setFrequency(frequency);
        //cap.dischargeCap();
        wait_us(50000);
        wait_us(5*(1/frequency)*1000000); //wait 4 periods before ADC

        float voltage = adc.read_ADC();
        float highpass = 20*log10((voltage)/0.3);
        printf("%.1f %.1f\n", highpass, frequency);


    
    }
  }

      





}