
#pragma once

#include "msg_cmdz.h"
#include "msg_dispatcher.h"
//#include "vector_math.h"
//#include "priorty_Objc_que.h"

#include "Base_TSym_entity.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "enity_1test.h"
#include "R_linez.h"

#include "Ponter_priorty_trainz.h"

#include <time.h>
#include <queue>
#include <vector>

//struct Priorty_for_station_que;
struct telagram;
class enity_1test;
class R_linez;
//class Ponter_priorty_trainz;


                    //return lhs->get_train_priority() < rhs->get_train_priority();
class enity_2test: public Base_TSym_entity
{
protected :
        sf::CircleShape cr_hubgraphic;
       sf::Vector2f Location;
    //double train_x;
    //double train_y;
        int entity_2_id;
       time_t stationary_enity_t;

std::vector<R_linez*> line_connections;

struct priorty_trainz_data_Stc{

    int id_train;
    double priority;

bool operator < (const priorty_trainz_data_Stc &o) const
    {
        return priority < o.priority;
    }

}priorty_trainz_data;

std::priority_queue <priorty_trainz_data_Stc>  train_quez;



//void add_train_toque(* traintoQues);


//i//nt return_highest_prioty_train_id();


//void put_priotytrain_on_line();





    public :
        void add_trainto_data_que(enity_1test* in_train_que);
        void put_priotytrain_on_line();
        int return_highest_prioty_train_id();
        //enity_2test* get_entity_via_id();
         void update();
         bool Handle_telagram(const telagram& tela);

         sf::Vector2f get_location();

        int get_id();
        void initialize(time_t c_time, sf::Vector2f stloc);
        void draw(sf::RenderWindow &window);
        bool are_train_waiting();

    ///    void add_to_pq();
    //    void remove_from_pq();
    //    enity_1test* top_from_pq();


~enity_2test();

enity_2test (time_t cur_time, sf::Vector2f locvec, int& total_enty): Base_TSym_entity(total_enty)
{
    entity_2_id = total_enty;
    total_enty++;
    initialize(cur_time, locvec);
}


std::vector<R_linez*> return_prt_lineconections()
{ return line_connections; }

void add_line_connection(R_linez* newline);



};
