/*
  This program was created for SIT315: M2.T1P by Cameron Boyd | Student #218275923
  
  References:
  shubham_rana_77, GauravKshirsagar1, nidhi_biet 2020, Multiplication of Matrix using threads, GeeksforGeeks, retrieved August 2 2020, https://www.geeksforgeeks.org/multiplication-of-matrix-using-threads/
*/

// Import necessary modules
#include <stdio.h> // Input and output
#include <stdlib.h> // srand() and rand()
#include <chrono> // Timing
#include <pthread.h> // Multithreading

// Set the namespace to reduce code (std::module...)
using namespace std;

// Define a maximum size for the matrices (4 = 4x4 matrix)
#define MAX 10

// Define the maximum number of threads to use
#define MAX_THREADS 4

int matrixA[MAX][MAX];
int matrixB[MAX][MAX];
int matrixC[MAX][MAX];

int step_i = 0;

// Function to multiply sections of matrixC depending on thread (shubham_rana_77, GauravKshirsagar1, nidhi_biet 2020)
void* multiply(void* arg)
{
  int core = step_i++;

  for (int i = core * MAX / MAX_THREADS; i < (core + 1) * MAX / MAX_THREADS; i++)
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

  // Defining threads
  pthread_t threads[MAX_THREADS];
  int i;

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

  // Creating the threads
  for (int i = 0; i < MAX_THREADS; i++)
  {
    int* p;
    pthread_create(&threads[i], NULL, multiply, (void*)(p));
  }

  // Joining and waiting for threads to finish
  for (int i = 0; i < MAX_THREADS; i++)
  {
    pthread_join(threads[i], NULL);
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
