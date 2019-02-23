__kernel void vector_octal(__global int *A,__global int* C){
//Get the index of the current work item
int i=get_global_id(0);
//Do the operation

int temp;
int oct=0,rev=0;






temp=A[i];

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



C[i]=rev;
}


	

   

