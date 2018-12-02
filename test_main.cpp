
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>

#include <time.h>

#include "Sym_Map.h"
#include "Base_Tsym_entity.h"

#include "trainz.h"
#include "R_linez.h"
#include "railhubz.h"

#include "msg_cmdz.h"
#include "msg_dispatcher.h"


int main ()

{




int total_trainz=0;
int total_hubz =0;
int total_linez=0;

clock_t start_prog_t =clock();
time_t currnttime = start_prog_t;

sf::RenderWindow window (sf::VideoMode(window_Width,window_Hight), "Test_hub1");
window.setFramerateLimit(60);


sf::Vector2f sampevec(700.f, 100.f);
sf::Vector2f sampevec2(200.f, 100.f);
sf::Vector2f sampevec3(200.f, 600.f);


railhubz Toronto(currnttime,sampevec3,total_hubz);
railhubz mtl(currnttime,sampevec,total_hubz);
railhubz otw(currnttime,sampevec2,total_hubz);
                                //railhubz mtl(currnttime, ,total_hubz );
                            //printf("hubsmade id: %r\n",total_hubz );
                            //printf("hubsmade id: %s \n",total_hubz );

R_linez* mtl_ottaw = new R_linez(mtl, otw, total_linez);
R_linez* otaw_Toronto = new R_linez(Toronto, otw, total_linez);

                    //R_linez otaw_Toronto(Toronto, otw, total_linez);
sym_manger->Register_entity(mtl_ottaw);
sym_manger->Register_entity(otaw_Toronto);



    while (window.isOpen())
    { sf::Event prevent;


//update
for (int i =0, total_trainz, i++)
        {

        }
for (int i=0, total_linez,  i++)
        {

        }
//

    while (window.pollEvent(prevent))
            {
                {if (prevent.type ==sf::Event::Closed)
                            window.close();
                    }

                {if (prevent.type == sf::Event::Resized)
                    glViewport(0, 0, prevent.size.width, prevent.size.height);
                }
            }

// draw
            //window.draw();
        //  window.draw();
        //sf::VertexArray rail_linez_array(sf::LinesStrip, 4);



        window.clear();
                otw.draw(window);
                mtl.draw(window);
                mtl_ottaw.draw(window);
                otaw_Toronto.draw(window);
                Toronto.draw(window);
            //    window.draw(rail_linez_array);
                window.display();

    }


    return 0;
}
