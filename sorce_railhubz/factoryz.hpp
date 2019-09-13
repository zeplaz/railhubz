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
     virtual ~entity_factory() = default;
     Base_TSym_entity* request_entity();
     size_t get_num_entityz_produced() const;

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
      explicit factory_ctlr(std::vector<std::unique_ptr<entity_factory>>&& factoryz){};
      factory_ctlr(){};
      virtual ~factory_ctlr()= default;

      void register_factory_group(std::pair<std::string,
                                  std::vector<std::unique_ptr
                                  <entity_factory>>> in_fac_group);

      void add_factory_to_ctlgroup(std::string f_name,
                                   std::unique_ptr<system_org::entity_factory> in_fac);
    //void scan_producerz(std::string);
    protected :
      virtual Base_TSym_entity* create_entity() override;

    private :
      std::unordered_map<std::string,std::vector<std::unique_ptr
                        <entity_factory>>> factory_map;
  };

}
