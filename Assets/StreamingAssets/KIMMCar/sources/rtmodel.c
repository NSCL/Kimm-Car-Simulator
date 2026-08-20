#include "KIMMCar_macros.h"
#include "rtmodel.h"

void KIMMCar_step(int_T tid)
{
  switch (tid) {
   case 0 :
    KIMMCar_step0();
    break;

   case 2 :
    KIMMCar_step2();
    break;

   default :
    break;
  }
}
