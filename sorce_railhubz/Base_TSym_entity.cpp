//Base_TSym_entity.cpp
#include "Base_TSym_entity.hpp"

//stdlibz
#include <cassert>

int Base_TSym_entity::be_NextValidID = 0;
int be_id;

void Base_TSym_entity::set_id(int val)
  {
    assert ((val>=be_NextValidID)&& "<Base_TSym_entity::set_id: broken ID>");
    be_id = val;

    be_NextValidID = be_id+1;
  }
