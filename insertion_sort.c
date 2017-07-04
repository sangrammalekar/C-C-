#include <stdio.h>
#include <stdlib.h>
void insert_sort(int* list, int pos, int max);
void print(int* list, int max);
 
int main()
{
int i=0;
int* list ;
printf("Enter numbers:");

while(1)
{
if(i==0)
{
list=malloc(sizeof(int)*(i+1));
scanf("%i",&list[i]);
i++;
}
else
{
list=realloc(list,(sizeof(int)*(i+1)));
scanf("%i",&list[i]);
i++;
}
if(list[i-1]==-1)
break;
}

insert_sort(list,0,(i-1));
print(list,i-1);
}

void insert_sort(int* list, int pos, int max)
{
if(pos==max-1)
{return;}
else
{

for(int i=pos; i>=0; i--)
{
   if(list[i+1]<list[i])
   {
   int temp = list[i];
   list[i]=list[i+1];
   list[i+1]=temp;
   }
}
insert_sort(list, pos+1, max);
return;
}

}

void print(int* list, int max)
{
    printf("\n");
    for(int i=0; i<max; i++)
    {
        printf("%i ",list[i]);
    }
     printf("\n");
}
