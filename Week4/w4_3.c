#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
void input (int A[SIZE][SIZE],int m){
int i,j;
fprintf(stdout,"\nEnter the elements");
fflush(stdout);
for(i=0;i<m;++i)
	for(j=0;j<m;++j)
        scanf("%d",&A[i][j]);
}
void output (int A[SIZE][SIZE],int m){
int i,j;
for(i=0;i<m;++i)
{   printf("\n");
    for(j=0;j<m;++j)
	{
		fprintf(stdout,"%d\t",A[i][j]);
        fflush(stdout);

	}
 }
}

int main(int argc,char* argv[])
{
	int rank,size,A[SIZE][SIZE],i=0,j=0,key=0,m=3,from,to,B[SIZE][SIZE];
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&size);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);


	if(rank==0)
    {
		            fprintf(stdout,"\nEnter the dimensions of the matrix");
				    fflush(stdout);
				    scanf("%d",&m);
				    fprintf(stdout,"\nEnter the element to be searched");
				    		    	fflush(stdout);
				    		    	scanf("%d",&key);
				    input(A,m);
    }

	from =(rank*m)/size;
			to = ((rank+1)*m)/size;

	if((m%size!=0) && (rank==0))
	{
	    //fprintf(stdout,"\nMatrix size isn't divisible by number of processes");
        //fflush(stdout);
        MPI_Finalize();
	    exit(1);
	}

	//fprintf(stdout,"\nBefore Bcast\n");
	//fflush(stdout);

	MPI_Bcast(A,m*m,MPI_INT,0,MPI_COMM_WORLD);

	//fprintf(stdout,"\nBefore Scatter\n");
	//fflush(stdout);

	MPI_Scatter (A, (m*m)/size, MPI_INT, B[from], (m*m)/size, MPI_INT, 0, MPI_COMM_WORLD);
    //printf("=============================================M=%d",m);
	for(i=0;i<m;++i)
	{   //fprintf(stdout,"\nInside search loop\n");
	    //fflush(stdout);
	    for(j=0;j<m;++j)
		{
			if(key==A[i][j])
			{
			fprintf(stdout,"\nFound=%d\t",key);
            fflush(stdout);
			break;
			}
			}
	 }
	MPI_Gather (B[from], (m*m)/size, MPI_INT, A, (m*m)/size, MPI_INT, 0, MPI_COMM_WORLD);
	/*if(rank==0)
	{
			output(A,m);
	}*/

	return 0;
}

