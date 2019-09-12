//drivers.hpp

#include "railhubz.h"
#include <unordered_map>

/*namespace driver
{
    static int enity_railz;
    static int hubz;
  void  initializer()
   {

   }

   void drive_loop()
   {

   }

}
*/
namespace system_org
{
  class Base_TSym_entity;
  class railhubz;

  static int rail_entityz;
  #define sym_manger Sym_Map::instance()

  class Sym_Map final
  {
    private :
      Sym_Map();
      ~Sym_Map();
      std::unordered_map<int, Base_TSym_entity*> rail_entity_map;
      std::unordered_map<size_t,railhubz*> hubz_map;

    public :
      static Sym_Map& instance();

      Sym_Map(const Sym_Map&) = delete;
      Sym_Map(Sym_Map&&) = delete;
      Sym_Map& operator = (const Sym_Map&) = delete;
      Sym_Map& operator = (Sym_Map&&) = delete;

      void Register_hubz(railhubz* newhubz);
      railhubz* get_hub(int id) const;
      void Register_rail_entity(Base_TSym_entity* newentity);
      Base_TSym_entity* get_rail_entity(int id)const;
  };

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
  };

  class trainz_factory : public entity_factory
  {
    protected :
     virtual Base_TSym_entity* create_entity() override;
  };

}
