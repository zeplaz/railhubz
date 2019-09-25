
#include "drivers.hpp"

#include <SFML/OpenGL.hpp>


int main(int argc, char** argv)
  {
    //create window and framez

    sf::RenderWindow p_window (sf::VideoMode(700,800), "Test_hub1");
    p_window.setFramerateLimit(60);

    //run inilizations!
    driver::initializer();

//open main window
    while (p_window.isOpen())
    {
      sf::Event prim_evt;

      //poll eventz
      while (p_window.pollEvent(prim_evt))
      {
        if (prim_evt.type ==sf::Event::Closed)
                    p_window.close();

        if (prim_evt.type == sf::Event::Resized)
        glViewport(0, 0, prim_evt.size.width, prim_evt.size.height);
      }//endpolling

      //rendring
      p_window.clear();
      //move to a thread!
      sym_manger.render_entiez(p_window); //not hubz only raillinz and trainz...
      sym_manger.render_hubz(p_window);
      p_window.display();

    }//end mainwindowloop

   return 0;
  }
