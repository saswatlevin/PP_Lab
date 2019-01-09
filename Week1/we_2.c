    #include<stdio.h>
    #include <mpi.h> 
    int main(int argc, char* argv[])
    {
       int n=100, i = 3, count, c,rank,size;
        MPI_Init(&argc,&argv);
        MPI_Comm_rank(MPI_COMM_WORLD,&rank);
        MPI_Comm_size(MPI_COMM_WORLD, &size);
       //printf("Enter the number of prime numbers required\n");
       //scanf("%d",&n);
     
       if ( n >= 1 )
       {
          printf("First %d prime numbers are :\n",n);
          printf("2\n");
       }
       if(rank==0||rank==1){
       for ( count = 2 ; count <= n ;  )
       {
          for ( c = 2 ; c <= i - 1 ; c++ )
          {
             if ( i%c == 0 )
                break;
          }
          if ( c == i && (rank==0||rank==1) )
          {
             printf("%d\n", i);
             count++;
          }
          i++;
       }
       }
       MPI_Finalize();
       return 0;
    }