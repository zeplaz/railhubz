//factoryz.hpp
#pragma once

#include "railhubz.hpp"

#include <vector>
#include <memory>
#include <string>


namespace system_org
{
  class entity_factory
  {
    public :
     //void (*fac_reg_calbk)(Base_TSym_entity*);
     virtual ~entity_factory() = default;
     void request_entity();
     size_t get_num_entityz_produced() const;
     bool bussy = false;


    protected :

     virtual Base_TSym_entity* create_entity() = 0;

    private :
     size_t number_of_entityProduced = 0;
  };

  class R_line_factory : public entity_factory
  {
    protected :
     virtual Base_TSym_entity* create_entity() override;
    public :
     R_line_factory(){}
     virtual ~R_line_factory() = default;
  };

  class trainz_factory : public entity_factory
  {
    protected :
     virtual Base_TSym_entity* create_entity() override;

    public :
     trainz_factory(){}
     virtual ~trainz_factory() = default;
  };

  class factory_ctlr : entity_factory
  {

    public :
      explicit factory_ctlr(std::vector<std::shared_ptr<entity_factory>>&& factoryz){};
      factory_ctlr() = default;
      virtual ~factory_ctlr()= default;

      void register_factory_group(std::pair<std::string,
                                  std::vector<std::shared_ptr
                                  <entity_factory>>> in_fac_group);

      void add_factory_to_ctlgroup(std::string f_name,
                                   std::shared_ptr<system_org::entity_factory> in_fac);

      std::shared_ptr<entity_factory> scan_factoryz(std::string f_name);
    protected :
      virtual Base_TSym_entity* create_entity() override;
    private :
      std::unordered_map<std::string,std::vector<std::shared_ptr
                        <entity_factory>>> factory_map;
  };

}
