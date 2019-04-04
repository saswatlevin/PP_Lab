__kernel void sortStr(__global char *A,__global char *B){

         int i=get_global_id(0);
         B[i]=A[i];
}         

