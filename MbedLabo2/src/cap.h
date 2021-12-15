#pragma once 
#include "mbed.h"


namespace Bodeplot{

    class Cap{

    public:
        void cap_init(DigitalOut * CAP);
        void dischargeCap();

    private:
        DigitalOut * CAP;


    
    };
}
