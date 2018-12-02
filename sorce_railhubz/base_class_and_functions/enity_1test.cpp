#include "enity_1test.h"
#include <iostream>

enity_1test::~enity_1test() {}


void enity_1test::initialize(time_t c_time,enity_2test* start, enity_2test* destiation )
{

    train_enity_cra= c_time;


     start_station=start;
      end_station=destiation;
    currentLocation = start_station->get_location();

    cr_traingraphic.setRadius(5.f);
    cr_traingraphic.setPosition(currentLocation);
    cr_traingraphic.setFillColor(sf::Color::Magenta);

}

void enity_1test::load_data(double priority, int spd, Defined_train_path* path_take)

{            // vector_math mathobj;

                esclatcatator_priority   =  priority;
                speed = spd;
                 trainrout =path_take;
                 next_station = trainrout->get_next_hub();
                 next_hub_location = next_station->get_location();
                 distance_toNext_from_last= sqrt(abs((currentLocation.x*next_hub_location.x) + (currentLocation.y*next_hub_location.y )));

                 }
void enity_1test::update()
{


    if(!arived)
    { //printf("train is in update not arived");
    time_t currenttime = clock();
    double movmentTime= currenttime - train_enity_cra;
    double vilocity_td =  (movmentTime/300)*speed/30;

    if (distance_traveld > distance_toNext_from_last)
    {    printf("train is in updatehublv1\n");

        if (trainrout->is_empty()==false)
    {       printf("train is in updatehublv2\n");
            next_station = trainrout->get_next_hub();
            next_hub_location = next_station->get_location();
            distance_toNext_from_last= sqrt(abs((currentLocation.x*next_hub_location.x) + (currentLocation.y*next_hub_location.y )));
    }
    }
        if (trainrout->is_empty())
            {printf("trainhasarived!id: %s \n ", this->get_id());
            arived = true;

            }


        sf::Vector2f  old_vec;
        double l=  (abs((currentLocation.x*next_hub_location.x) + (currentLocation.y*next_hub_location.y )));

        l = sqrt(l);


        sf::Vector2f  normilzec_vec;
        old_vec    = currentLocation;
//std::cout<< "info: l" <<movmentTime << "ohter:\n" <<vilocity ;

std::cout<< "distance next to last" << distance_toNext_from_last << std::endl;
std::cout<< "distance travled:" << l << std::endl;
std::cout<< "velocty travled:" << vilocity_td << std::endl;

        normilzec_vec = normalize_and_Drectional_vector(l,currentLocation,next_hub_location);

        currentLocation.x     =normilzec_vec.x*vilocity_td;
        currentLocation.y   =normilzec_vec.y*vilocity_td;

        std::cout << currentLocation.x << std::endl ;
        std::cout <<currentLocation.y<< std::endl ;

double temp_dist;
        temp_dist += sqrt(abs((currentLocation.x*old_vec.x) + (currentLocation.y*old_vec.y )));
         distance_traveld= temp_dist-sqrt(abs((currentLocation.x*old_vec.x) + (currentLocation.y*old_vec.y )));

        cr_traingraphic.setPosition(currentLocation);

        }



}

double  enity_1test::dot ( sf::Vector2f vec1,  sf::Vector2f vec2)
{printf("in dot %s\n",vec1.x*vec2.x + vec1.y*vec2.y) ;
return vec1.x*vec2.x + vec1.y*vec2.y;

};

void enity_1test::draw(sf::RenderWindow &window)
{
    window.draw(cr_traingraphic);
}

int enity_1test::get_id()

{

    return entity_1_id;
}


bool enity_1test::Handle_telagram(const telagram& tela)
{
return false;

}


sf::Vector2f enity_1test::normalize_and_Drectional_vector(double len,sf::Vector2f C_vec1,sf::Vector2f D_vec2){
    sf::Vector2f    temp_move_vec;
    double dx = D_vec2.x-C_vec1.x;
    double dy = D_vec2.y-C_vec1.y;

     dx /= len;
     dy /= len;
     temp_move_vec.x =abs(dx);
     temp_move_vec.y= abs(dy);
printf("innormalze\n");
return (temp_move_vec);

}
