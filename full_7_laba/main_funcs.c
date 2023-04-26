#include "main_funcs.h"

void new(node** root, int number, short* nodes_count)
{
    if((*nodes_count) == 0)create_root(root, number, nodes_count);
    else add_node(*root, number, nodes_count);
}
void print(node* root)
{
    if (root)
    {
        printf("\t%d\n", root->number);
        print(root->left);
        print(root->right);
    }
}
node* search(node* root, int number)
{
    if(root != NULL)
    {
        if (root->number == number)return root;
        else if (number > root->number) search(root->right, number);
        else if (number < root->number) search(root->left, number);
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
            if ((deleted_node->left == NULL) && (deleted_node->right == NULL))
            {
                if(deleted_node->parent == NULL)
                {
                    free(*root);
                    (*root) = NULL;
                }
                else
                {
                    node* parent = deleted_node->parent;
                    if(deleted_node->number > parent->number) parent->right = NULL;
                    else parent->left = NULL;
                    free(deleted_node);
                }
                (*nodes_count)--;
            }
//left child
            else if ((deleted_node->left != NULL) && (deleted_node->right == NULL))
            {
                node* parent = deleted_node->parent;
                node* child = deleted_node->left;
                delete_node_with_one_child(parent, child, deleted_node);
                (*nodes_count)--;
            }
//right child
            else if ((deleted_node->left == NULL) && (deleted_node->right != NULL))
            {
                node* parent = deleted_node->parent;
                node* child = deleted_node->right;
                delete_node_with_one_child(parent, child, deleted_node);
                (*nodes_count)--;
            }
//two children
            else if ((deleted_node->left != NULL) && (deleted_node->right != NULL))
            {
                node* parent = deleted_node->parent;
                parent = node_for_replacement(deleted_node);
                deleted_node->number = parent->number;
                if (parent -> right == NULL) parent->parent->left = NULL;
                else parent->parent->left = parent->right;
                free(parent);
                (*nodes_count)--;
            }
        }
    }
}

void transformation(node **root, int interval, int min_min)
{
    if(interval != 0)
    {
        int number;
        for (int i = 0; i < (interval + 1) / 2; i++)
        {
            int min_curr = UPPER_BOUND + 1;
            min_min = recursive_min_search(*root, &min_curr, min_min);
        }
        printf("\t\t%d\n", min_min);
        transformation(root, interval / 2, LOWER_BOUND - 1);//min_min correct
        transformation(root, interval / 2, min_min);
    }
}
