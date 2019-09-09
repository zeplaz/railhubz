

#include "railhubz.h"

//class trainz;
#include <stdio.h>
    railhubz::~railhubz(){printf("destructorcallrailzhubz\n");}

railhubz::railhubz(time_t& orgin, sf::Vector2f hub_vec, int& hubz_countz)
{
    id = hubz_countz;
       hubz_countz++;
    //totalhubs++;
    printf("id: trianhub %s %h \n", id, hubz_countz);

        H_creation_t = clock()-orgin;

        hub_location =hub_vec;


printf(" trianhub1\n" );
//graphics
    cr_hubgraphic.setRadius(20.f);
    cr_hubgraphic.setPosition(hub_location);
   cr_hubgraphic.setFillColor(sf::Color::Green);
printf(" trianhub2\n" );

}

    //sf::Vector2f railhubz::getLocation() const
    //{
//        return(hub_location);
//    }


/*    void railhubz::draw(sf::RenderWindow &window)
    {
         window.draw(cr_hubgraphic);
    }
    */
