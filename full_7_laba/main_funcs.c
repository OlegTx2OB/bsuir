#include "main_funcs.h"

void new(node** root, int number, short* nodes_count)
{
    if((*nodes_count) == 0)create_root(root, number, nodes_count);
    else add_node(*root, number, nodes_count);
}
void print(node* root)
{
    if (root != NULL) //потом проверь, мб нулл убрать нужно
    {
        printf("\t%d\n", root->number);
        print(root->l);
        print(root->r);
    }
}
node* search(node* root, int number)
{
    if(root != NULL)
    {
        if (root->number == number)return root;
        else if (number > root->number) search(root->r, number);
        else if (number < root->number) search(root->l, number);
    }
    else return NULL;
}
void delete(node **root, int number, short* nodes_count)
{
//0 count of nodes
    if(nodes_count == 0) printf("Nodes count is 0");
    else
    {
        node* deleted_node = search(*root, number);
//node not founded
        if(deleted_node == NULL) printf("Node NOT founded\n");
        else
        {
//no children
            if ((deleted_node->l == NULL) && (deleted_node->r == NULL))
            {
                if(deleted_node->p == NULL)
                {
                    free(*root);
                    (*root) = NULL;
                }
                else
                {
                    node* parent = deleted_node->p;
                    if(deleted_node->number > parent->number) parent->r = NULL;
                    else parent->l = NULL;
                    free(deleted_node);
                }
                (*nodes_count)--;
            }
//l child
            else if ((deleted_node->l != NULL) && (deleted_node->r == NULL))
            {
                node* parent = deleted_node->p;
                node* child = deleted_node->l;
                delete_node_with_one_child(root, parent, child, deleted_node);
                (*nodes_count)--;
            }
//r child
            else if ((deleted_node->l == NULL) && (deleted_node->r != NULL))
            {
                node* parent = deleted_node->p;
                node* child = deleted_node->r;
                delete_node_with_one_child(root, parent, child, deleted_node);
                (*nodes_count)--;
            }
//two children
            else if ((deleted_node->l != NULL) && (deleted_node->r != NULL))
            {
                node* parent = node_for_replacement(deleted_node);
                deleted_node->number = parent->number;
                if (parent -> r == NULL) parent->p->l = NULL;
                else parent->p->l = parent->r;
                free(parent);
                (*nodes_count)--;
            }
        }
    }
}
void transformation(node **root, node** new_root, int interval, int min_min, int after_right)
{
    if(interval != 0)
    {
        for (int i = 0; i < (interval + 1) / 2; i++)
        {
            int min_curr = UPPER_BOUND + 1;
            min_min = recursive_min_search(*root, &min_curr, min_min, after_right);
        }
        static short new_nodes_count = 0;
        new(new_root, min_min, &new_nodes_count);
        transformation(root, new_root, interval / 2, LOWER_BOUND, after_right);//для левой ветки
        after_right = min_min;
        transformation(root, new_root, interval / 2, min_min, after_right); //для правой ветки
        after_right = LOWER_BOUND - 1;
    }
}