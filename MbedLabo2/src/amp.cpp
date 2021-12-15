#include "amp.h"

namespace Bodeplot{

void Amp::initialize_IN_AMP(DigitalOut * IN_AMP_2, DigitalOut * IN_AMP_4, DigitalOut * IN_AMP_10, DigitalOut * IN_AMP_100){

    this->IN_AMP_2 = IN_AMP_2;
    this->IN_AMP_4 = IN_AMP_4;
    this->IN_AMP_10 = IN_AMP_10;
    this->IN_AMP_100 = IN_AMP_100;    


}

void Amp::initialize_DDS_AMP(DigitalOut * DDS_AMP_A1, DigitalOut * DDS_AMP_A0){
  this->DDS_AMP_A1 = DDS_AMP_A1;
  this->DDS_AMP_A0 = DDS_AMP_A0;

}

void Amp::set_DDS_AMP(int amplification){

      switch(amplification) {
      case 1:
        DDS_AMP_A1->write(0);
        DDS_AMP_A0->write(0);
        break;
      case 2:
        DDS_AMP_A1->write(0);
        DDS_AMP_A0->write(1);
        break;
      case 4:
        DDS_AMP_A1->write(1);
        DDS_AMP_A0->write(0);
        break;
      case 8:
        DDS_AMP_A1->write(1);
        DDS_AMP_A0->write(1);
        break;
      default:
        DDS_AMP_A1->write(0);
        DDS_AMP_A0->write(0);

  }
}


    
void Amp::set_IN_AMP(int amplification) {

    switch(amplification) {
      case 1:
        IN_AMP_2->write(0);
        IN_AMP_4->write(0);
        IN_AMP_10->write(0);
        IN_AMP_100->write(0);
        break;
      case 2:
        IN_AMP_2->write(1);
        IN_AMP_4->write(0);
        IN_AMP_10->write(0);
        IN_AMP_100->write(0);
        break;
      case 4:
        IN_AMP_2->write(0);
        IN_AMP_4->write(1);
        IN_AMP_10->write(0);
        IN_AMP_100->write(0);
        break;
      case 8:
        IN_AMP_2->write(1);
        IN_AMP_4->write(1);
        IN_AMP_10->write(0);
        IN_AMP_100->write(0);
        break;
      case 10:
        IN_AMP_2->write(0);
        IN_AMP_4->write(0);
        IN_AMP_10->write(1);
        IN_AMP_100->write(0);
        break;
      case 20:
        IN_AMP_2->write(1);
        IN_AMP_4->write(0);
        IN_AMP_10->write(1);
        IN_AMP_100->write(0);
        break;
      case 40:
        IN_AMP_2->write(0);
        IN_AMP_4->write(1);
        IN_AMP_10->write(1);
        IN_AMP_100->write(0);
        break;
      case 80:
        IN_AMP_2->write(1);
        IN_AMP_4->write(1);
        IN_AMP_10->write(1);
        IN_AMP_100->write(0);
        break;
      case 100:
        IN_AMP_2->write(0);
        IN_AMP_4->write(0);
        IN_AMP_10->write(0);
        IN_AMP_100->write(1);
        break;
      case 200:
        IN_AMP_2->write(1);
        IN_AMP_4->write(0);
        IN_AMP_10->write(0);
        IN_AMP_100->write(1);
        break;
      case 400:
        IN_AMP_2->write(0);
        IN_AMP_4->write(1);
        IN_AMP_10->write(0);
        IN_AMP_100->write(1);
        break;
      case 800:
        IN_AMP_2->write(1);
        IN_AMP_4->write(1);
        IN_AMP_10->write(0);
        IN_AMP_100->write(1);
        break;
      default:
        IN_AMP_2->write(0);
        IN_AMP_4->write(0);
        IN_AMP_10->write(0);
        IN_AMP_100->write(0);
    }
  }


};
