#include "struct_functions.h"
#include "functions.h"

school* new_pupil()
{
    school* new_p = malloc(sizeof(school));
    new_p->next = NULL;
    new_p->prev = NULL;
//id
    new_p->id = time(NULL);
//full name
    printf(" * Enter full name of this child (to 63 symbols) (Please, write in correct form):");
    fgets(new_p->full_name, 64, stdin);
    rewind(stdin);
//age
    printf(" * Enter age of this child (from 0 to to 100):");
    new_p->age = getshort(0, 100);
//choose class
    printf(" * Enter class of this child:");
    new_p->cl1.i = getshort(1, 4);
//sizeof choosen class
    size_t class_size = -sizeof(int);
    if(new_p->cl1.i == CLASS1)class_size += sizeof(new_p->cl1);
    else if(new_p->cl1.i == CLASS2)class_size += sizeof(new_p->cl2);
    else if(new_p->cl1.i == CLASS3)class_size += sizeof(new_p->cl3);
    else if(new_p->cl1.i == CLASS4)class_size += sizeof(new_p->cl4);

//input average marks for every subject
    float* psubject = (float*)((int*)&new_p->cl1 + 1);
    for(int i = 0; i < class_size/sizeof(float); i++)
    {
        printf("Enter average mark for the subject: ");
        float average_mark = getfloat(0, 10);
        *(psubject++) = average_mark;
    }
//char* address
    printf(" * Enter address of this child (to 63 symbols):");
    rewind(stdin);
    fgets(new_p->address, 64, stdin);
    rewind(stdin);
//telephone
    printf(" * Enter telephone of this child:");
    new_p->telephone = getlonglong(1, 9223372036854775807);
    return new_p;
}

void add(school** p)
{
    school* new_p = new_pupil();
    if(*p != NULL)
    {
        (*p)->next = new_p;
        new_p->prev = *p;
    }
    else *p = new_p;
}
void print(school* p)
{
    printf("    |------------------------------\n"
           "    | 1. id: %d\n"
           "    | 2. full name: %s"
           "    | 3. age: %d\n"
           "    | 4. class: %d\n"
           "    | 5. average mark: %f\n"
           "    | 6. address: %s"
           "    | 7. telephone: %lld\n"
           "    |------------------------------\n", p->id, p->full_name, p->age,
           p->cl1.i, ave_mark(p), p->address, p->telephone);
}
void update(school** p)
{
    printf(" * Enter id of this pupil: ");
    unsigned short int id = (unsigned short)getlonglong(0, 65535);

    if (p == NULL) {
        printf("\n * There no one pupil with id.%d\n", id);
        return;
    }

    short check = 0;
    school* curr = *p;
    while(curr != NULL)
    {
        if(id == curr->id)
        {
            school* pr = curr->prev;
            school* next = curr->next;

            *curr = *new_pupil();
            printf("\n * All info about this pupil has been updated.\n");
            check = 1;
            break;
        }
        curr = curr->next;
    }
    if(check == 0) printf("\n * There no one pupil with id.%d\n", id);
}
void kill(school** p)
{
    printf("\n * Enter id of this pupil: ");
    unsigned short int id = (unsigned short)getlonglong(0, 65535);

    school* to_kill = NULL;
    school* curr = *p;
    while(curr != NULL){
        if(id == curr->id){
            to_kill = curr;
            break;
        }
        curr = curr->next;
    }

    if(to_kill == NULL) {
        printf(" * There no one pupil with id.%d\n", id);
        return;
    }
    else{
        if(to_kill->next)
            to_kill->next->prev = to_kill->prev;
        if(to_kill->prev)
            to_kill->prev->next = to_kill->next;
        *p = NULL;
        printf("\n * This pupil has been removed \n");
        fflush(stdin);
    }
}
//void sort(school* p) {
//    if (p == NULL)
//        return;
//    school* curr = p->next;
//    while (curr != NULL) {
//        school* el = curr;
//        school* curr_temp = el->prev;
//        curr = curr->next;
//
//        while (curr_temp && el->c1.i > curr_temp->c1.i)
//            curr_temp = curr_temp->prev;
//
//        remove(list, el);
//        //дальше бога нет
//
//        if (!curr_temp) {
//            list->begin->prev = el;
//            el->next = list->begin;
//            list->begin = el;
//            el->prev = NULL;
//        }
//        else if(curr_temp->next) {
//            curr_temp->next->prev = el;
//            el->next = curr_temp->next;
//            el->prev = curr_temp;
//            curr_temp->next = el;
//        }
//        else {
//            curr_temp->next = el;
//            el->prev = curr_temp;
//            list->end = el;
//            el->next = NULL;
//        }
//    }
//}

float ave_mark(school* p)
{
    float* psubject = (float*)((int*)&p->cl1 + 1);
    size_t class_size = -sizeof(int);

    if(p->cl1.i == CLASS1)class_size += sizeof(p->cl1);
    else if(p->cl1.i == CLASS2)class_size += sizeof(p->cl2);
    else if(p->cl1.i == CLASS3)class_size += sizeof(p->cl3);
    else if(p->cl1.i == CLASS4)class_size += sizeof(p->cl4);

    float average_mark = 0;
    for(int i = 0; i < class_size/sizeof(float); i++) average_mark += *(psubject+i);
    average_mark /= (class_size/sizeof(float));

    return average_mark;
}

void retarded(school* p)
{
    printf("\n * Enter minimum of normal gpa :");
    float min_gpa;
    while (!scanf("%f", &min_gpa) || min_gpa < 0 || min_gpa > 10)
    {
        printf("invalid input\n");
        rewind(stdin);
    }
    school* curr = p;
    while(curr != NULL){
        if(ave_mark(curr) < min_gpa)
            print(p);
        curr = curr->next;
    }
}