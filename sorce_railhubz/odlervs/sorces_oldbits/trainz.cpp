//Trainz.cpp

#include "trainz.h"

class Defined_train_path;
Defined_train_path trainz_currnet_path;


void trainz::train_inilaize(int& dispact_enity_id,  railhubz* hub_start,
   railhubz* Hub_dest)
        {
        Train_id =  dispact_enity_id+1;
        dispact_enity_id++;
                Orgin_clock = clock();
                Orign_Station = hub_start;
                Destination_station = Hub_dest;
                current_location = Orign_Station->getLocation();

                Next_hub_on_j = trainz_currnet_path.get_next_hub();
        distance_toNext_from_last =
                       sqrt(vector_math::dot(current_location,next_hub_location));


        //settime and other info
        printf("new train added:ID %s active line %t \n", Train_id, active_line);

        //graphicsz

        cr_traingraphic.setPosition(current_location);
        cr_traingraphic.setRadius(20.f);
        cr_traingraphic.setFillColor(sf::Color::Magenta);
}

    bool trainz::Handle_telagram (const telagram& tela)
    {
                if (tela.msg == halt_cmd)
                    { printf("train has been given Hult_tela_fromLINE!mustbe trubz\n");
                    return (true);
                    }

                if(tela.msg == move_cmd)
                    {
                     printf("trainWillMove_on_locationUpdate!\n");
                    return (true);
                    }
     return false;
    }

    void trainz::update()
    {       time_t currenttime = clock();
                //check_status();
            update_location(currenttime);

            if (distance_toNext_from_last < distance_traveld )
            {
                        hault();

                if (Destination_station->id ==Next_hub_on_j->id)
                {
                    arid_f = true;
                }
            }

            //loop up new next station;

            else {
                    Path_Next_hub();
                 }

            }


    void trainz::update_location(time_t& currenttime)
    {
        if (is_halt = false)
        {
            double movmentTime= currenttime - Orgin_clock;
            double vilocity =  movmentTime*speed/3;

            float l = sqrt(vector_math::dot(current_location,next_hub_location));
            sf::Vector2f  old_vec;
            old_vec    = current_location;

            current_location = normalize_and_Drectional_vector(l,current_location,next_hub_location);

            current_location.x    = current_location.x*vilocity;
            current_location.y    = current_location.x*vilocity;

            distance_traveld +=  sqrt(vector_math::dot(current_location,old_vec));

            cr_traingraphic.setPosition(current_location);

        }

        else { if (arived_final())
                {  printf("arived and remove?\n") ;}
            }

        }

    void    trainz::load_data(double start_priory, int speezx, Defined_train_path& trainPath )

            {
                esclatcatator_priority=start_priory;
                speed=speezx ;
                trainz_currnet_path  = trainPath;
            }


    void trainz::Path_Next_hub()

    {   Next_hub_on_j =  trainz_currnet_path.get_next_hub();

        next_hub_location = Next_hub_on_j->getLocation();

        distance_toNext_from_last= sqrt(vector_math::dot(current_location,next_hub_location));
    }



    void trainz::hault()
    {
        is_halt = true;

        sf::Vector2f temp_next_location= Next_hub_on_j->getLocation();
        double dre_dxr= vector_math::Drectional_dxr(distance_toNext_from_last,
                current_location,temp_next_location );

        telagram  cmd_telaexit(0,this->Train_id, active_line,
                       -1.f, exit_line,dre_dxr);
                       this->Handle_telagram(cmd_telaexit);

                       active_line =-1;
    }

    bool trainz::arived_final()

    {
        if (arid_f = true)
        {printf(" a train: %s has arvied final destaion %r \n",  Train_id, Destination_station->id);
            return true;}
    }

    void trainz::move(int enter_line_id)
    {
        is_halt = false;
        current_t= clock();
         active_line = enter_line_id;

        double dre_dxr= vector_math::Drectional_dxr(distance_toNext_from_last,
                current_location, Next_hub_on_j->getLocation());

                telagram  cmd_telmove(current_t, this->Train_id, enter_line_id,
                                      -1.f, enter_line, dre_dxr);

     this->Handle_telagram(cmd_telmove);

    }


void trainz::draw(sf::RenderWindow &window)
            {
                window.draw(cr_traingraphic);
              }
