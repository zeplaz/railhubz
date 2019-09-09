
//Base_TSym_entity.cpp
#include "Base_TSym_entity.h"
#include <cassert>

int Base_TSym_entity::be_NextValidID = 0;


void Base_TSym_entity::set_id(int val)
{
assert ((val>=be_NextValidID)&& "<Base_TSym_entity::set_id: broken ID>");
be_id = val;

be_NextValidID = be_id+1;


}
