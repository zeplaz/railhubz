

//main_test_nov_5am.cpp

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include <time.h>
#include "Sym_Map.h"
#include "Base_TSym_entity.h"
#include "trainz.h"
#include "R_linez.h"
#include "railhubz.h"

#include "msg_cmdz.h"
#include "msg_dispatcher.h"

#include "Cmd_agent_operator.h"

int main() {


    static int cycles;
 int enity_count=0;
 int count_train_hubz=0;

    printf("Welcome To Trainsym MainRun\n");

//    int stattrain_rounds;
//    int linesetupval;
count_train_hubz++;
time_t cmd_time_start = clock();

printf("srailhub 234 %s :\n", count_train_hubz);


    sf::RenderWindow window (sf::VideoMode(700,800), "Test_hub1");
    window.setFramerateLimit(60);
    //Cmd_agent_operator agent1;

    float x = 45.4042f;
    float y = 71.8923f;
/*
    railhubz sherbyz1(cmd_time_start,sf::Vector2f(x,y),count_train_hubz);

  railhubz* sherbyz = &sherbyz1 ;

//*sherbyz = railhubz(cmd_time_start,sf::Vector2f(x,y),hubz_count);

    printf("srailhub formationz:\n");

 sym_manger->Register_hubz(sherbyz);

    //   printf("sherbyz_ID: %s \n",sherbyz->id);

    x = 43.6532f;
    y = 79.3832f;
printf("srailhub 234 %s :\n", count_train_hubz);
  railhubz* tro = new railhubz(cmd_time_start,sf::Vector2f(x,y),count_train_hubz);
  sym_manger->Register_hubz(tro);

  count_train_hubz++;

//   railhubz tro1(cmd_time_start,sf::Vector2f(x,y),hubz_count);
    //railhubz* tro = &sherbyz1;
    printf("Toronto_ID: %s \n",tro->id);

     x = 45.5088f;
     y = 73.552f;


    railhubz* mtl = new railhubz(cmd_time_start,sf::Vector2f(x,y),count_train_hubz);
    sym_manger->Register_hubz(mtl);
    printf("Montreal_ID: %s \n",mtl->id);


    x = 46.8257f;
     y = 71.2349f;

    railhubz* Qcity = new railhubz(cmd_time_start,sf::Vector2f(x,y),count_train_hubz);
    sym_manger->Register_hubz(Qcity);
    printf("Qcity_ID: %s \n",Qcity->id);

     x = 75.69f;
     y = 45.421f;

    railhubz* otta = new railhubz(cmd_time_start,sf::Vector2f(x,y),count_train_hubz);
    sym_manger->Register_hubz(otta);
    printf("OttAWA_ID: %s \n",otta->id);

*/

R_linez*Sherb_mtl =  new R_linez(sherbyz, mtl, enity_count);
R_linez* mtl_ottaw = new R_linez(mtl, otta, enity_count);
R_linez* otaw_Toronto = new R_linez(tro, otta, enity_count);

sym_manger->Register_entity(Sherb_mtl);
sym_manger->Register_entity(mtl_ottaw);
sym_manger->Register_entity(otaw_Toronto);



    // MAIN LOOP:
    printf("entering simulationLoop\n");
    while (window.isOpen())
    {

        sf::Event prevent;
        cycles++;

        while (window.pollEvent(prevent))
        {
            {if (prevent.type ==sf::Event::Closed)
                        window.close();
                }

            {if (prevent.type == sf::Event::Resized)
                glViewport(0, 0, prevent.size.width, prevent.size.height);
            }
        }

        //get keypress for pause
        {
            printf("keypress rturn to input cmdz; \n");

        //    event::polling { keypres :returnkey,..}

        }



        //update loop

        while (window.pollEvent(prevent))
                {
                    {if (prevent.type ==sf::Event::Closed)
                                window.close();
                        }

                    {if (prevent.type == sf::Event::Resized)
                        glViewport(0, 0, prevent.size.width, prevent.size.height);
                    }
                }

        // drawupdate

        sym_manger->draw_hubz(window);
        printf("number of enties: %s \n" ,sym_manger->numberofentities());

        window.clear();
    }



return 0;

}
