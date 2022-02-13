

#include <cstddef>

template <typename ID_TYPE>
class ID
{
  protected: 
  inline static ID_TYPE NextValidID = 0;
  ID_TYPE val;

  public : 
  ID_TYPE operator()()
  {
    return val;
  }

  const ID_TYPE operator()() const 
  {
    return val;
  }

  ID()
  {
    //assert ((val>=be_NextValidID)&& "<Base_TSym_entity::set_id: broken ID>");
    val = NextValidID;
    NextValidID = val+1;

  }

  protected:
  inline static ID_TYPE get_next_id() { return NextValidID;}


};

typedef ID<size_t> E_ID; 
