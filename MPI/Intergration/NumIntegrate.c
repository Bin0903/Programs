#include "stdio.h"
#include "mpi.h"

double f1(double x)
{
  return x*x;
}

int main(int argv, char* argc[])
{
  int rank, size;
  // a, b represents the two sides of the interval
  double a, b;
  // number of parts thar the interval is divided into 
  int n;
  // length of the small interval
  double d;
  // integration result
  int buf = 0;
  int i = 1;
  double res=0, result=0;

  MPI_Init(&argv, &argc);
  MPI_Comm_size(MPI_COMM_WORLD, &size);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);

  double start = MPI_Wtime();
  if(rank == 0)
  {
    // Init
    printf("Enter a, b, and n(b>a, n>1)\n");
    scanf("%lf %lf %d", &a, &b, &n);

    d = (b-a)/n;
    
    for(;i<=size-1;i++)
    { 
      MPI_Send(&a, 1, MPI_DOUBLE, i, 1, MPI_COMM_WORLD);
      MPI_Send(&b, 1, MPI_DOUBLE, i, 1, MPI_COMM_WORLD);
      MPI_Send(&n, 1, MPI_INT, i, 1, MPI_COMM_WORLD);
    }
    // Send
    for(i=1;i<=n;i++)
    {
      int dest = i%(size-1)+1;
      buf = i;
      MPI_Send(&buf, 1, MPI_INT, dest, 0, MPI_COMM_WORLD);
    }
    buf=-1;
    for(i=1;i<=size-1;i++)
      MPI_Send(&buf, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
  }
  else 
  {
    // Recv
    MPI_Recv(&a, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&b, 1, MPI_DOUBLE, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    MPI_Recv(&n, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    d = (b-a)/n;
    while(buf!=-1)
    {
      MPI_Recv(&buf, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
      // Calc
      if(buf != 0 && buf!=-1)
      {
       //MPI_Recv(&buf, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        double T = (f1(a+buf*d)+f1(a+(buf-1)*d))*d/2;
        res += T;
      }
    }
  }
  MPI_Reduce(&res, &result, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  double finish = MPI_Wtime();
  if(rank == 0)
    printf("result=%lf, elapsed time=%lf\n", result, finish-start);
  MPI_Finalize();
  return 0;
}
