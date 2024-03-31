# LBYARCH Programming Project 2
## About the Project
### Description
This project aims to compare and analyze the execution time of C and x86-64 assembly in both debug and release mode. For this purpose, a short program was created to calculate the sum of every seven elements (single-precision float) in an array, and these results are then stored in a separate array. <br>
The program follows this format: <br>
### Y[i] = X[i-3] + X[i-2] + X[i-1] + X[i] + X[i+1] + X[i+2] + X[i+3]
<br> 
An example can be seen below:
### Input: X-> 1, 2, 3, 4, 5, 6, 7, 8
### Output: Y-> 28, 35
<br> 
### Steps Followed
1. Initialize the size and values of the array
2. Fill the cache
3. Call the function 30 times
4. Calculate the average time per call/ total tim
5. Repeat steps 2-4 (for SASM)
## How to Run

## Comparative Analysis
## Authors
Jean Cabrera
Bentley Lu
