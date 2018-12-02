//Cmd_agent_operator.h

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

#include "railhubz.h"
#include "R_linez.h"
#include "trainz.h"



#include "msg_cmdz.h"
#include "msg_dispatcher.h"


#include <time.h>


class R_lines;
class trainz;
class railhubz;
class Sym_Map;

class Cmd_agent_operator
 {

private:


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


    std::priority_queue<train_linepar> trainpriorty_master_que;


public :

    int enity_count =0;
    int train_count=0;
  int hubz_count =0;

    int number_of_dispatches=0;
    int numberofarrvails=0;

    Cmd_agent_operator(){cmd_time_start=clock();}

    ~Cmd_agent_operator();

    void dispatchtrain();


    int check_cleanup_train_enityz();

    //railhubz* Drect_trains_next_rout();

    void scan_hubs_for_dispatch_cadiates();

    void create_trainz();

    void create_hubz(int location);

    void create_paths();

    void load_train_data();
};
