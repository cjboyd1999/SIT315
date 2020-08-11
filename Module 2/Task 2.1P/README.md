# SIT315 - Task 2.1P
### Parallel Matrix Multiplication

In this task, I created three programs:
* **MatrixSeq** - A sequential program that multiplies two matrices
* **MatrixMulti** - A *pthread* multithreaded program that multiplies two matrices
* **MatrixOmp** - An *OpenMP* multithreaded program that multiplies two matrices

The purpose of these three programs was to test whether sequential or multithreading is faster. Additionally, the test looked at whether pthread or OpenMP is faster in its execution time. 

Each test was done using the following flow:
1. Define three n-square matrices (A, B and C);
2. Initialise matrices A and B with randomised values between 0 and 10;
3. Print matrices A and B to the console/terminal;
4. Start a timer;
5. Multiply matrix A by matrix B and save it as matrix C;
6. Stop the timer;
7. Print matrix C; and 
8. Print the time taken to multiply matrices A and B (in microseconds).

The writeup PDF covers the times and graph comparisons taken for each program amongst other information about the program's development.

In summary however; 
• Very small programs are better suited to a sequential program;
• The larger the task, the more effective multithreading becomes with regards to
execution time; and
• Using pthread for multithreading results in a lower execution time than OpenMP.