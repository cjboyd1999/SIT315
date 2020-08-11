/*
  This program was created for SIT315: M2.T1P by Cameron Boyd | Student #218275923
*/

// Import necessary modules
#include <stdio.h> // Input and output
#include <stdlib.h> // srand() and rand()
#include <chrono> // Timing
#include <omp.h> // Multithreading

// Set the namespace to reduce code (std::module...)
using namespace std;

// Define a maximum number of threads
#define NUM_THREADS 4

// Define a maximum size for the matrices (4 = 4x4 matrix)
#define MAX 10

int matrixA[MAX][MAX];
int matrixB[MAX][MAX];
int matrixC[MAX][MAX];

// Function to multiply a section of matrixC based on thread number
void multiply(int th_id)
{
  for (int i = th_id * MAX / NUM_THREADS; i < (th_id + 1) * MAX / NUM_THREADS; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      for (int k = 0; k < MAX; k++)
      {
        matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }
}

// Function to fill a given matrix with random values between 0 and 10
void createMatrix(int matrix[MAX][MAX])
{
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      matrix[i][j] = rand() % 10;
    }
  }
}

// A function that takes a matrix and prints it row by row
void printMatrix(int matrix[MAX][MAX])
{
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      printf("%i ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main()
{
  // rand() will always produce the same result unless a seed is set
  srand((unsigned int)time(NULL));

  // Setting the number of threads equal to the the defined NUM_THREADS
  omp_set_num_threads(NUM_THREADS);

  // Creating matrix A and B
  createMatrix(matrixA);
  createMatrix(matrixB);

  // Printing matrixA
  printf("Matrix A: \n");
  printMatrix(matrixA);

  // Printing matrixB
  printf("Matrix B: \n");
  printMatrix(matrixB);

  // Start time
  auto start = chrono::high_resolution_clock::now();

  #pragma omp parallel
  {
    int i = omp_get_thread_num();
    multiply(i);
  }

  // Record end time
  auto finish = chrono::high_resolution_clock::now();

  // Printing matrixC
  printf("Matrix A * B: \n");
  printMatrix(matrixC);

  // Calculate and print the time take to multiply matrices A and B
  auto duration = chrono::duration_cast<chrono::microseconds>(finish - start);
  printf("Time taken to multiply matrix A and B: %li microseconds.\n", duration.count());

  return 0;
}
