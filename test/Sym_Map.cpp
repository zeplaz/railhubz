

//Sym_Map.cpp

#include "Sym_Map.h"

//#include "Cmd_agent_operator.h"

    Sym_Map* Sym_Map::Instance()
    {
        static Sym_Map instance;
        return &instance;
    }


    void Sym_Map::Register_hubz(railhubz* newhub)
      { printf("in regiserfunction\n");

          inst_hub_map.insert( std::pair<int,railhubz*>(newhub->id, newhub) );

          hubz++;

        }

    void Sym_Map::remove_hubz(railhubz* prt_hub)
      {
          inst_hub_map.erase(inst_hub_map.find(prt_hub->id));
          hubz--;
      }

    std::vector<int>* Sym_Map::hublist()
      { std::vector<int>* hub_id_list;

          for(auto it = inst_hub_map.cbegin(); it != inst_hub_map.cend(); ++it)
          {


                     hub_id_list->push_back(it->first);
          }
                return  hub_id_list;
      }

    railhubz* Sym_Map::get_hub_via_id(int id) const
      {
          Hubz_map::const_iterator cons_itor =inst_hub_map.find(id);

          assert ((cons_itor != inst_hub_map.end()) && "<Sym_Map::get_hub_via_id>:ERROR");
          return cons_itor->second;
      }

/*
    void Sym_Map::draw_hubz(sf::RenderWindow& window)
    {
        for(auto it = inst_hub_map.cbegin(); it != inst_hub_map.cend(); ++it)
        {
            railhubz* temphubz_Draw = it->second;
            temphubz_Draw->draw(window);
        }

      }
*/
