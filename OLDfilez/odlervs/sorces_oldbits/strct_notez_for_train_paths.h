


/*
line of site.
hurist functions
distance of vectors
x.y.
<strct_notez_for_train_paths.h>
*/

// instance for each hub

struct strc_m_node

{
    bool b_visited = false;
    float  Dis_to_next_so_far_H_val;
    float Dis_if_alter_Path_cost;

    float node_x;
    float mode_y;
    int node_id;

    vector<strc_m_node*> list_neighbours_connections;
    strc_m_node* No_parent_prt;
    strc_m_node(): parent (0){}
    strc_m_node(float x, float y, strc_m_node *Prt_parent = nullptr, int& total_nodez) :
                node_x(x), node_y(x), No_parent_prt(Prt_parent),node_id(total_nodez+1),
                Dis_to_next_so_far(0),Dis_if_alter_Path(0){total_nodez++;};

    float calculate_f()
     {
        return Dis_to_next_so_far_H_val+Dis_if_alter_Path_cost;
     }

    float Manhatten_distance (strc_m_node * end_node)
    {
            float x = (float)(fabs(this->node_x- end_node->node_x));
            float y = (float) (fabs(this->node_y- end_node->node_y));
            return (x+y);
    }
};

//checks if connected to line
void find_path (sf::Vector2f,sf::Vector2f, )

    void clear__open_list() { }
void clear_visited_list(){};
viod clear_path_to_destination() {};

bool
bool _node_found_desitination;









void find_Path_Aétoile()
{
    for (int i= 0; i< sizeof_hublist; i++)

    {
strc_m_node[i].b_visited = false;

strc_m_node[i].Dis_to_next_so_far = -1;
strc_m_node[i].Dis_if_alter_Path =-1;

node
    }

auto distancex_nodez = [](strc_m_node *a, strc_m_node* b)
{
    return sqrtf((a->x - b->x) * (a->x - b->x)+(a->y - b->y)*(a->y-b->y))
};

auto pathfinding_Heuristic_rulez = [distancex_nodez](strc_m_node *a, strc_m_node* b)
{

    return distancex_nodez(a,b);
};

    strc_m_node *prt_current_node = Curr_location_node;
    Curr_location_node->Dis_if_alter_Path = 0.0f;
    Curr_location_node->Dis_to_next_so_far = pathfinding_Heuristic_rulez(
                                        Curr_location_node,FinaL_destionation)

list<strc_m_node*> list_not_visited_nodez;
list_not_visited_nodez.push_back(Curr_location_node);

while(!list_not_visited_nodez.empty() && prt_current_node !=FinaL_destionation)

{
list_not_visited_nodez.front() )
{
    if(list_not_visited_nodez)



    }
}

//goes in hubs
strc_m_node *nodez_for_hubz = nullptr;




// goes into rail trains!

strc_m_node *Curr_location_node = nullptr;
strc_m_node  *FinaL_destionation = nullptr;


//goes in cmander
void create_hub_nodez()
{
nodez = new strc_m_node[sizeof_hublist];
for (int i 0; i< sizeof_hublist; i++)

{
    nodez[i].x=get_hubfloatx;
    nodez[i].y=get_hubfloaty;
    nodez[i].b_visited = false;
    nodez[i].No_parent_prt = nillptr;
        //nodez[i].
}
}
