# OS_Utility
Implementing various techniques related to Operating Systems

## Problem Statements

### 1. Banker's Algorithm:
Write a C program to determine the sequence of execution of
processes such that the system will not enter the deadlock using Bankers algorithm.
The system consists of five processes P0 through P4 and three resources types such as
A(10 instances), B(5 instances), C(7 instances). The details of already allocated
resources at time T0 and the maximum resources required for completing the
execution of these processes are provided in the below table.

| Process 	| ALL 	| OCA 	| TION 	| M 	| A 	| X 	| AVA 	| ILA 	| BLE 	|
|---------	|-----	|-----	|------	|---	|---	|---	|-----	|-----	|-----	|
|         	| A   	| B   	| C    	| A 	| B 	| C 	| A   	| B   	| C   	|
| P0      	| 0   	| 1   	| 0    	| 7 	| 5 	| 3 	| 3   	| 3   	| 2   	|
| P1      	| 2   	| 0   	| 0    	| 3 	| 2 	| 2 	|     	|     	|     	|
| P2      	| 3   	| 0   	| 2    	| 9 	| 0 	| 2 	|     	|     	|     	|
| P3      	| 2   	| 1   	| 1    	| 2 	| 2 	| 2 	|     	|     	|     	|
| P4      	| 0   	| 0   	| 2    	| 4 	| 3 	| 3 	|     	|     	|     	|


### 2. Multithread Program:
Write a multithreaded C program that calculates various
statistical values for a list of numbers. This program will be passed a series of
numbers on the command line and will then create three separate worker threads.
One thread will determine the average of the numbers, the second will determine
the maximum value, and the third will determine the minimum value. For example,
suppose your program is passed the integers
```
90 81 78 95 79 72 85
```
The program will report
```
The average value is 82
The minimum value is 72
The maximum value is 95
```
The variables representing the average, minimum, and maximum values will be
stored globally. The worker threads will set these values, and the parent thread will
output the values once the workers have exited.
Also, create additional threads that determine other statistical values, such as
median and standard deviation and also the total number of integers passed.
