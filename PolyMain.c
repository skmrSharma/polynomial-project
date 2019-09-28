#include "polynomial.h"
main()
{
hnode header=createheader();
int c,res;
for(;;)
{
printf("\nEnter your choice:\n1.Create a polynomial\n2.Display the polynomial\n3.Evaluate the polynomial\n");
scanf("%d",&c);
switch(c)
{
    case 1:create(header);break;
    case 2:display(header);break;
    case 3:res=evaluate(header);
            printf("Value of the polynomial for given values is %d\n",res);
            break;
    default:exit(0);
}
}
}
