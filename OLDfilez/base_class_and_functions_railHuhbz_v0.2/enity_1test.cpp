#include "enity_1test.h"


enity_1test::~enity_1test() {}

Defined_train_path trainrout;

void enity_1test::initialize(time_t c_time,enity_2test* start, enity_2test* destiation )
{

    train_enity_cra= c_time;

     start_station= start;
     end_station= destiation;
     currentLocation = start->get_location();
        start_station->add_trainto_data_que(this);
    cr_traingraphic.setRadius(5.f);
    cr_traingraphic.setPosition(currentLocation);
    cr_traingraphic.setFillColor(sf::Color::Magenta);

}

double enity_1test::get_train_priority() const
{
        return esclatcatator_priority;
}


void enity_1test::load_data(double priority, float spd, Defined_train_path* path_take)

{            // vector_math mathobj;

                esclatcatator_priority   =  priority;
                speed = spd;
                //    Defined_train_path* trainrout = new Defined_train_path;
                    trainrout = *path_take;
                 next_station = trainrout.get_next_hub();
                 next_hub_location = next_station->get_location();
                //  train_x = next_hub_location.x;
                 // train_y =next_hub_location.y;
                 cr_traingraphic.setPosition(currentLocation);
    distance_toNext_from_last= sqrt(abs((currentLocation.x*next_hub_location.x) + (currentLocation.y*next_hub_location.y )));
  printf("intializationload data %s locaioanl drection: %f %r \n",distance_toNext_from_last ,next_hub_location.y ,next_hub_location.y);

                   }


                 void enity_1test::draw(sf::RenderWindow &window)
                 {
                     window.draw(cr_traingraphic);
                 }

                 int enity_1test::get_id()
                 {
                     return entity_1_id;
                 }

    void enity_1test::update()
    {
        esclatcatator_priority+ clock();

        if (arived_f== false)
        { //printf("train is in update not arived");
            time_t currenttime = clock();

            double movmentTime= currenttime - train_enity_cra;
            double vilocity_td =  (movmentTime/300)*speed/20;
            //train_enity_cra =  clock();
            //train_enity_cra= movmentTime;
            if(is_halt == true)
            {
              cr_traingraphic.setFillColor(sf::Color::Blue);}

            if (is_halt== false)
            {
                if (distance_traveld > distance_toNext_from_last)
                    {
                        printf("train is in updatehublv1\n");
                        distance_traveld = 0.f;
                        hault();

                    }

                sf::Vector2f  old_vec;
                                                //double l = sqrt(abs((currentLocation.x*next_hub_location.x) + (currentLocation.y*next_hub_location.y )));
                sf::Vector2f  normilzec_vec;
                old_vec    = currentLocation;
                //std::cout<< "info: l" <<movmentTime << "ohter:\n" <<vilocity ;
                //std::cout<< "train id::" << entity_1_id << std::endl;
                //std::cout<< "distance next to last" << distance_toNext_from_last << std::endl;
                //std::cout<< "distance l:" << l << std::endl;
                //std::cout<< "distance traveled:" << distance_traveld << std::endl;
                //std::cout<< "velocty travled:" << vilocity_td << std::endl;

                normilzec_vec = normalize_and_Drectional_vector(distance_toNext_from_last,currentLocation,next_hub_location.x,next_hub_location.y);

                currentLocation.x   = normilzec_vec.x*vilocity_td;
                currentLocation.y   = normilzec_vec.y*vilocity_td;

            //    std::cout << currentLocation.x << std::endl ;
            //    std::cout <<currentLocation.y<< std::endl ;

                double temp_dist;
                temp_dist = sqrt(abs(currentLocation.x*old_vec.x) + abs(currentLocation.y*old_vec.y ));
                // distance_traveld= temp_dist+ sqrt(abs(currentLocation.x*old_vec.x) - abs(currentLocation.y*old_vec.y ));
                distance_traveld =abs(distance_toNext_from_last-temp_dist);
                cr_traingraphic.setPosition(currentLocation);

            }
            }



        }


    void enity_1test::hault()

    {
        if (arived_f== false)
            {

            if (trainrout.is_empty()==true)
             {
                printf("trainhasarived!id:  \n ");
                arived_f = true;
                cr_traingraphic.setFillColor(sf::Color::Red);
                //delete[] trainrout;
             }

             if (trainrout.is_empty()==false)
             {
                    printf("train is in updatehublv2\n");
                    // currnet_station_id =next_station->get_id();
                if (arived_f ==false)
                {
                    next_station->add_trainto_data_que(this);
                    next_station = trainrout.get_next_hub();
                    printf("train is in updatehublv3 reutn from rout.\n");
                    next_hub_location = next_station->get_location();

                    printf("train is in updatehublv4 reutn from nextlocationget.\n");
                        printf("train locational data x2 %k x1 %v .\n",currentLocation.x ,next_hub_location.x);

                    distance_toNext_from_last= sqrt(abs(currentLocation.x*next_hub_location.x)
                                                + abs(currentLocation.y*next_hub_location.y));

                     dre_dxr=  Drectional_dxr(distance_toNext_from_last,
                                                    currentLocation,next_hub_location );

                    int tempt_id = (int)active_line;
                    std::cout << "line active ID:" << active_line;
                //    tranzmitor->trazmit_telagram(0.f,entity_1_id,tempt_id,
            //                                    -1.f,exit_line,dre_dxr);

                    active_line =-1;

                    printf("train is in updatehublv5 reutn from nextlocationget.\n");

                    //Next_hub_on_j = trainz_currnet_path->get_next_hub();
                        //  sf::Vector2f temp_next_location= Next_hub_on_j->getLocation();
            }
            }
                is_halt = true;

                }


}

  void enity_1test::move(int ent_line_id)

  {
       printf("in train entity given moveorder2\n");
          is_halt = false;
          train_enity_cra= clock();
           printf("in train entity given moveorder2\n");
           active_line = ent_line_id;
           cr_traingraphic.setFillColor(sf::Color::Magenta);
           printf("in train entity given moveorder3\n");


           double line_blocker;
           line_blocker = (currentLocation.x* next_hub_location.x*next_hub_location.y*currentLocation.x);
           std::cout << "info drivite?: disnex-last: " << distance_toNext_from_last << std::endl;

        //  tranzmitor->trazmit_telagram(0.f, entity_1_id, ent_line_id,
                //                 0.f,enter_line, line_blocker);
/*

          double dre_dxr= Drectional_dxr(distance_toNext_from_last,
                  currentLocation, next_hub_location);


                 // telagram  cmd_telmove(0, this->get_id(), ent_line_id,
                //                        -1,enter_line, dre_dxr);
        printf("train is msged to move telling line: %s \n",ent_line_id );




                             */

  }



