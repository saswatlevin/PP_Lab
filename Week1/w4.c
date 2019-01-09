#include <mpi.h>
#include <stdio.h>
int main(int argc, char* argv[])
{   int rank,size;
	int a,b;
    MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
    printf("\nEnter a and b");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("My rank is %d in total %d process",rank,size);
    switch(rank)
	{
	case 0:a=a*b;
	       printf("\n Multiply=%d",a);
	       break;

	case 1:a=a+b;
    printf("\n%Add=%d",a);
    break;

	case 2:a=a-b;
    printf("\n Subtract=%d",a);
    break;

	case 3:a=a/b;
    printf("\n%d Divide=",a);
    break;

	default:printf("\nNo case selected");
	}

	MPI_Finalize();
	return 0;
}

