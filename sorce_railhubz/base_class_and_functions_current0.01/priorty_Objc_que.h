
#ifndef PRQUEOBK_H
#define PRQUEOBK_H

#include <math.h>
#include <queue>

template<typename priorty_sestive_ojk>

inline  bool operator()( priorty_sestive_ojk* lhs,  priorty_sestive_ojk* rhs) 
 {
   return lhs->esclatcatator_priority < rhs->esclatcatator_priority;
 }


struct Priorty_for_station_que

{
 std::priority_queue<priorty_sestive_ojk*,std::vector<priorty_sestive_ojk*>,
                     Priorty_for_station_que> protyque_ojkz;
/*
Priorty_for_station_que()
: priorty_sestive_ojk.push(-1);
{};
Priorty_for_station_que(priorty_sestive_ojk objktoque) :
    priorty_sestive_ojk.push(objktoque);
    {}
    */
};


#endif
