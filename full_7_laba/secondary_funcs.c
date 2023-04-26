#include "secondary_funcs.h"

void create_root(node **root, int number, short* nodes_count)
{
    (*root) = malloc(sizeof(node));
    (*root)->number = number;
    (*root)->parent = (*root)->left = (*root)->right = NULL;
    printf("New %hd-st node has been added\n", ++(*nodes_count));
}
void add_node(node* root, int number, short* nodes_count)
{
    node* added_node = root;
    node* parent_of_added_node = root;

    short equality_of_nodes = 0;
    while(added_node != NULL)
    {
        parent_of_added_node = added_node;
        if(number > added_node->number) added_node = added_node->right;
        else if (number < added_node->number) added_node = added_node->left;
        else
        {
            equality_of_nodes = 1;
            break;
        }
    }

    if(equality_of_nodes == 0)
    {
        added_node = malloc(sizeof(node));
        added_node->number = number;
        added_node->left = NULL, added_node->right = NULL, added_node->parent = parent_of_added_node;
        if(number > parent_of_added_node->number) parent_of_added_node->right = added_node;
        else parent_of_added_node->left = added_node;

        printf("New %hd-st node has been added\n", ++(*nodes_count));
    }
    else printf("Node with %hd number already exists\n", number);
}
int enter_number_you_want()
{
    printf("Enter number you want:");
    int number = getint(LOWER_BOUND, UPPER_BOUND);
    return number;
}
int getint(int lower_bound, int upper_bound)
{
    int d;
    while (!scanf("%d", &d) || d < lower_bound || d > upper_bound || getchar() != '\n')
    {
        printf("invalid input\n");
        rewind(stdin);
    }
    return d;
}

void delete_node_with_one_child(node* parent, node* child, node* deleted_node)
{
    if(deleted_node->number > parent->number) parent->right = child;
    else parent->left = child;
    free(deleted_node);
    child->parent = parent;
}

node *node_for_replacement(node *root)
{
    node *p = root, *l = NULL;
    if (p -> right != NULL)return find_node_with_min_number(p -> right);

    l = p->parent;
    while ((l != NULL) && (p == l->right))
    {
        p = l;
        l = l->parent;
    }
    return l;
}
node *find_node_with_min_number(node *root)
{
    node *l = root;
    while (l->left != NULL) l = l->left;
    return l;
}
node *find_node_with_max_number(node *root)
{
    node *r = root;
    while (r->right != NULL) r = r->right;
    return r;
}

int recursive_min_search(node *root, int* min_curr, int min_min)
{
    if (root)
    {
        if((root->number < (*min_curr)) && (min_min < root->number)) (*min_curr) = root->number;
        recursive_min_search(root->left, min_curr, min_min);
        recursive_min_search(root->right, min_curr, min_min);
    }
    return (*min_curr);
}