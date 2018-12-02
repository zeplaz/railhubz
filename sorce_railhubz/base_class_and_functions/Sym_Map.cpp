

//Sym_Map.cpp

#include "Sym_Map.h"

//#include "Cmd_agent_operator.h"

    Sym_Map* Sym_Map::Instance()
    {
        static Sym_Map instance;
        return &instance;
    }

    int Sym_Map::numberofentities()
    {
        return (inst_enity_map.size());
    }



     Base_TSym_entity* Sym_Map::get_entity_via_id(int id) const

        {
            entity_map::const_iterator cons_itor =inst_enity_map.find(id);
            assert ((cons_itor != inst_enity_map.end()) && "<Sym_Map::get_entity_via_id>:ERROR");

            return cons_itor->second;
        }

     void Sym_Map::removeenity(Base_TSym_entity* ptrentity)
        {
            inst_enity_map.erase(inst_enity_map.find(ptrentity->ID()));
        }

     void Sym_Map::Register_entity(Base_TSym_entity* newentity)
        {
            inst_enity_map.insert(std::make_pair(newentity->ID(),newentity));
        }

/*
    void Sym_Map::draw_entityz(sf::RenderWindow& window)
    {
        for(auto it = inst_hub_map.cbegin(); it != inst_hub_map.cend(); ++it)
        {
            railhubz* temphubz_Draw = it->second;
            temphubz_Draw->draw(window);
        }

      }


          std::vector<int>* Sym_Map::hublist()
            { std::vector<int>* hub_id_list;

                for(auto it = inst_hub_map.cbegin(); it != inst_hub_map.cend(); ++it)
                {


                           hub_id_list->push_back(it->first);
                }
                return  hub_id_list;
            }


      */
