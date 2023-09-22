#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearSort(void *ptr,int cs,int es,int (*p2f)(void *,void *))
{
int e,g,f;
void *a,*b,*c;
c=(void *)malloc(es);
int w;
e=0;
while(e<=cs-2)
{
f=e+1;
while(f<=cs-1)
{
a=ptr+(f*es);
b=ptr+(e*es);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,es);
memcpy(a,(const void *)b,es);
memcpy(b,(const void *)c,es);
}
f++;
}
e++;
}
free(c);
}

int myComparator(void *left,void *right)
{
int *i,*j;
i=(int *)left;
j=(int *)right;
return (*i)-(*j);
}

int main()
{
int *x;
int y,req;
printf("Enter Req : ");
scanf("%d",&req);
if(req<=0)
{
printf("Inavlid Requirment : %d\n",req);
return 0;
}
x=(int *)malloc(sizeof(int)*req);
if(x==NULL)
{
printf("Unable to allocate memory");
return 0;
}
for(y=0;y<req;y++)
{
printf("Enter a number : ");
scanf("%d",(x+y));
}
linearSort(x,req,sizeof(int),myComparator);
for(y=0;y<req;y++) printf("%d\n",x[y]);
free(x);
return 0;
}