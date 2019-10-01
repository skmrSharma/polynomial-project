#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Poly
{
int coeff,px,py;
struct Poly *link;
};
struct Hnode
{
int info;
struct Poly *link;
};
typedef struct Poly* poly;
typedef struct Hnode* hnode;
poly createnode();
hnode createheader();
void create(hnode);
void insertRear(hnode,poly);
void display(hnode);
int evaluate(hnode);
void add(hnode,hnode,hnode);
