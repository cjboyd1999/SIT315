/*
  This program was created for SIT315: M2.T1P by Cameron Boyd | Student #218275923
*/

// Import necessary modules
#include <stdio.h> // Input and output
#include <stdlib.h> // srand() and rand()
#include <chrono> // Timing

// Set the namespace to reduce code (std::module...)
using namespace std;


// Define a maximum size for the matrices (E.g. 10 = 10 * 10 matrix)
#define MAX 10

// Create three matrices with a size of MAX * MAX
int matrixA[MAX][MAX];
int matrixB[MAX][MAX];
int matrixC[MAX][MAX];

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

// Main code to execute at runtime
int main()
{
  // rand() will always produce the same result unless a seed is set
  srand((unsigned int)time(NULL));

  // Creating random matrices A and B in a MAX-square matrix
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      // Assign row i, column j a random number between 0 and 10 in matrices A and B
      matrixA[i][j] = rand() % 10;
      matrixB[i][j] = rand() % 10;
    }
  }

  // Printing matrixA
  printf("Matrix A: \n");
  printMatrix(matrixA);

  // Printing matrixB
  printf("Matrix B: \n");
  printMatrix(matrixB);

  // Start time
  auto start = chrono::high_resolution_clock::now();

  // Calculate Matrix A * B and save it as Matrix C
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      for (int k = 0; k < MAX; k++)
      {
        matrixC[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
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
