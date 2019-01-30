#include <stdio.h>
#include <mpi.h>
int main(int argc,char* argv[]){
int rank,size,fact=1,factsum,i=0;
MPI_Init(&argc,&argv);
MPI_Comm_size(MPI_COMM_WORLD,&size);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);

for(i=rank+1;i>1;--i)
	{
	fact=fact*i;
	//printf("\nInside Fact");
	}
MPI_Scan(&fact,&factsum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);


//MPI_Bcast(&factsum,1,MPI_INT,0,MPI_COMM_WORLD);
//printf("\nFactsum outside rank=%d",factsum);
if(rank==size-1)
	printf("\nSum of all the factorials=%d",factsum);

MPI_Finalize();
return 0;
}

