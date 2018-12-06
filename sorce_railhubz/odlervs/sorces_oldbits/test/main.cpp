#include <time.h>

#include "Sym_Map.h"
//#include "Base_TSym_entity.h"
//#include "trainz.h"
//#include "R_linez.h"

#include "railhubz.h"
#include <stdio.h>
//#include "msg_cmdz.h"
//#include "msg_dispatcher.h"
#include <iostream>
//#include "Cmd_agent_operator.h"

int main() {


    //static int cycles;
 int enity_count=0;
 int count_train_hubz=0;

    printf("Welcome To Trainsym MainRun\n");

//    int stattrain_rounds;
//    int linesetupval;
//count_train_hubz++;
time_t cmd_time_start = clock();

float x = 43.6532f;
float y = 79.3832f;

printf("srailhub 234 %s :\n", count_train_hubz);

railhubz* tro = new railhubz(cmd_time_start,sf::Vector2f(x,y),count_train_hubz);
std::cout << "this is trublsum: " << count_train_hubz;
sym_manger->Register_hubz(tro);


x = 45.5088f;
y = 73.552f;


railhubz* mtl = new railhubz(cmd_time_start,sf::Vector2f(x,y),count_train_hubz);
sym_manger->Register_hubz(mtl);
printf("Montreal_ID: %s \n",mtl->id);


return 0;
}
