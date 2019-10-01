#include "polynomial.h"
main()
{
hnode header=createheader();
hnode header2=createheader();
hnode header3=createheader();
int c,res;
for(;;)
{
printf("\nEnter your choice:\n1.Create a polynomial\n2.Display the first polynomial\n3.Evaluate the first polynomial\n4.Add the first and another polynomial\n");
scanf("%d",&c);
switch(c)
{
    case 1:create(header);break;
    case 2:display(header);break;
    case 3:res=evaluate(header);
            printf("Value of the polynomial for given values is %d\n",res);
            break;
    case 4:create(header2);
            printf("\nThe second polynomial is ");
            display(header2);
            printf("\n");
            add(header,header2,header3);
            printf("The resultant polynomial is\n");
            display(header3);
            printf("\n");
            break;
    default:exit(EXIT_SUCCESS);
}
}
}