bool enity_1test::Handle_telagram(const telagram& tela)
{
    if (tela.msg == halt_cmd)
                   { printf("train has been given Hult_tela_fromLINE!mustbe trubz\n");
                   is_halt = true;
                   return (true);
                   }

               if(tela.msg == move_cmd)
                   {
                    printf("trainWillMove_on_locationUpdate!\n");
                    active_line = tela.Other_data;
                   return (true);
                   }


return false;

}



/*
bool enity_1test::in_station()
{
    if (arived_f == false && is_halt ==true)


    return true;
    else
    return false;

}

*/
double  enity_1test::dot ( sf::Vector2f vec1,  sf::Vector2f vec2)
{printf("in dot %s\n",vec1.x*vec2.x + vec1.y*vec2.y) ;
return vec1.x*vec2.x + vec1.y*vec2.y;

}



    sf::Vector2f enity_1test::normalize_and_Drectional_vector(double len,sf::Vector2f C_vec1, double x2, double y2)
{
    double x1;
    double y1;
    sf::Vector2f    temp_move_vec;

    x1=  (double)C_vec1.x;
    y1 =(double)C_vec1.y;

    double dx = abs(x2-x1);
    double dy = abs(y2-y1);
//std::cout << "normalz info:" << dy <<" dx" << dx <<std::endl;
     dx /= len;
     dy /= len;
    // std::cout << "normalz post deived:" << dy <<" dx" << dx <<std::endl;

     temp_move_vec.x =(float) dx;
     temp_move_vec.y= (float) dy;
//printf("innormalze dy %s otherx %r \n",dy ,temp_move_vec.x );
return (temp_move_vec);

}


double enity_1test::Drectional_dxr(double L,sf::Vector2f C_vec1,sf::Vector2f D_vec2)
   {    printf("in drx\n ");
       double S;
       double mx = D_vec2.x-C_vec1.x;
       double my = D_vec2.x-C_vec1.x;
      std::cout << "mx: " << mx << "my" << my << std::endl;

      if (mx==my)
      {
            printf("prereutn mx==my");
            return ((mx*L)*(my*L));
      }

        if (mx!= my)
        {
            S = (mx)/(my);
            printf("in drx3");
           return (S*(mx/L)+(mx/L)/S);
       }


   }
