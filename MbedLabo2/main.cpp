//Compile: 
//g++ -o labo main.cpp 
//mbed compile -f

#include <iostream>         // System-wide library
#include <string>
#include "stm32l476xx.h"
#include "mbed.h"
#include "src/adc.h"
#include "src/amp.h"
#include "src/cap.h"
#include "src/dds.h"
#include <math.h>

using namespace std;
using namespace Bodeplot;

SPI ADC(NC, PB_4,PB_3); // ADC SPI communication -   mosi, miso, sclk
SPI DDS(PC_12, NC, PC_10); // dds SPI communication - mosi, miso, sclk

DigitalOut CS_DDS(PA_13, 1);
DigitalOut CS_ADC(PA_10);

DigitalOut IN_AMP_2(PA_12);
DigitalOut IN_AMP_4(PA_11);
DigitalOut IN_AMP_10(PB_12);
DigitalOut IN_AMP_100(PB_11);
DigitalOut DDS_AMP_A1(PA_4);
DigitalOut DDS_AMP_A0(PB_0);

DigitalOut CAP(PC_5);




int main()
{
    cout << "initializing" <<endl;
    Adc adc;
    Dds dds;
    Amp amp;
    Cap cap;
    //initialize
    cap.cap_init(&CAP);
    dds.DDSInit(&DDS, &CS_DDS);
    adc.adcInit(&ADC, &CS_ADC);
    amp.initialize_DDS_AMP(&DDS_AMP_A1, &DDS_AMP_A0);
    amp.initialize_IN_AMP(&IN_AMP_2, &IN_AMP_4, &IN_AMP_10, &IN_AMP_100);
 
    std::string testString = "Everything Initialized";
    printf("%s \n",testString.c_str());

    //set amplification
    cap.dischargeCap();
    amp.set_DDS_AMP(1);
    amp.set_IN_AMP(1);

    //dds.setFrequency(10000);
    //sweepfrequency
    dds.sweepDDS(100, 10, 20000, adc, amp, cap);


    

    while(1){
    
    //float output = adc.read_ADC();
    //printf("%f %c\n", output, '\n');
    // wait_us(5*(1/10000)*1000000); //wait 4 periods before ADC

    }
   
 return 0;
}