__kernel void vector_add(__global int *A,__global int* C)
{
//Get the index of the current work item
int i=get_global_id(0);
//Do the operation

int oct(int num){
  int remainder=0,temp[3]={0,0,0},j=2;
  while(num>0)
  {
        remainder=(num%8);
        if(num!=0)
        temp[j]=remainder;
        printf("\nT=%d\t",temp[j]);
        j--;
        num=num/8;
  }
   num=(temp[0]*100)+(temp[1]*10)+temp[2]; 
   printf("\nTemp is =");
     for(int i=0;i<3;++i)
          printf("%d\t",temp[i]);
printf("\nNum=%d\t",num);
return num;
}

for(i=0;i<LIST_SIZE;++i)
{
C[i]=oct(A[i]);
}


}
