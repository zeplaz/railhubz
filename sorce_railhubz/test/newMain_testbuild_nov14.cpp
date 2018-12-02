


#include <fstream>   // for std::ifstream
#include <iostream>  // for std::cout
#include <sstream>   // for std::istringstream


main {

static int cycles;

    printf("Welcome To Trainsym MainRun\n");

  Cmd_agent_operator* agent1;
    printf( "you have created an agent:\n \n");



printf("defultsettup input -1, will create 5 stations; \n
        shrbyz, tro,mtl,Qcity,otta are ennumed \n
        else the int you enter is the rounds of new hubz\n
        wise you will be asked to enter ax and y point to place sation and given an ID.\n");



load_startup();
  {
      int stattrain_rounds;
      int linesetupval;

      printf("enter number of stations or -1 for defult:\n");
      std::cin >> stattrain_rounds;

      if (stattrain_rounds ==-1 )
     {
         agent1->create_hubz(0);
         agent1->create_hubz(1);
         agent1->create_hubz(2);
         agent1->create_hubz(3);
         agent1->create_hubz(4);


     for ( i=0; i< stattrain_rounds ;i++)

       {agent1->create_hubz(i+5);}

    }

    printf("intialhubconstruction compleate. adding lines...\n");

    printf("enter -1 for defult setup shrbyz_mtl,
            mtl_qcity,toront_ottaw,mtl_ottaw:\n
            otherwise enter hub idz,..ish");

            std::cin >> linesetupval;
    if ( ==-1)
        {
            agent1->create_R_line(0,2);
            agent1->setup_linez(2,3);
            agent1->create_R_line(1,4);
            agent1->create_R_line(2,4);
        }
        
    printf("linesetup compleate,constructing intialroutmarix..\n");

    agent1->setup_routmatrix();
    printf("matrixworkdone\n");

    }
    printf("inlizationloaddata_compleate!");


  sf::RenderWindow window (sf::VideoMode(window_Width,window_Hight), "Test_hub1");
  window.setFramerateLimit(60);


// MAIN LOOP:
printf("entering simulationLoop\n")
while (window.isOpen())
{
    report();
    {printf("DATAoutput: %d \n
                        Hubzcount: %f traincount: %h\n
                        totalTrains(mapize:); %t\n",

                             cycles,
                             agent1->hubz_count,agent1->train_count,
                             agent1->train_list.size());


    }


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

            event::polling { keypres :returnkey,..}

        }

        agent1->scan_hubs_for_dispatch();
        agent1->check_cleanup_train_enityz_arrival();

    //update loop



    // drawupdate
        sym_manger->Draw_maped_hubz(window);
        sym_manger->Draw_maped_enties(window);
        printf("number of enties: %s \n" ,sym_manger->numberofentities());

    }




//while window open.

  {



      // sysem_loop

      // event polling loop

    //update_loop

    //draw_update_loop



  }


}
