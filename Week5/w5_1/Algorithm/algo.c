#include<stdio.h>
#include<stdlib.h>

int main()
{
int A[5],C[5];
int n,i;
int temp=0,rev=0,oct=0;

printf("\nEnter the number of elements");
scanf("%d",&n);

printf("\nEnter the elements");
for(i=0;i<n;++i)
scanf("%d",&A[i]);


for(i=0;i<n;++i)
{
temp=A[i];
rev=0;
while(temp>0)
{
oct=(oct*10)+(temp%8);
temp=temp/8;
}



while(oct>0)
{
rev=(rev*10)+(oct%10);
oct=oct/10;
}

printf("\nrev=%d",rev);

C[i]=rev;
}

printf("\nA is=");
for(i=0;i<n;++i)
printf("%d\t",A[i]);

printf("\nC is=");
for(i=0;i<n;++i)
printf("%d\t",C[i]);

return 0;
}
