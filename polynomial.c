#include "polynomial.h"
poly createnode()
{
poly t;
t=(poly)malloc(sizeof(struct Poly));
if(t)
{
    printf("createnode:Memory allocation successfull\n");
    return t;
}
printf("createnode:Memory allocation failed ");
return NULL;
}
hnode createheader()
{
hnode t;
t=(hnode)malloc(sizeof(struct Hnode));
if(t)
{
    printf("createheader:Memory allocation successfull\n");
    t->info=0;
    t->link=NULL;        
    return t;
}
printf("createheader:Memory allocation failed ");
return NULL;
}
void create(hnode h)
{
int i=0,coeff,px,py;
poly nn;
for(;;)
{
printf("Enter 0 to exit input:");
printf("Enter coefficient of term %d:",i+1);
scanf("%d",&coeff);
if(!coeff)
    break;
printf("Enter power of x,power of y:");
scanf("%d%d",&px,&py);
nn=createnode();
nn->coeff=coeff;
nn->px=px;
nn->py=py;
insertRear(h,nn);
i++;
}
}
void insertRear(hnode h,poly nn)
{
poly ln=h->link;
if(!(h->info))
{    
    h->link=nn;
    nn->link=NULL;
    (h->info)++;
    return;
}
while(ln->link)
    ln=ln->link;
ln->link=nn;
nn->link=NULL;
(h->info)++;
}
void display(hnode h)
{
poly t=h->link;
if(!(h->link))
{
printf("Polynomial has no terms!!");
return;
}
while(t)
{
if(t->coeff > 0)
{
    printf("+");
}
printf("%dx^%dy^%d ",t->coeff,t->px,t->py);
t=t->link;
}
}
int evaluate(hnode h)
{
int res=0,x,y;
poly t=h->link;
printf("Enter the values of x and y:");
scanf("%d%d",&x,&y);
while(t)
{
res+=t->coeff*pow(x,t->px)*pow(y,t->py);
t=t->link;
}
return res;
}
