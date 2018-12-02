
//debugmsgz_nov12.cpp



#include <time.h>

#include "Sym_Map.h"
#include "Base_TSym_entity.h"

#include "msg_cmdz.h"
#include "msg_dispatcher.h"

    //#include "R_linez.h"
#include "test_entity1.h"
#include "railhubz.h"


int main ()

{

int total_entityz=0;

clock_t start_prog_t =clock();
time_t currnttime = start_prog_t;

test_entity1* test_e1 = new test_entity1(total_entityz);

total_entityz++;
sym_manger->Register_entity(test_e1);

test_entity1* test_e2 = new test_entity1(total_entityz);

total_entityz++;
sym_manger->Register_entity(test_e2);




for (int i =0; i<20; ++i )
{
test_e1->update();
test_e2->update();


}

delete test_e1;
delete test_e2;

//PressAnyKeyToContinue();


return 0;
}
