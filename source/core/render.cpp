
#include "render.hpp"
#include "railhubz.hpp"
#include "Base_TSym_entity.hpp"


     void Rendering::render_entiez(sf::RenderWindow &window, system_org::Entity_map& rail_entity_map)
     {
       for ( auto it = rail_entity_map.begin(); it != rail_entity_map.end(); ++it )
         {
            it->second->draw(window);
         }
     }

     void Rendering::render_hubz(sf::RenderWindow &window, system_org::Hub_map& hubz_map)
     {
       for ( auto it = hubz_map.begin(); it != hubz_map.end(); ++it )
         {
            it->second->draw(window);
         }
     }










