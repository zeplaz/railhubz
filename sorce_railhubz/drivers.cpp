//drivers.cpp

#include <cassert>

#include "drivers.hpp"
#include "factoryz.hpp"

 system_org::Sym_Map& system_org::Sym_Map::instance()
  {
   static system_org::Sym_Map instance;
   return instance;
  }

  void system_org::Sym_Map::Register_hubz(railhubz* newhub)
  {
    hubz_map.insert(std::pair<size_t,railhubz*>(newhub->get_ID(), newhub));
  }

  railhubz* system_org::Sym_Map::get_hub(size_t id) const
    {
        std::unordered_map<size_t,railhubz*>::const_iterator cons_itor = hubz_map.find(id);

        assert ((cons_itor != hubz_map.end()) && "<Sym_Map::get_hub_via_id>:ERROR");
        return cons_itor->second;
    }

  void system_org::Sym_Map::insert_facgroup_ctrl(std::string f_name,
                                                std::vector<std::unique_ptr
                                                <entity_factory>> in_fac)
  {
    mfactory_ctrlr.register_factory_group(std::make_pair(f_name,std::move(in_fac)));
  }
  void system_org::Sym_Map::add_factory(std::string e_name,
                                        std::unique_ptr<entity_factory> factory)
   {
      mfactory_ctrlr.add_factory_to_ctlgroup(e_name,std::move(factory));
   }
  void system_org::factory_ctlr::add_factory_to_ctlgroup(std::string f_name,
                                                         std::unique_ptr<entity_factory> in_fac)
   {
    std::unordered_map<std::string,std::vector<std::unique_ptr
                        <entity_factory>>>::iterator c_itr = factory_map.find(f_name);
     if ( c_itr == factory_map.end() )
      {
        std::vector<std::unique_ptr<entity_factory>> vec_fac;
        vec_fac.push_back(std::move(in_fac));
        int x,y;
        std::pair <std::string,std::vector<std::unique_ptr<entity_factory>>> name_vec_pair;
        name_vec_pair = std::make_pair(f_name,std::move(vec_fac));

        system_org::factory_ctlr::factory_map.insert(std::move(name_vec_pair));
      }
      else
      {//use typeinfo or dynamic cast to insure correct factory!
        //chked_factory = dynamic_cast<>
      //  if()
        c_itr->second.push_back(std::move(in_fac));
      }
     }
  void system_org::factory_ctlr::register_factory_group(std::pair<std::string,
                                                        std::vector<std::unique_ptr
                                                        <entity_factory>>> in_fac_group)
  {
    system_org::factory_ctlr::factory_map.insert(std::move(in_fac_group));
  }

  system_org::Sym_Map::~Sym_Map()
    {
        rail_entity_map.clear();
        hubz_map.clear();
    }

  Base_TSym_entity* system_org::entity_factory::request_entity()
  {
    ++number_of_entityProduced;
    return create_entity();
  }

  size_t system_org::entity_factory::get_num_entityz_produced() const
  {
    return number_of_entityProduced;
  }

  Base_TSym_entity* system_org::trainz_factory::create_entity()
  {
    trainz* prt_new_train = new trainz();
    return prt_new_train;
  }
  Base_TSym_entity* system_org::R_line_factory::create_entity()
  {
    R_linez* prt_new_R_line = new R_linez();
    return prt_new_R_line;
  }
/*
  system_org::factory_ctlr::factory_ctlr(std::vector<std::unique_ptr<entity_factory>>&& factoryz)
    : factory_vec(std::move(factoryz))
  {
    if(factory_vec.empty())
    {
      throw std::runtime_error("missinz factoryz");
    }
  }
  */

  Base_TSym_entity* system_org::factory_ctlr::create_entity()
  {
  /*  //stuff
    switch ()
    {
      case 'R' :
      {

        break;
      }
      case 'T' :
      {
        break;
      }
    }
    */
  }


  void driver::initializer()
  {
    std::vector<std::unique_ptr<system_org::entity_factory>> Rail_factoyz;
    std::vector<std::unique_ptr<system_org::entity_factory>> train_factoryz;

    Rail_factoyz.push_back(std::make_unique<system_org::R_line_factory>());
    Rail_factoyz.push_back(std::make_unique<system_org::R_line_factory>());
    train_factoryz.push_back(std::make_unique<system_org::trainz_factory>());
    train_factoryz.push_back(std::make_unique<system_org::trainz_factory>());

    sym_manger.insert_facgroup_ctrl("train01",std::move(train_factoryz));
    sym_manger.insert_facgroup_ctrl("rail01",std::move(Rail_factoyz));

    sym_manger.add_factory("train01",std::make_unique<system_org::trainz_factory>());

    
  }


          /*for ( auto it = rail_entity_map.begin(); it != rail_entity_map.end(); ++it )
           {
            //  Base_TSym_entity* tmpptr =  it->second;
            //  delete tmpptr;
           }
           for ( auto it = hubz_map.begin(); it != hubz_map.end(); ++it )
            {
              //delete it->second;
            }*/
