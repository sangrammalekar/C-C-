#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void rotate(int mat[][6],int dim, int level);
void print(int mat[][6], int dim);
int main()
{
int val=0;
int mat[6][6];

for(int i=0;i<6;i++)
{ for(int j=0;j<6;j++)
{
mat[i][j]=val++;
}
}
print(mat,6);
printf("\n");
rotate(mat,6,0);
//rotate(mat,4,0);
//rotate(mat,4,0);
print(mat,6);
}

void rotate(int mat[][6],int dim, int level)
{
if(dim!=level)
{
for(int i=0;i<dim-level-1;i++)
{
int temp;

for(int j=level;j<dim-1;j++)
{
temp=mat[level][j+1];
mat[level][j+1]=mat[level][level];
mat[level][level]=temp;
}

for(int j=level;j<dim-1;j++)
{
temp=mat[j+1][dim-1];
mat[j+1][dim-1]=mat[level][level];
mat[level][level]=temp;
}

for(int j=dim-1;j>level;j--)
{
temp=mat[dim-1][j-1];
mat[dim-1][j-1]=mat[level][level];
mat[level][level]=temp;
}

for(int j=dim-1;j>level;j--)
{
temp=mat[j-1][level];
mat[j-1][level]=mat[level][level];
mat[level][level]=temp;
}
}
rotate(mat,dim-1,level+1);
}


}

void print(int mat[][6], int dim)
{
for(int i=0;i<dim;i++)
{ for(int j=0;j<dim;j++)
{
printf("%2d ",mat[i][j]);
}
printf("\n");
}

}
