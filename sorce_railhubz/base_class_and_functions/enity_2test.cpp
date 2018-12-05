


#include "enity_2test.h"
//


enity_2test::~enity_2test() {}


void enity_2test::initialize(time_t c_time, sf::Vector2f stloc)
{

    stationary_enity_t += c_time;
    Location = stloc;

    cr_hubgraphic.setRadius(20.f);
    cr_hubgraphic.setPosition(stloc);
    cr_hubgraphic.setFillColor(sf::Color::Green);
    Location= stloc;

}

 sf::Vector2f enity_2test::get_location()

 {

     return(Location);
 }
int enity_2test::get_id()
{
    return (entity_2_id);

}


void enity_2test::draw(sf::RenderWindow &window)
{
     window.draw(cr_hubgraphic);

}


bool enity_2test::Handle_telagram(const telagram& tela)
{
return false;

}

void enity_2test::update()
{
    printf("update enity2\n");
}

//ques accessors
/*
void add_to_pq(enity_1test* trian_e)
{
    trainQ->protyque_ojkz.push(trian_e);
}

void remove_from_pq()
{
    trainQ->protyque_ojkz.pop();
}

enity_1test* top_from_pq()
{ enity_1test* = tempenity1;
    tempenity1 = trainQ->protyque_ojkz.top()

    return tempenity1;
}
*/
