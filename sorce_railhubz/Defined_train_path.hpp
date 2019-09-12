#ifndef D_TR_PATH_H
#define D_TR_PATH_H

#include <stack>

//#include "railhubz.h"
template <class path_nodez>
class Defined_train_path

 {
  private :

    std::stack<path_nodez*> train_path_stk;

  public :
    Defined_train_path() = default;
    ~Defined_train_path() = default;

    path_nodez* get_next_hub()
    {
     if (!train_path_stk.empty())
     {
       path_nodez* temp_hub_prt = train_path_stk.top();
       train_path_stk.pop();
       printf("you arein getnexthub_definePath\n");
       return(temp_hub_prt);
      }
      else
      {
       printf("you arein else requet emptystack error\n");
       return nullptr;
      }
     }

    void addhubtoPath(path_nodez* newrailhub)
     {
     train_path_stk.push(newrailhub);
     }

    bool is_empty()
     {
      return (train_path_stk.empty());
     }
 };

#endif
