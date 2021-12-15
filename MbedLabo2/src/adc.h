#pragma once
#include <iostream>
#include "mbed.h"

namespace Bodeplot{

    class Adc{

        public: 
            void adcInit(SPI * ADC, DigitalOut * CS_ADC);
            float read_ADC(void);

        private:
            SPI * ADC;
            DigitalOut * CS_ADC;



    };

}
