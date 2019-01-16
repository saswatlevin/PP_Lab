#include <mpi.h>
#include <stdio.h>

int main(int argc,char* argv[]){
int rank,size,x[2],i;
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0){
	for(i=0;i<2;++i)
	scanf("%d",&x[i]);
for(i=0;i<2;++i)
MPI_Send(&x[i],1,MPI_INT,1,1,MPI_COMM_WORLD);
for(i=0;i<2;++i)
fprintf(stdout,"I have sent %d from process 0\n",x[i]);
fflush(stdout);
}
else {

	MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
	for(i=0;i<2;++i)
	fprintf(stdout,"I have sent %d from process 0\n",x[i]);
fflush(stdout);
}
MPI_Finalize();
return 0;
}

