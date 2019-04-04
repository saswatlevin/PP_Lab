__kernel void vector_compliment(__global int *A,__global int* C){
//Get the index of the current work item
int i=get_global_id(0);
//Do the operation



int number=0,bin=0,rev=0,comp=0,digit=0;
    number=A[i];
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

  
  while(rev>0)
  {
   digit=rev%10;
   comp=(comp*10)+(digit==0);
   rev=rev/10;
  } 

  C[i]=comp;
}


	

   

