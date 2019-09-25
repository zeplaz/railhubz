//msg_dispatcher.cpp
#include "msg_dispatcher.hpp"
#include "Base_TSym_entity.hpp"
#include "system_org.hpp"

Msg_Dispatcher* Msg_Dispatcher::instance()
  {
    static Msg_Dispatcher instance;
    return &instance;
  }


void Msg_Dispatcher::call_receiver_handle(Base_TSym_entity* receiver,
                                          const telagram& tela)
    {
      if(!receiver->Handle_telagram(tela))
      {
        std::cout << "##ERROR TELAGRAM FAILD TO BE HANDLED\n";
      }
    }

  void Msg_Dispatcher:: tranzmit(std::chrono::steady_clock::time_point trazmission_t,
                                int sender,
                                int receiver,
                                float priority,
                                msg_cmdz msg,
                                void* Other_data)
    {
      Base_TSym_entity* prt_reciver = sym_manger.get_rail_entity(receiver);

      if(prt_reciver == nullptr)
      {
        std::cout << "##ERROR TELAGRAM FAILD INVALIED POINTER ENTITY ETC \n";
      }
      else
      {
        telagram prep_tela(trazmission_t,sender,receiver,priority,msg,Other_data);
        if(trazmission_t<std::chrono::steady_clock::now())
        {
          std::cout <<"->DISPATCHING TELAGRAM NOW!"<<'\n';
          call_receiver_handle(prt_reciver,prep_tela);
        }
        else
        {
          std::cout <<"->DISPATCHING TELAGRAMsometimeafter::" <<'\n';
          dispatch_que.insert(prep_tela);
        }
      }
    }
