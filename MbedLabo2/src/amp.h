#pragma once
#include <iostream>
#include "mbed.h"

namespace Bodeplot{
class Amp{

    

public:
    void set_IN_AMP(int amplification); 
    void set_DDS_AMP(int amplification);
    void initialize_IN_AMP(DigitalOut * IN_AMP_2, DigitalOut * IN_AMP_4, DigitalOut * IN_AMP_10, DigitalOut * IN_AMP_100);
    void initialize_DDS_AMP(DigitalOut * DDS_AMP_A1, DigitalOut * DDS_AMP_A0);
private: 
    
    DigitalOut * DDS_AMP_A1;
    DigitalOut * DDS_AMP_A0;
    DigitalOut * IN_AMP_2;
    DigitalOut * IN_AMP_4;
    DigitalOut * IN_AMP_10;
    DigitalOut * IN_AMP_100;





};
};

