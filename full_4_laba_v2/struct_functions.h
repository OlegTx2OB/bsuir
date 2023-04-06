#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "class_subjects.h"
#pragma once

enum options
{
    ADD = 1, PRINT, UPDATE, KILL, SORT, RETARDED, QUIT,
};

typedef struct
{
    unsigned short int id;
    char full_name[64];
    short int age;
    union
    {
        class1 cl1;
        class2 cl2;
        class3 cl3;
        class4 cl4;
    };
    char address[64];
    long long telephone;
} school;

void add(school* p,int size);
void print(school* p, int i);
void update(school* p, int size);
void kill(school* p, int* size);
void sort(school* p, int size);
float ave_mark(school* p);
void retarded(school* p, int size);