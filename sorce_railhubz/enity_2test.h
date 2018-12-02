

#include "msg_cmdz.h"
#include "msg_dispatcher.h"
#include "vector_math.h"
#include "priorty_Objc_que.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <time.h>

struct Priorty_for_station_que;
struct telagram;
class enity_1test;

class enity_2test: public Base_TSym_entity
{
protected :

    sf::Vector2f Location;
    int entity_2_id;
    time_t stationary_enity_t;

    Priorty_for_station_que* trainQ;



    public :
        virtual void update();
        virtual  bool Handle_telagram(const telagram& tela);


        int get_id();
        void initialize(time_t* c_time, sf::Vector2f stloc);
        void draw(sf::RenderWindow &window);


        void add_to_pq();
        void remove_from_pq();
        enity_1test* top_from_pq();


~enity_2test();{}

    enity_2test (time_t* cur_time,int& total_enty, sf::Vector2f locvec): Base_TSym_entity(total_enty)
        {
            entity_2_id = total_enty;
            initialize (cur_time,locvec);
            total_enty++;
        }
};
