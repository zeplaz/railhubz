
#pragma once

#include <queue>
#include <tuple>
#include "system_org.hpp"
#include "railhubz.hpp"
#include "rail_trainz.hpp"


   /*
  bool operator<(const train_tuple& tt1, const train_tuple& tt2)
  {
    return std::get<2>(tt1)<std::get<2>(tt2);
  }

  bool operator>(const train_tuple& tt1, const train_tuple& tt2)
  {
    return std::get<2>(tt1)>std::get<2>(tt2);
  }
  */
  typedef std::tuple<trainz*,R_linez*,float> train_tuple;
  auto tup_cmp =[](train_tuple lhs, train_tuple rhs)
  {
    return std::get<2>(lhs) < std::get<2>(rhs);
  };


 class Cmd_agent_operator
  {
    friend class Sym_Map;
    
    using P_que_trainz = std::priority_queue<train_tuple,std::vector<train_tuple>,decltype(tup_cmp)>;

    private:

      P_que_trainz trainLine_que{tup_cmp};
    public :

      int enity_count = 0;
      int train_count = 0;
      int hubz_count  = 0;

      int number_of_dispatches = 0;
      int numberofarrvails = 0;

      void scan_hubs_for_dispatch_cadiates();
      void dispatchtrain();

};
