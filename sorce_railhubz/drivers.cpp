//drivers.cpp

#include <cassert>
#include <iostream>

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
        std::unordered_map<size_t,railhubz*>::const_iterator cons_itor =
                                                             hubz_map.find(id);

        assert ((cons_itor != hubz_map.end()) && "<Sym_Map::get_hub_via_id>:ERROR");
        return cons_itor->second;
    }

    void system_org::Sym_Map::Register_rail_entity(Base_TSym_entity* newentity)
    {
      std::cout << "New_renderable entity ID::" << newentity->get_ID() <<'\n';
      rail_entity_map.insert(std::pair<int,Base_TSym_entity*>(newentity->get_ID(),
                                                                      newentity));
    }

    Base_TSym_entity* system_org::Sym_Map::get_rail_entity(int id) const
    {
      std::unordered_map<int,Base_TSym_entity*>::const_iterator cons_itor =
                                                           rail_entity_map.find(id);
      assert ((cons_itor != rail_entity_map.end()) && "<Sym_Map::get_hub_via_id>:ERROR");
      return cons_itor->second;
    }
  //Sym_Map factory defintionsz

  void system_org::Sym_Map::insert_facgroup_ctrl(std::string f_name,
                                                std::vector<std::shared_ptr
                                                <entity_factory>> in_fac)
  {
    mfactory_ctrlr.register_factory_group(std::make_pair(f_name,std::move(in_fac)));
  }
  void system_org::Sym_Map::add_factory(std::string e_name,
                                        std::shared_ptr<entity_factory> factory)
   {
      mfactory_ctrlr.add_factory_to_ctlgroup(e_name,std::move(factory));
   }
  void system_org::factory_ctlr::add_factory_to_ctlgroup(std::string f_name,
                                                         std::shared_ptr<entity_factory> in_fac)
   {
    std::unordered_map<std::string,std::vector<std::shared_ptr
                        <entity_factory>>>::iterator c_itr = factory_map.find(f_name);
     if ( c_itr == factory_map.end() )
      {
        std::cout<< "no factory vector, adding new vector::" << typeid(*in_fac).name() <<'\n';
        std::vector<std::shared_ptr<entity_factory>> vec_fac;
        vec_fac.push_back(std::move(in_fac));

        std::pair <std::string,std::vector<std::shared_ptr<entity_factory>>> name_vec_pair;
        name_vec_pair = std::make_pair(f_name,std::move(vec_fac));

        system_org::factory_ctlr::factory_map.insert(std::move(name_vec_pair));
      }
      else
      {
        std::cout << "in interatorname:: " <<typeid(*c_itr->second.at(0)).name() <<'\n'
        << "added factory prr_derefenz name:: " <<typeid(*in_fac).name() << '\n';

           if(typeid(*c_itr->second.at(0)) != typeid(*in_fac))
           std::cout << "<Sym_Map::wrong factory typed>:ERROR";
           else
           c_itr->second.push_back(std::move(in_fac));
       }
     }
  void system_org::factory_ctlr::register_factory_group(std::pair<std::string,
                                                        std::vector<std::shared_ptr
                                                        <entity_factory>>> in_fac_group)
  {
    system_org::factory_ctlr::factory_map.insert(std::move(in_fac_group));
  }

  system_org::Sym_Map::~Sym_Map()
    {
        rail_entity_map.clear();
        hubz_map.clear();
    }

  void system_org::entity_factory::request_entity()
  {
    //fac_reg_calbk =
    //using reg_map_prt = void (system_org::Sym_Map::*)(Base_TSym_entity*);
  //  reg_map_prt fac_reg_clbk = &system_org::Sym_Map::Register_rail_entity;
    std::cout << "##->request_entity" <<'\n';
    ++number_of_entityProduced;
    sym_manger.Register_rail_entity(create_entity());
     //fac_reg_clbk->*;
  }

  size_t system_org::entity_factory::get_num_entityz_produced() const
  {
    return number_of_entityProduced;
  }

  Base_TSym_entity* system_org::trainz_factory::create_entity()
  {
    trainz* prt_new_train = new trainz();
    sym_manger.train_id_list.push_back(prt_new_train->get_ID());
    return prt_new_train;
  }
  Base_TSym_entity* system_org::R_line_factory::create_entity()
  {
    R_linez* prt_new_R_line = new R_linez();
    sym_manger.r_line_id_list.push_back(prt_new_R_line->get_ID());
    return prt_new_R_line;
  }
