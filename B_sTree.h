
#include <stdio.h>
#include <stdlib.h>

struct B_psTree
{
    struct train_data
        {double cal_priority;
            int trian_id;
        };

    struct train_data train_data_1;

    struct B_psTree *lprt;
    struct B_psTree *rprt;

};

typedef struct B_psTree node;

node *createtree(node *root);
node *insert(train_data , double _pr, node *root);
node *delet(int T_id)

int Highest_priorty( node* root )
{
    if ( root == null )
        return -1;

    int left = Highest_priorty(root->left);
    int right = Highest_priorty ( root->right);
    if( root->train_data_1.cal_priority > left && root->train_data_1.cal_priority > right )
       return train_data_1;
    else
       return max ( left, right );
}





public void findMax(Node root) {
            if (root == null)
                System.out.println("empty tree");
            else {
                Queue<Node> queue = new LinkedList<Node>();  //make a queue
                Node max = root;                              //suppose max is root
                queue.add(root);                              //add root to queue
                while (queue.size() != 0) {                  //while size of queue is not empty
                    Node temp = queue.remove();              //remove an item from queue
                    if (temp.getElement() > max.getElement())    //if removed item is greater than max
                        max = temp;                             //set new max
                    if (temp.getLeft() != null)
                        queue.add(temp.getLeft());             //traverse left
                    if (temp.getRight() != null)
                        queue.add(temp.getRight());            //traverse right
                }
                System.out.println(max.getElement());       //in the end ,print the max
            }
        }
