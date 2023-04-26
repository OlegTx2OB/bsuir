#pragma once
typedef struct tree
{
    struct tree* parent;
    struct tree* left;
    struct tree* right;

    int number;
}
node;