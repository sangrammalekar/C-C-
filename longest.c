#include <stdio.h>
#include <stdlib.h>               //Dynamic Programming | Set 3 | Longest Increasing Subsequence
#include <string.h>

void LIS(int list[], int temp[], int size, int pos);//Longest Increasing Subsequence
int MAX(int temp[],int size);

int main()
{
int list[]={10, 22, 9, 33, 21, 50, 41, 60};
int temp[8];
LIS(list,temp, 8, 0);
}

void LIS(int list[], int temp[], int size, int pos)
{
if(pos==size)
{
printf("Longest increasing subsequence: %d\n",MAX(temp, size));
}
else if(pos==0)
{
temp[0]=1;
LIS(list,temp,size,++pos);
}
else
{
temp[pos]=1;
for(int i=0; i<pos; i++)
{
if(list[pos]>=list[i]&&temp[pos]<=temp[i])
temp[pos]=temp[i];
}
temp[pos]++;
LIS(list,temp,size,++pos);
}

}

int MAX(int temp[],int size)
{
int max=temp[0];
for(int i=0; i<size-1; i++)
{
if(max<temp[i+1])
max=temp[i+1];
}
return max;
}
