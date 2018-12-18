
#include "mathStatz.h"



mathStatz* mathStatz::Instance()
  {
      static mathStatz instance;
      return &instance;
  }
