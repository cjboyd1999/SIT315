# SIT315 - Task 2.2C
### Concurrent Programming

In this task, I created two programs:
* **QuicksortSeq** - A sequential program that uses the Quicksort algorithm to sort a one-dimensional array
* **QuicksortMulti** - An *OpenMP* multithreaded program that aims to speed up the QuicksortSeq program

The purpose of these three programs was to test whether creating a concurrent program would speed up the Quicksort algorithm with regards to its execution time.

The writeup PDF covers the times and graph comparisons taken for each program.

The overall results were identical to that of [Task 2.1P](https://github.com/cjboyd1999/SIT315/tree/master/Module%202/Task%202.1P):
* Small tasks are better suited to a sequential program; and
* The larger the task, the more effective multithreading becomes in reducing execution time.