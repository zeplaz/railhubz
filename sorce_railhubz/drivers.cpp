//drivers.cpp

#include "drivers.hpp"

Sym_Map& system_org::Sym_Map::instance()
 {
  static Sym_Map instance;
  return instance;
 }

system_org::Sym_Map::~Sym_Map()
  {
    for ( auto it = rail_entity_map.begin(); it != rail_entity_map.end(); ++it )
     {
       delete[] it->second;
     }
     for ( auto it = hubz_map.begin(); it != hubz_map.end(); ++it )
      {
        delete[] it->second;
      }
  }

  system_org::entity_factory::request_entity()
  {
    ++number_of_entityProduced;
    return create_entity();
  }

  size_t system_org::entity_factory::get_num_entityz_produced() const
  {
    return number_of_entityProduced;
  }

  Base_TSym_entity* create_entity()
  {
    trainz* prt_new_train = new trainz();
    return
  }
  Base_TSym_entity* create_entity()
  {

  }
