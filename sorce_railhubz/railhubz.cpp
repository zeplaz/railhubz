

#include "railhubz.h"

class trainz;




struct Priorty_for_station_que
{
 bool operator()( trainz* lhs,  trainz* rhs) const
 {
   return lhs->esclatcatator_priority < rhs->esclatcatator_priority;
 }
};

std::priority_queue<trainz*,std::vector<trainz*>,
                    Priorty_for_station_que> Trainprotyque;


    railhubz::~railhubz(){printf("destructorcallrailzhubz\n");}

railhubz::railhubz(time_t& orgin, sf::Vector2f hub_l, int& hubz_countz)
{


    id = hubz_countz;
       hubz_countz++;
    //totalhubs++;
    printf("id: trianhub %s %h \n", id, hubz_countz);

        H_creation_t = clock()-orgin;
        hub_location = hub_l;
printf(" trianhub1\n" );
//graphics
    cr_hubgraphic.setRadius(20.f);
    cr_hubgraphic.setPosition(hub_location);
    cr_hubgraphic.setFillColor(sf::Color::Green);
printf(" trianhub2\n" );

}

    sf::Vector2f railhubz::getLocation() const
    {
        return(hub_location);
    }



    void railhubz::add_train_toque(trainz* traintoQues)
    {
        Trainprotyque.push(traintoQues);
    }

    void railhubz::add_line_connection(R_linez* newline)
    {
        line_connections->push_back(newline);
        //update astar
    //line_connections
    }

    int railhubz::return_highest_prioty_train_id()
    {
        return ( Trainprotyque.top()->Train_id);
    }

    void railhubz::put_priotytrain_on_line()
    {
        Trainprotyque.pop();

        printf("trainhasLeftStation Nolonger in Que\n");
    }


    void railhubz::draw(sf::RenderWindow &window)
    {
         window.draw(cr_hubgraphic);
    }
