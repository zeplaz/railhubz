//Base_TSym_entity.cpp
#include "Base_TSym_entity.hpp"

//stdlibz
#include <cassert>

//int Base_TSym_entity::be_NextValidID = 0;

Base_TSym_entity::Base_TSym_entity(int& id_in)
{
  set_id(id_in);
}

void Base_TSym_entity::set_id(int& val)
  {
    //assert ((val>=be_NextValidID)&& "<Base_TSym_entity::set_id: broken ID>");
    val = be_NextValidID;
    be_id = val;
    be_NextValidID = be_id+1;
  }

  void Base_TSym_entity::set_type(Entity_Type&& char_idenity)
  {
    entity_type = char_idenity;
  }
