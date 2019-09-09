//Cmd_agent_operator.h

#pragma once
//#include <algorithm>
#include <map>
#include <queue>

#include "Sym_Map.h"
#include "msg_dispatcher.h"

#include "AdjacencyMatrix.h"

#include "railhubz.h"

#include "Base_TSym_entity.h"
#include "R_linez.h"
#include "trainz.h"

#include <time.h>

enum hubNamez {Shebrooke,Toronto,Montreal,QubecCity,Ottowa};

class R_lines;
class trainz;
class railhubz;
//class Sym_Map;

class Cmd_agent_operator
 {

private:
    AdjacencyMatrix* routmatrix;

    time_t cmd_time_start;
    sid::vector<int> train_list;

    struct train_linepar{
        int train_id;
        int line_id;
        double priority;
        bool  operator < (const train_linepar &o) const
        {
            return Priority < o.Priority;
        }
    }priority_train_paket;

    std::priority_queue<train_linepar> trainpriorty_master_que;


public :

    int enity_count =0;
    //int train_count=0;
// int hubz_count =0;

    int number_of_dispatches=0;
    int numberofarrvails=0;

    Cmd_agent_operator(){cmd_time_start=clock();};

    ~Cmd_agent_operator();

                    AdjacencyMatrix* checkmatrix_forPrioty();

                    {
                        for(i++;i<)

                    }


    void dispatchtrain();

    int check_cleanup_train_enityz();

    railhubz* Drect_trains_next_rout();

    void scan_hubs_for_dispatch_cadiates();

    void create_trainz(int numtraincreat, int priorty, int speed,
                       int beinghub ,int endhub);

    void create_hubz(int location);

};
