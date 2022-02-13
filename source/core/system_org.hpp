//drivers.hpp

#pragma once

#include <unordered_map>
#include <vector>
#include <string>
#include <memory>

//#include "railhubz.hpp"
//#include "factoryz.hpp"
//#include "Cmd_agent_v3Operaor.hpp"

#include "../h_libs/id_gen.h"
#include "Defined_train_path.hpp"

#define sym_manger system_org::Sym_Map::instance()

class Base_TSym_entity;
class railhubz;
class factory_ctlr;
class R_linez;
class entity_factory;




namespace system_org
{

  typedef std::unordered_map<E_ID,railhubz*> Hub_map;
  typedef std::unordered_map<size_t, Base_TSym_entity*> Entity_map;
  typedef std::unordered_map<std::string,int> String_int_lookup;     
  
  class Sym_Map final
  {
    friend class Cmd_agent_operator;

    private :

      Sym_Map();
      ~Sym_Map();

      Entity_map rail_entity_map;
      String_int_lookup lookuptable;     

      std::vector<Defined_train_path<railhubz>> train_path_vec;

      factory_ctlr* mfactory_ctrlr;


    public :

      std::vector<E_ID> r_line_id_list;
      std::vector<E_ID> train_id_list;
      std::vector<E_ID> hub_id_list;

      //untill can figure out how to do the iterators or freind
        Hub_map hubz_map;
        //public itteratorz
        //std::unordered_map<size_t,railhubz*>::iterator ittr_hub =hubz_map.begin();
        //hubz_map.end();

      //instance
      static Sym_Map& instance();

      //deletaed copy and move
      Sym_Map(const Sym_Map&) = delete;
      Sym_Map(Sym_Map&&) = delete;
      Sym_Map& operator = (const Sym_Map&) = delete;
      Sym_Map& operator = (Sym_Map&&) = delete;

      //hub procedurez
      void Register_hubz(railhubz* newhubz);
      railhubz* get_hub(size_t id) const;

      // entity procedurez
      void Register_rail_entity(Base_TSym_entity* newentity);
      Base_TSym_entity* get_rail_entity(E_ID id)  const;
      std::unique_ptr<std::vector<R_linez*>> retrieve_R_linez();

      //path procedurez
      std::vector<std::string> construct_pathz(std::string& raw_path);
      void registar_pathz(std::vector<std::string>& str_pathz);

      inline  const Defined_train_path<railhubz>& rtn_train_path(int index)
      {
        return train_path_vec.at(index);
      }

      inline int num_of_paths()
      {
        return train_path_vec.size();
      }


      //sytem proz
      
       int find_lookuptable(std::string input);
      void update_rail_entityz();

      //factory crlz
      void insert_facgroup_ctrl(std::string f_name,
                               std::vector<std::shared_ptr
                              <entity_factory>> in_fac);

      void add_factory(std::string e_name,
                       std::shared_ptr<entity_factory> factory);

      void activate_factory(std::string);
  };
}
