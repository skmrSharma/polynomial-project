#include "polynomial.h"
poly createnode()
{
poly t;
t=(poly)malloc(sizeof(struct Poly));
if(t)
    return t;
printf("createnode:Memory allocation failed ");
exit(EXIT_FAILURE);
}
hnode createheader()
{
hnode t;
t=(hnode)malloc(sizeof(struct Hnode));
if(t)
{
    t->info=0;
    t->link=NULL;        
    return t;
}
printf("createheader:Memory allocation failed ");
exit(EXIT_FAILURE);
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
printf("Polynomial has no terms!!\n");
return;
}
for(int i=1;i<=(h->info);i++)
{
if(t->coeff > 0 && i > 1)
    printf("+ ");
if(t->px == 0 && t->py == 0)
    printf("%d ",t->coeff);
else
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
void add(hnode h1,hnode h2,hnode h3)
{
poly p1,p2,p3;
p1=h1->link;
while(p1)
{
	p2=h2->link;
	while(p2)
	{
		if((p1->px==p2->px) && (p1->py==p2->py))
		{	
            if(p1->coeff+p2->coeff)
			{    
                p3=createnode();
			    p3->coeff=p1->coeff+p2->coeff;
			    p3->px=p1->px;
			    p3->py=p1->py;
			    insertRear(h3,p3);
			    break;
            }
		}
		p2=p2->link;
	}
	if(!p2)
	{
		p3=createnode();
		p3->coeff=p1->coeff;
		p3->px=p1->px;
		p3->py=p1->py;
		insertRear(h3,p3);
	}
	p1=p1->link;
}
p2=h2->link;
while(p2)
{
	p1=h1->link;
	while(p1)
	{
		if((p1->px==p2->px) && (p1->py==p2->py))
		{	
            break;
		}
		p1=p1->link;
	}
	if(!p1)
	{
		p3=createnode();
		p3->coeff=p2->coeff;
		p3->px=p2->px;
		p3->py=p2->py;
		insertRear(h3,p3);
	}
	p2=p2->link;
}
}
