glustuff.

#include <GL/glew.h>
#include <SFML/Window.hpp>

const GLint WIDTH =800*2, HEIGHT =600*2;

int main ()
{

sf::ContextSettings settings;


settings.depthBits =24;

setting.stencilBits =8;
settings.majorVersion =3;
setting.minorVersion = 3;
settings.attrbuteFlags = sf::ContextSettings::Core;

sf::Window window(sf::VideoMode(WIDTH,HEIGHT,32),
"Oglz, :tezt", sf::Style::Titlebar| sf::Style::Close, settings);


glewExperimental =GL_TRUE;

if (GLEW_OK!=gewInit())
{std::cout << "faild to inilzie gl" << std::endl;

return EXIT_FAILURE;
}

bool running = true;

while (running)
{
sf::Event windowEvent;

    while (window.pollEvent(window))
    {

          switch (windowEvent.type)
          { case sf::Event::Closed;
            running = close;
            break;
          }

    }
    glClearColor(0.1f,0.3f, 0.0f, 0.3f);

      glClear(GL_COLOR_BUFFER_BIT);

      //draw


//

window.display();



}

window.close();
return 0;

}
