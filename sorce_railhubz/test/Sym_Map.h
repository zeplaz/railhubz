//Sym_Map.h



#pragma once
            #include "railhubz.h"

#include <map>
#include <cassert>
#include <vector>




static const int window_Hight =640;
static const int window_Width = 800;


class railhubz;

#define sym_manger Sym_Map::Instance()

class Sym_Map
{

private:
    typedef std::map<int,railhubz*> Hubz_map;
//    typedef std::map<int,int>  hub_path_matrixPos;

private:
    int hubz;
            Hubz_map inst_hub_map;

        //disable copyconstrcor

        Sym_Map(const Sym_Map&);
        Sym_Map& operator =(const Sym_Map&);

public :

    static Sym_Map* Instance();

    Sym_Map(){}; // deal with id latr.

    ~Sym_Map(){};
                //should erase?maps?

        std::vector<int>* hublist();

        void Register_hubz(railhubz* newhubz);

        railhubz* get_hub_via_id(int id) const;

        void remove_hubz(railhubz* prt_hub);
    //void    draw_hubz(sf::RenderWindow& window);


};
