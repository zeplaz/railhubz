#ifndef D_TR_PATH_H
#define D_TR_PATH_H

#include <stack>
#include <cstdio>


template <class path_nodez>
class Defined_train_path

 {
  private :

    std::stack<path_nodez> train_path_stk;

  public :
  //  Defined_train_path() = default;
  //  ~Defined_train_path() = default;
     path_nodez peak_top()
    {
      if (!train_path_stk.empty())
      {  path_nodez temp_hub_prt = train_path_stk.top();
        return temp_hub_prt;
      }
      else
      {printf("stack is empty\n"); return nullptr;}
    }
    path_nodez process_next_node()
    {
      if (!train_path_stk.empty())
      {
       path_nodez temp_hub_prt = train_path_stk.top();
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
