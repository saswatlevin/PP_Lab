#include <mpi.h>
#include <stdio.h>

int main(int argc,char* argv[]){
int i,n,rank,sum=0,size,A[10];

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

if(rank==0){
printf("\nEnter the number of elements");
scanf("%d",&n);
for(i=0;i<n;++i){
	scanf("%d",&A[i]);
}
for(i=0;i<n;++i){
sum+=A[i];
}

MPI_Send(&sum,1,MPI_INT,1,1,MPI_COMM_WORLD);

//fprintf(stdout,"I have sent the sum %d from process 0\n",sum);
//fflush(stdout);
}
else {
MPI_Recv(&sum,1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
fprintf(stdout,"I have sent the sum %d from process 0\n",sum);
fflush(stdout);
}
MPI_Finalize();
return 0;
}
