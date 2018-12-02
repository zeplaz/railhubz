






void enity_2test::initialize(time_t* c_time, sf::Vector2f stloc)
{

    stationary_enity_t += *c_time;
    Location = stloc;

}

int enity_2test::get_id()
{
    return (entity_2_id);

}


void enity_2test::draw(sf::RenderWindow &window)
{


}

//ques accessors

void add_to_pq(enity_1test* trian_e)
{
    trainQ->protyque_ojkz.push(trian_e);
}

void remove_from_pq()
{
    trainQ->protyque_ojkz.pop();
}

enity_1test* top_from_pq()
{ enity_1test* = tempenity1;
    tempenity1 = trainQ->protyque_ojkz.top()

    return tempenity1;
}
