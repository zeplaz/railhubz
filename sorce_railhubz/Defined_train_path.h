#ifndef D_TR_PATH_H
#define D_TR_PATH_H

#include <stack>

#include "railhubz.h"

class Defined_train_path

 {
  private :

    std::stack<railhubz*> train_path_stk;

  public :
    Defined_train_path() = default;
    ~Defined_train_path() = default;

    railhubz* get_next_hub();

    void addhubtoPath(railhubz* newrailhub);
    bool is_empty();
 };

#endif
