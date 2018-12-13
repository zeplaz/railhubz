//Sym_Map.h



#pragma once
        #include <SFML/Graphics.hpp>


        #include "Base_TSym_entity.h"
                                    //    #include "R_linez.h"
#include <map>
#include <cassert>
#include <vector>

                                //#include "Cmd_agent_operator.h"


static const int window_Hight =640;
static const int window_Width = 800;

class Base_TSym_entity;


#define sym_manger Sym_Map::Instance()

class Sym_Map
{

private:

    typedef std::map<int,Base_TSym_entity*> entity_map;
    //typedef



private:

    int rail_linez;
                std::vector<int> hub_idlist;
                            //std::map<int,R_linez*> Rail_map;

//inilzate isnaces of maps
    entity_map inst_enity_map;

        //disable copyconstrcor

        Sym_Map(const Sym_Map&);
        Sym_Map& operator =(const Sym_Map&);

public :

    static Sym_Map* Instance();

    Sym_Map(){}; // deal with id latr.

    ~Sym_Map(){};
                //should erase?maps?

    int numberofentities();


        std::vector<int>* hublist();

        void Register_entity(Base_TSym_entity* newentity);

        Base_TSym_entity* get_entity_via_id(int id)const;

        void removeenity(Base_TSym_entity* ptr_entity);

        void add_hub_list(int id_h);



    //void     Draw_maped_enties(sf::RenderWindow& window);

    //void  draw_trainz(sf::RenderWindow& window);
//    void draw_linez(sf::RenderWindow& window);
//    void     draw_hubz(sf::RenderWindow& window);

    //    float get_cartesian_plane(bool H_1_W_0, float plane);


//void addLinez(int& Line_id, R_linez& newRline);
//void add_hubz(int& hub_id,railhubz& newhub);

};
