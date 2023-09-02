#include "stdio.h"
#include "stdlib.h"
#include "mpi.h"

#define N 3

struct {
	float value;
	int index;
}local, global;


void print_matrix(float m[][4], int* p)
{
	int i = 0, j = 0;

	for(i=0;i<N;i++)
	{
		for(j=0;j<N+1;j++)
		{
			printf("%f ", m[p[i]][j]);
		}
		printf("\n");
	}
}

int exists(int r, int *p)
{
	int i=0;
	for(i=0;i<N;i++)
		if(r == p[i])
			return 1;
	return 0;
}

int main(int argv, char* argc[])
{
	int rank, size;
	
	MPI_Init(&argv, &argc);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	// input data
	int i = 0, j = 0;
	float m[N][N+1] = 
	{
		{1, 2, 1, 2},
		{3, 8, 1, 12},
		{0, 4, 1, 2}
	};

	// find the minimal value in matrix
	float min = 0;
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(min < m[i][j])
				min = m[i][j];
	min -= 1;

	// record the pivot
	int* pivot =(int* )malloc(sizeof(int)*N);
	for(i=0;i<N;i++)
		*(pivot+i)= -1;

	// Forward elimination
	for(i=0;i<N;i++)
	{
		if(!exists(i, pivot))
		{
			local.value = m[rank][i];
			local.index = rank;
		}
		else
		{
			local.value = min;
			local.index = rank;
		}
		// reduce the max value and store it in global region
		MPI_Allreduce(&local, &global, 1, MPI_FLOAT_INT, MPI_MAXLOC, MPI_COMM_WORLD);
		pivot[i] = global.index;

		if(rank == global.index)
		{
			MPI_Bcast(&global.index, 1, MPI_INT, rank, MPI_COMM_WORLD);
		}

		MPI_Allgather(&m[rank][0], N+1, MPI_FLOAT, m, N+1, MPI_FLOAT, MPI_COMM_WORLD);
		
		if(!exists(rank, pivot))
		{
			float t = (-1)*m[rank][i] / m[pivot[i]][i];
			for(j=i; j<N+1; j++)
				m[rank][j] += m[pivot[i]][j] * t;
		}
	}
	
	MPI_Gather(&m[rank][0], N+1, MPI_FLOAT, m, N+1, MPI_FLOAT, 0, MPI_COMM_WORLD);

	// show the matrix after the reduce
	if(rank == 0)
	{
		printf("The Matrix A:\n");
		print_matrix(m, pivot);
	
		//Back substitution
	
		// vector x 
		float* x = (float* )malloc(sizeof(float)*N);
		for(i=0;i<N;i++)
			x[i] = 0;
	
		for(i=N-1;i>=0;i--)
		{
			x[i] = m[pivot[i]][N]/m[pivot[i]][i];
			for(j=0;j<N;j++)
			{
				m[pivot[j]][N] -= x[i]*m[pivot[j]][i];
				m[pivot[j]][i] = 0;
			}
		}
	
		// print the solution vector x
		printf("Solution Vector X:\n");
		for(i=0; i<N; i++)
			printf("%f ", x[i]);
		printf("\n");
	}
	MPI_Finalize();
	return 0;
}
