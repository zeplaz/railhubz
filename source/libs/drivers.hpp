
#pragma once

#include "system_org.hpp"
#include "Cmd_agent_v3Operaor.hpp"
#include <cstddef>
#include <unordered_map>
#include <vector>





namespace driver
{
    static Cmd_agent_operator m_cmd_agent_op;


    class Parse_Map : public std::unordered_map<P_Key,parse_packet>
    {
       public :
       Parse_Map();
       parser::xml_parser xml_parser;
       String_Vec* get_hub_data_at(size_t i);

    };

    //BREAK THIS FUNCTION UP OMG
    void initializer();

     void factory_setup();
     Parse_Map run_parseing();
     void init_hubz(const Parse_Map* pm);
     void init_R_linez(const Parse_Map* pm);

     void path_setup(const Parse_Map* pm);

     void drive_loop();
}
 // typedef std::unordered_map<std::string,std::string> Parse_Map;
