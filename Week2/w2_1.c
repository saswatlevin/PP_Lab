#include <mpi.h>
#include <stdio.h>

int main(int argc,char* argv[]){
int i,rank,size;
char x[2];
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0){
for(i=0;i<2;++i)
	scanf("%c",&x[i]);
MPI_Ssend(&x,2,MPI_CHAR,1,1,MPI_COMM_WORLD);
fprintf(stdout,"I have sent %s from process 0\n",x);
fflush(stdout);
}
else {
MPI_Recv(&x,2,MPI_CHAR,0,1,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
fprintf(stdout,"I have sent %s from process 0\n",x);
fflush(stdout);
}



MPI_Finalize();
return 0;
}


