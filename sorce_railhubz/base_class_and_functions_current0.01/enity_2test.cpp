
#include "enity_2test.h"


enity_2test::~enity_2test() {}


void enity_2test::add_trainto_data_que(enity_1test* in_train_que)
{
    printf("adddatto que...\n");

        priorty_trainz_data.id_train = in_train_que->get_id();
        priorty_trainz_data.priority = in_train_que->get_train_priority();
        printf("adddatto que3...\n");
        train_quez.push(priorty_trainz_data);

        printf("adddatto que4...\n");
}


bool enity_2test::are_train_waiting()
{
    if (train_quez.empty())
    {return false;}
    else
    {return true;}
}


int enity_2test::return_highest_prioty_train_id()
{
    priorty_trainz_data_Stc temp_train_data;
    //printf(" highestprotty id_...\n");
    if (!train_quez.empty())
    {
      temp_train_data = train_quez.top();
    }

    return (temp_train_data.id_train);
}


void enity_2test::put_priotytrain_on_line()
{
    train_quez.pop();
    printf("trainhasLeftStation Nolonger in Que\n");
}


void enity_2test::initialize(time_t c_time, sf::Vector2f stloc)
{
    stationary_enity_t += c_time;
    Location = stloc;

    cr_hubgraphic.setRadius(20.f);
    cr_hubgraphic.setPosition(stloc);
    cr_hubgraphic.setFillColor(sf::Color::Green);
    Location= stloc;
}

 sf::Vector2f enity_2test::get_location()
 {
     return(Location);
 }


int enity_2test::get_id()
{
    return (entity_2_id);

}


void enity_2test::draw(sf::RenderWindow &window)
{
    window.draw(cr_hubgraphic);
}


bool enity_2test::Handle_telagram(const telagram& tela)
{
    return false;
}


void enity_2test::update()
{
    printf("update enity2\n");
}


void enity_2test::add_line_connection(R_linez* newline)
{
    printf("inaddlinefunction addline\n");
    line_connections.push_back(newline);
}

//bool enity_2test::operator()(const priorty_trainz_data_Stc* lhs, const priorty_trainz_data_Stc* rhs) const
//{  // priorty_trainz_data_Stc.p
    //int* id_train;
    //double* priority;

//    return lhs->priority < rhs->priority;
//}
/*

void enity_2test::add_train_toque(enity_1test* traintoQues)
{
    train_quez.push(traintoQues);
}
