#include <stdio.h>
int main(int argc, char* argv[])
{
int m,n,p,A[10][10],B[10][10];

printf("\nEnter the number of rows and columns of the 1st matrix");
scanf("%d",&m);
scanf("%d",&n);
printf("\nEnter the number of columns of the 2nd matrix");
scanf("%d",&p);
printf("\nEnter the elements in the 1st matrix");
for(int i=0;i<m;++i)
  {
  for(int j=0;j<n;++j)
     {
      scanf("%d",&A[i][j]);
     }
   }

printf("\nEnter the lements of the 2nd matrix");
for(int i=0;i<n;++i)
  {
  for(int j=0;j<p;++j)
     {
      scanf("%d",&B[i][j]);
     }
   }

printf("\nThe product of the matrices is=\n");
for(int i=0;i<n;++i)
   {printf("\n");
    for(int j=0;j<p;++j)
      {
       printf("%d\t",A[i][j]*B[i][j]);
      }
    }

return 0;
}



     
