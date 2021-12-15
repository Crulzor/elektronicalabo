#include "cap.h"

namespace Bodeplot{

    void Cap::cap_init(DigitalOut * CAP){
        this->CAP = CAP;


    }
    void Cap::dischargeCap(){
        CAP->write(1);
        wait_us(5000);
        CAP->write(0);

    }


};