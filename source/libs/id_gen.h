

#include <cstddef>

template <typename ID_TYPE>
class ID
{
  inline static ID_TYPE NextValidID = 0;
  ID_TYPE val;

  ID_TYPE operator()()
  {
    return val;
  }

  inline static ID_TYPE get_next_id() { return NextValidID;}

  ID()
  {
    //assert ((val>=be_NextValidID)&& "<Base_TSym_entity::set_id: broken ID>");
    val = NextValidID;
    NextValidID = val+1;

  }
};

typedef ID<size_t> E_ID; 
