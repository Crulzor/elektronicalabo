#include "adc.h"
#include <math.h>

namespace Bodeplot {

    void Adc::adcInit(SPI * ADC, DigitalOut * CS_ADC){

        this->ADC = ADC;
        this->CS_ADC = CS_ADC;
        CS_ADC->write(1);
        ADC ->format(8,0);
        ADC ->frequency(1000000);

    }

    float Adc::read_ADC(void){
        CS_ADC->write(0);
        uint8_t high = ADC->write(0x00);
        uint8_t low = ADC->write(0x00);
        CS_ADC->write(1);

        high = high & 0x1F; //clear unknown bits
        low = low >> 1; //shift low 1 bit to the right
        low = low | ((high & 0x01) << 7); //add the first bit from high and add it to low
        high = high >> 1; //shift high 1 bit to the right

        uint16_t data = (high << 8) | low;  //add high and low together
        float voltage = (data *3.3)/4096;

        return voltage;
    
    
    }

    


};