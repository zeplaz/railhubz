//drivers.cpp

#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <chrono>

#include "system_org.hpp"
#include "factoryz.hpp"

/*
* system_org  holds defintions for Sym_map, the factoires.
* 
*/


/*
* Sym_Map defz
* PRIMARY LIST OF DEZ FOR symap
*/
 system_org::Sym_Map& system_org::Sym_Map::instance()
  {
   static system_org::Sym_Map instance;
   return instance;
  }

  system_org::Sym_Map::Sym_Map()
  {
      lookuptable.insert(std::make_pair(std::string("qcity"),parser::h_qcity));
      lookuptable.insert(std::make_pair(std::string("shrbyz"),parser::h_shrbyz));
      lookuptable.insert(std::make_pair(std::string("mtl"),parser::h_mtl));
  }

  int system_org::Sym_Map::find_lookuptable(std::string input)
  {
    std::unordered_map<std::string,int>::const_iterator got = lookuptable.find (input);

  if ( got == lookuptable.end() )
    {std::cout << "not found";
    return -1;}
  else
    return got->second;
  }

  system_org::Sym_Map::~Sym_Map()
   {
    rail_entity_map.clear();
    hubz_map.clear();
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


     void system_org::Sym_Map::render_entiez(sf::RenderWindow &window)
     {
       for ( auto it = rail_entity_map.begin(); it != rail_entity_map.end(); ++it )
         {
            it->second->draw(window);
         }
     }

     void system_org::Sym_Map::render_hubz(sf::RenderWindow &window)
     {
       for ( auto it = hubz_map.begin(); it != hubz_map.end(); ++it )
         {
            it->second->draw(window);
         }
     }

    std::vector<std::string> system_org::Sym_Map::construct_pathz(std::string* raw_path)
    {
      std::deque<char> path_processing_que;
      std::string temp_hub_name;
      std::vector<std::string> path_station_list;
      std::cout << *raw_path <<" :name size is::" << raw_path->size() <<'\n';

      for ( std::string::iterator it=raw_path->begin(); it!=raw_path->end(); ++it)
      {
        if(*it == '>')
        {
          std::cout << "\n NEXT hub:: \n";
          continue;
        }
          if(*it == '-')
          {
            std::cout <<"begin querprocssing \n";
            size_t quezize = path_processing_que.size();
            for(size_t i =0; i<quezize; i++)
            {
              temp_hub_name.push_back(path_processing_que.front());
              path_processing_que.pop_front();
            }
            std::cout<< "pushprocessedpathnametolist:::"<<temp_hub_name <<'\n';
            path_station_list.push_back(temp_hub_name);
            temp_hub_name= "";
            //it-1;
            continue;
           }

          std::cout << "charpushed:"<< *it <<'\n';
          path_processing_que.push_back(*it);
      }

      {
        std::cout <<"begin querprocssing \n";
        size_t quezize = path_processing_que.size();
        for(size_t i =0; i<quezize; i++)
        {
          temp_hub_name.push_back(path_processing_que.front());
          path_processing_que.pop_front();
        }
        std::cout<< "pushprocessedpathnametolist:::"<<temp_hub_name <<'\n';
        path_station_list.push_back(temp_hub_name);
      }
      //path_station_list.push_back();

      //Test
      for(size_t i=0; i< path_station_list.size(); i++)
      {
        std::cout <<"STATION FOR PATH::"<< path_station_list.at(i) <<"\n";
      }

      return path_station_list;
    }


    std::unique_ptr<std::vector<R_linez*>> system_org::Sym_Map::retrieve_R_linez()
    {
      std::unique_ptr<std::vector<R_linez*>> r_line_list =
      std::make_unique<std::vector<R_linez*>>();

      std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
      auto r_iteraor = rail_entity_map.begin();

        now = std::chrono::high_resolution_clock::now();

            while( r_iteraor!=rail_entity_map.end())
            {
              R_linez* temp_ptr_rline;
              temp_ptr_rline = dynamic_cast<R_linez*> (r_iteraor->second);

              if(temp_ptr_rline !=nullptr)
                {
                  r_line_list->push_back(temp_ptr_rline);
                }
                r_iteraor++;
            }
           std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();

            std::cout << "\n Dynamiccastz took::"
                      << std::chrono::duration_cast<std::chrono::nanoseconds>(end - now).count()
                      <<"  withentiyzNUMrd:"<< r_line_list->size()<<'\n';

        return std::move(r_line_list);

      }

    /*
    *Stm_Map FACTORY COTL FUNCTIONZ
    */
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

    void system_org::Sym_Map::activate_factory(std::string to_make)
    {
      std::cout<< "##->activate_factory!" <<'\n';
      std::shared_ptr<system_org::entity_factory> temp_fac = mfactory_ctrlr.scan_factoryz(to_make);
      temp_fac->request_entity();
      temp_fac->bussy = false;
    }


    /*
    *##factory defintionsz
    */

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

     void system_org::entity_factory::request_entity()
     {
      std::cout << "##->request_entity" <<'\n';
      ++number_of_entityProduced;
      sym_manger.Register_rail_entity(create_entity());
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

      railhubz* system_org::hub_factory::request_entity(std::string id_in,float x, float y)
    {
      //bussy = true;
      sf::Vector2f hubloc;
      hubloc.x = x;
      hubloc.y = y;

      railhubz* temp_hub = new railhubz(sym_manger.find_lookuptable(id_in),hubloc);

      return temp_hub;
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
          /*for ( auto it = rail_entity_map.begin(); it != rail_entity_map.end(); ++it )
           {
            //  Base_TSym_entity* tmpptr =  it->second;
            //  delete tmpptr;
           }
           for ( auto it = hubz_map.begin(); it != hubz_map.end(); ++it )
            {
              //delete it->second;
            }*/
            /*
                  while( r_iteraor!=rail_entity_map.end())
                    {
                      //if( typeid(R_linez) == typeid(r_iteraor->second))
                      if(r_iteraor->second->get_Etype()==Entity_Type::R_LINEZ)
                      {

                        r_line_list->push_back(dynamic_cast<R_linez*> (r_iteraor->second));
                        //r_list_hold->push_back(r_iteraor->second);
                      }
                     //r_iteraor =  std::find_if(r_iteraor->second,rail_entity_map.end(),system_org::is_train);
                     r_iteraor++;
                    }

                      std::cout << "\n get_Etype took::"
                      << std::chrono::duration_cast<std::chrono::nanoseconds>(end - now).count() <<"  withentiyzNUMrd"<< r_list_hold->size()<<'\n';

                  r_iteraor = rail_entity_map.begin();
                  now = std::chrono::high_resolution_clock::now();

                  while( r_iteraor!=rail_entity_map.end())
                    { std::cout <<"R_linenamz::"<<typeid(R_linez).name()<< " ->contanedin Iterator::" <<typeid(r_iteraor->second).name() <<'\n';

                      if( typeid(R_linez).name() == typeid(r_iteraor->second).name())
                        {
                          r_list_hold->push_back(r_iteraor->second);
                        }
                       r_iteraor++;
                     }

                    end = std::chrono::high_resolution_clock::now();

                    std::cout << "\n TypeID took::"
                              << std::chrono::duration_cast<std::chrono::nanoseconds>(end - now).count()
                              <<"  withentiyzNUMrd:"<< r_list_hold->size()<<'\n';
                              r_iteraor = rail_entity_map.begin();
            */
