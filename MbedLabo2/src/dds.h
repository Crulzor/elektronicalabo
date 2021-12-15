#pragma once
#include <iostream>
#include "mbed.h"
#include "adc.h"
#include "amp.h"
#include "cap.h"

namespace Bodeplot{

    class Dds {


        public: 
            void DDSInit(SPI * DDS, DigitalOut * CS_DDS);
            void setFrequency(float frequency);
            void sweepDDS(uint32_t steps, float minFrequency, float maxFrequency, Adc adc, Amp amp, Cap cap);
            void dischargeCap(DigitalOut * CAP);
        private:
            SPI * DDS;
            DigitalOut * CS_DDS;

    };







}