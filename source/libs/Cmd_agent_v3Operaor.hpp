
#pragma once


#include <queue>
#include <tuple>
//#include "system_org.hpp"
//#include "rail_trainz.hpp"

  class trainz;
  class R_linez; 

  typedef std::tuple<trainz*,R_linez*,float> train_on_line_priory_tuple;

  bool  train_tuple_comparor(train_on_line_priory_tuple lhs, train_on_line_priory_tuple rhs);

 


 class Cmd_agent_operator
  {
    friend class Sym_Map;
    
    using P_que_trainz = std::priority_queue<train_on_line_priory_tuple,std::vector<train_on_line_priory_tuple>,decltype(&train_tuple_comparor)>;

    private:

      P_que_trainz trainLine_que{train_tuple_comparor};
    public :

      int enity_count = 0;
      int train_count = 0;
      int hubz_count  = 0;

      int number_of_dispatches = 0;
      int numberofarrvails = 0;

      void scan_hubs_for_dispatch_cadiates();
      void dispatchtrain();

};



  bool operator<(const train_on_line_priory_tuple& tt1, const train_on_line_priory_tuple& tt2);


  bool operator>(const train_on_line_priory_tuple& tt1, const train_on_line_priory_tuple& tt2);

  
 
 /* auto tup_cmp =[](train_tuple lhs, train_tuple rhs)
  {
    return std::get<2>(lhs) < std::get<2>(rhs);
  };*/