/*
  system_org::factory_ctlr::factory_ctlr(std::vector<std::shared_ptr<entity_factory>>&& factoryz)
    : factory_vec(std::move(factoryz))
  {
    if(factory_vec.empty())
    {
      throw std::runtime_error("missinz factoryz");
    }
  }
  */
  std::shared_ptr<system_org::entity_factory> system_org::factory_ctlr::scan_factoryz
                                                      (std::string f_name)
  {
    std::cout << "##->scan_factoryz!" <<'\n';
    std::unordered_map<std::string,std::vector<std::shared_ptr
                        <system_org::entity_factory>>>::iterator c_itr = factory_map.find(f_name);
     if ( c_itr == factory_map.end() )
      {
        std::cout << "failed to find factory doom" << '\n';
      }
      else
      {
        std::vector<std::shared_ptr<system_org::entity_factory>> temp_fac_vec = c_itr->second;

        for(size_t i=0; i < temp_fac_vec.size(); i++)
        {
          if(!temp_fac_vec.at(i)->bussy)
          {
            std::cout << "bussy:" << temp_fac_vec.at(i)->bussy;
            temp_fac_vec.at(i)->bussy = true;
            return temp_fac_vec.at(i);
          }
          if(i == temp_fac_vec.size())
          {std::cout << "all factoez are bussy :(" << '\n';}
        }
      }
  }
  void system_org::Sym_Map::activate_factory(std::string to_make)
  {
    std::cout<< "##->activate_factory!" <<'\n';
    std::shared_ptr<system_org::entity_factory> temp_fac = mfactory_ctrlr.scan_factoryz(to_make);
    temp_fac->request_entity();
    temp_fac->bussy = false;
    //reg_map_prt callback =&system_org::Sym_Map::Register_rail_entity;
    //
    //system_org::Sym_Map::fac_clbk = ;
    // =
    //      &system_org::Sym_Map::Register_rail_entity;
  //  auto  fac_reg_callbk =
  //  temp_fac->request_entity(fac_clbk);
  }

  Base_TSym_entity* system_org::factory_ctlr::create_entity()
  {
  /*  //stuff
  system_org::entity_factory::fac_reg_calbk = &system_org::Sym_Map::Register_rail_entity;
    */

  }
  void system_org::Sym_Map::render_entiez(sf::RenderWindow &window)
  {
    for ( auto it = rail_entity_map.begin(); it != rail_entity_map.end(); ++it )
      {
         it->second->draw(window);
      }
  }


  void driver::initializer()
  {
    std::string rail_type1 = "rail01";
    std::string train_type1 = "train01";
    //std::vector<std::shared_ptr<system_org::entity_factory>> Rail_factoyz;
    std::vector<std::shared_ptr<system_org::entity_factory>> train_factoryz;

    train_factoryz.push_back(std::make_shared<system_org::trainz_factory>());
    train_factoryz.push_back(std::make_shared<system_org::trainz_factory>());

    sym_manger.insert_facgroup_ctrl(train_type1,std::move(train_factoryz));
    //sym_manger.insert_facgroup_ctrl(rail_type1,std::move(Rail_factoyz));


    sym_manger.add_factory(rail_type1,std::make_shared<system_org::R_line_factory>());
    sym_manger.add_factory(rail_type1,std::make_shared<system_org::R_line_factory>());

    sym_manger.activate_factory(rail_type1);
    sym_manger.activate_factory(rail_type1);

    R_linez* templine = dynamic_cast<R_linez*>(sym_manger.get_rail_entity(sym_manger.r_line_id_list[0]));
    templine->set_pos(100.f,300.f,200.f,20.f);
    templine = dynamic_cast<R_linez*>(sym_manger.get_rail_entity(sym_manger.r_line_id_list[1]));
    templine->set_pos(10.f,30.f,200.f,200.f);
    //train_factoryz.at(0)->;

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
