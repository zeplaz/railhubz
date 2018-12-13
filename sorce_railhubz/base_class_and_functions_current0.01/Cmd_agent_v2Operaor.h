

#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>


#include <algorithm>
#include <map>
#include <queue>

#include "Sym_Map.h"
#include "Base_TSym_entity.h"
#include  "Defined_train_path.h"



#include "R_linez.h"
#include "enity_1test.h"
#include "enity_2test.h"


#include "msg_cmdz.h"
#include "msg_dispatcher.h"


#include <time.h>
#include <iostream>

class R_linez;
class Sym_Map;
class  enity_1test;
class  enity_2test;

class Cmd_agent_v2Operaor {

private :

time_t cmd_time_start;
std::vector<int> train_list;


struct train_linepar{
    int train_id;
    int line_id;
    double priority;
    bool  operator < (const train_linepar &o) const
    {
        return priority < o.priority;
    }
}priority_train_paket;

bool train_waiting = false;
bool is_hub_out_post= false;
 bool out_crt= false;

std::priority_queue<train_linepar> trainpriorty_master_que;



public :
     enum hubNamez {Shebrooke,Toronto,Montreal,QubecCity,Ottowa};

    int number_of_dispatches=0;
    int numberofarrvails=0;


    Cmd_agent_v2Operaor(){cmd_time_start=clock();}

    ~Cmd_agent_v2Operaor();

void dispatchtrain();

void scan_hubs_for_dispatch();

void check_cleanup_train_enityz_arrival();
};
