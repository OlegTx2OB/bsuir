#include "struct_functions.h"
#include "functions.h"

void add(school* p, int size)
{
//id
    p[size - 1].id = time(NULL);
//full name
    printf(" * Enter full name of this child (to 63 symbols) (Please, write in correct form):");
    fgets(p[size - 1].full_name, 64, stdin);
    rewind(stdin);
//age
    printf(" * Enter age of this child (from 0 to to 100):");
    p[size - 1].age = getshort(0, 100);
//choose class
    printf(" * Enter class of this child:");
    p[size-1].cl1.i = getshort(1, 4);
//sizeof choosen class
    size_t class_size = -sizeof(int);                                               //todo size_t //MINUS?
    if(p[size-1].cl1.i == CLASS1)class_size += sizeof(p[size-1].cl1);
    else if(p[size-1].cl1.i == CLASS2)class_size += sizeof(p[size-1].cl2);
    else if(p[size-1].cl1.i == CLASS3)class_size += sizeof(p[size-1].cl3);
    else if(p[size-1].cl1.i == CLASS4)class_size += sizeof(p[size-1].cl4);

//input average marks for every subject
    float* psubject = (float*)((int*)&p[size-1].cl1 + 1);
    for(int i = 0; i < class_size/sizeof(float); i++)
    {
        printf("Enter average mark for the subject: ");
        float average_mark = getfloat(0, 10);
        *(psubject++) = average_mark;
    }
//char* address
    printf(" * Enter address of this child (to 63 symbols):");
    rewind(stdin);
    fgets(p[size - 1].address, 64, stdin);
    rewind(stdin);
//telephone
    printf(" * Enter telephone of this child:");
    p[size - 1].telephone = getlonglong(1, 9223372036854775807);
}
void print(school* p, int i)
{
    printf("    |------------------------------\n"
           "    | 1. id: %d\n"
           "    | 2. full name: %s"
           "    | 3. age: %d\n"
           "    | 4. class: %d\n"
           "    | 5. average mark: %f\n"
           "    | 6. address: %s"
           "    | 7. telephone: %lld\n"
           "    |------------------------------\n", p[i].id, p[i].full_name, p[i].age,
           p[i].cl1.i, ave_mark(p+i), p[i].address, p[i].telephone);
}
void update(school* p, int size)
{
    unsigned short int id;
    printf(" * Enter id of this pupil: ");
    while (!scanf("%hd", &id) || id > 65535 || id < 0 || getchar() != '\n')
    {
        printf("invalid input\n");
        rewind(stdin);
    }
    if (size == 0) printf("\n * There no one pupil with id.%d\n", id);
    for(int i = 0; i < size; i++)
    {
        if(id == p[i].id)
        {
            add(p, i+1);
            printf("\n * All info about this pupil has been updated.\n"); //there was added new pupil lol
            break;
        }
        else printf("\n * There no one pupil with id.%d\n", id);

    }

}
void kill(school* p, int* size)
{
    printf("\n * Enter id of this pupil: ");
    unsigned short int id = (unsigned short)getlonglong(0, 65535);
    int kill_num = -1;
    for(int i = 0; i < (*size); i++) if(id == p[i].id) kill_num = i;

    if(kill_num == -1) printf(" * There no one pupil with id.%d\n", id);
    else
    {
        for (int i = kill_num; i < (*size) - 1; i++) p[i] = p[i + 1];

        (*size)--;
        realloc(p, (*size) * sizeof(school));
        printf("\n * This pupil has been removed \n");
        fflush(stdin);
    }
}
void sort(school* p, int size)
{
    if(size < 2) printf(" * too few pupils. Please, try next time\n");
    else
    {
        printf("    |By-what-parameter-do-you-want-to-sort?\n"
               "    | 1. id          \n"
               "    | 2. full name   \n"
               "    | 3. age         \n"
               "    | 4. class       \n"
               "    | 5. average mark\n"
               "    | 6. address     \n"
               "    | 7. telephone   \n"
               "    |------------------------------\n");
        char choose;
        while (!scanf("%c", &choose) || choose < '1' || choose > '7' || getchar() != '\n')
        {
            printf("invalid input\n");
            rewind(stdin);
        }
        insertion_sort(p, size, choose);

        printf(" * Sorting was successful\n");
    }
}

float ave_mark(school* p)
{
    //enter class num
    float* psubject = (float*)((int*)&p->cl1 + 1);
    size_t class_size = -sizeof(int);                                           //todo size_t

    if(p->cl1.i == CLASS1)class_size += sizeof(p->cl1);
    else if(p->cl1.i == CLASS2)class_size += sizeof(p->cl2);
    else if(p->cl1.i == CLASS3)class_size += sizeof(p->cl3);
    else if(p->cl1.i == CLASS4)class_size += sizeof(p->cl4);

    float average_mark = 0;
    for(int i = 0; i < class_size/sizeof(float); i++) average_mark += *(psubject+i);
    average_mark /= (class_size/sizeof(float));

    return average_mark;
}

void retarded(school* p, int size)
{
    printf("\n * Enter minimum of normal gpa :");
    float min_gpa;
    while (!scanf("%f", &min_gpa) || min_gpa < 0 || min_gpa > 10)
    {
        printf("invalid input\n");
        rewind(stdin);
    }
    for(int i = 0; i < size; i++)
        if(ave_mark(p + i) < min_gpa)
            print(p, i);
}