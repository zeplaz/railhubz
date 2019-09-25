//test_entity1.h

#pragma once

//#include "Sym_Map.h"
#include "Base_TSym_entity.h"

#include "msg_cmdz.h"
#include "msg_dispatcher.h"
#include <iostream>
struct telagram;

class test_entity1 : public Base_TSym_entity

{
  private:
  int somedata;


  public:
    int reciveddata=0;

test_entity1(int id_e):Base_TSym_entity(id_e){}

~test_entity1();
 void update();

 bool Handle_telagram(const telagram& tela);


int returnsomedata();

void changedata (int x);

};
