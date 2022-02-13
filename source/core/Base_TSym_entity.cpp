//Base_TSym_entity.cpp
#include "Base_TSym_entity.hpp"

//stdlibz



Base_TSym_entity::Base_TSym_entity()
{
}

void Base_TSym_entity::set_type(Entity_Type&& char_idenity)
  {
    entity_type = char_idenity;
  }
