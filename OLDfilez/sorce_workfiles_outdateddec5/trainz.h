#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Sym_Map.h"
#include "Base_TSym_entity.h"

#include "railhubz.h"
#include "R_linez.h"

#include "msg_cmdz.h"
#include "msg_dispatcher.h"

#include "Defined_train_path.h"

#include <time.h>
#include <cmath>
#include <fstream>

#include "vector_math.h"

struct telagram;
            class railhubz;
            class R_linez;
            class vector_math;
            class Defined_train_path;
class trainz : public  Base_TSym_entity
{

private:

    bool is_halt;
    double distance_toNext_from_last;
    double distance_traveld=0;
    bool arid_f = false;

Defined_train_path* trainz_currnet_path;

    sf::Vector2f current_location;
    sf::Vector2f next_hub_location;

    railhubz* Orign_Station;
    railhubz* Destination_station;


    int active_line;
    clock_t Orgin_clock;
    time_t current_t;

    sf::CircleShape cr_traingraphic;


public:
    railhubz* Next_hub_on_j;
    void train_inilaize(int& dispact_enity_id,  railhubz* hub_start,
                          railhubz* Hub_dest);

    int Train_id;
    double esclatcatator_priority;
    int speed;

    trainz(int& dispact_enity_id,  railhubz* hub_start,
       railhubz* Hub_dest): Base_TSym_entity(dispact_enity_id)
     {
         train_inilaize(dispact_enity_id,hub_start,Hub_dest);
     }


     ~trainz(){
        // delete[] trainz_currnet_path;
     };

    void hault();

    void move(int enter_line_id);

    bool  arived_final();

    void Path_Next_hub();

    void update();

    void update_location(time_t& currenttime);

    bool Handle_telagram(const telagram& tela);

    void draw(sf::RenderWindow &window);

    void load_data(double start_priory, int speezx, Defined_train_path* trainPath);


};


/*

sf::Vector2f* get_prt_location_train();

{    sf::Vector2f* prt_location;

    prt_location* = current_location;
    reutrn (prt_location);
}

//sf::Time lanchtime_orgin;
//sf::Time timesince_lastHub;


                    struct train_data{

                        bool is_inStation;

                        int distance_traveld_total;
                        int numberofCarts;

                            struct cargo{
                                int resorse1;
                                int resorse2;
                                int resorse3;

                                }cargo;
                        };
                        */

//grpahics
            //        enum cagrotype_colour
        //            { red_res1, magenta_res2, green_res3,
    //                };

//sf::VertexArray Triangle_train_engine();

    //std::stack<sf::RectangleShape*>  cargoz;

        /*    for (int i = 0; i <=cargo.numberofCarts; i++ )
                { cargoz.push(sf::RectangleShape* i = new sf::RectangleShape);
                    cargoz.top()-> setColour(Red);
                } */
