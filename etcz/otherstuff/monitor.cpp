

    template <class F>

    struct FunctionType;

    template <class R, class Object, class... Args>
    struct FunctionType<R (Object::*)(Args...)>
    {
      typedef R return_type;
    };

    template <class R, class Object, class... Args>
    struct FunctionType<R (Object::*)(Args...) const>
    {
      typedef R return_type;
    };


    template <class Object_>



class Monitor {
public:
   typedef Object_ object_type;
   template <class F, class... Args >
   typename FunctionType<F>::return_type operation(const F& f, Args... args)
   {
       critical_section cs;
       return (object.*f)(args...);
   }
   template <class F, class... Args >
   typename FunctionType<F>::return_type operation(const F& f, Args... args) const
   {
       critical_section cs;
       return (object.*f)(args...);
   }
private:
  object_type object;
  class critical_section {};
};
