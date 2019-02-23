#include <stdio.h>
int main()
{
   int number=0,bin=0,rev=0,comp=0,digit=0;
   printf("\nEnter Number");
   scanf("%d",&number);
   //number=~number;
   //printf("\nNumber is now %d\t",number);
   while(number>0)
   {
     bin=(bin*10)+(number%2);
     number=number/2;
   }
   while(bin>0)
   {
     rev=(rev*10)+(bin%10);
     bin=bin/10;
   }

  printf("\nThe binary value is=%d\t",rev);
  while(rev>0)
  {
   digit=rev%10;
   comp=(comp*10)+(digit==0);
   rev=rev/10;
  } 
   
   printf("\nThe One's Complement is=%d\t",comp); 
  return 0;
 }



