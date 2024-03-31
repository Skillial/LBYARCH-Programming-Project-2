# LBYARCH Programming Project 2
## About the Project
### Description
This project aims to compare and analyze the execution time of a C function and an external function implemented in x86-64 assembly in both debug and release mode. For this purpose, a short program was created in Visual Studio 2022 to calculate the sum of every seven elements in an array, and these results are then stored in a separate array. These elements are single-precision floats that are initialized with the same random value every time the program runs.  
The program follows this format:  
### Y[i] = X[i-3] + X[i-2] + X[i-1] + X[i] + X[i+1] + X[i+2] + X[i+3]

An example can be seen below:  
### Input: X-> 1, 2, 3, 4, 5, 6, 7, 8
### Output: Y-> 28, 35

### Steps Followed
1. Initialize the size and values of the array
2. Fill the cache
3. Call the function 30 times
4. Calculate the average time per call/ total time
5. Repeat steps 2-4 (for SASM)

## How to Run
1. Have a local copy of the project.
2. Change NASM location in the properties of *sliding_window.asm.* (Currently set to *C:/nasm/nasm*)
3. Run *main.c* with the selected configuration.


## Analysis
To verify whether the function performs the same task, the results of both assembly and C are printed simultaneously. This can be observed in the two images below.

To measure the execution time of these functions, a clock was used to record the time before the function call and right after the function call. The difference between these times was then calculated to determine the duration of each function call. Furthermore, it was repeated three times with an array size of 2<sup>20</sup>, 2<sup>24</sup>, 2<sup>28</sup> for both release and debug mode.

### Debug mode 
![Results for Debug Mode](Results/Debug.png)  
In debug mode, the C function runs slower for the three array sizes than the external x86-64 function. Theoretically, this should be the expected result, as assembly is a low-level language and does not go through the same level of abstraction. Code written in assembly is directly mapped to machine language executable by the CPU. More of its advantages can be seen [here](https://www.spiceworks.com/tech/tech-general/articles/what-is-assembly-language/).
|         | 2<sup>20</sup>    | 2<sup>24</sup>   | 2<sup>28</sup>    |
|---------|-----------|-----------|-----------|
| C       | 17.67     | 254.57    | 4047.63   |
| SASM    | 2.77      | 42.30     | 605.53    |

By using the percenatage change formula, SASM is faster than C by 84.32% for 2<sup>20</sup>, 83.38% for 2<sup>24</sup>, and 85.04% for 2<sup>28</sup>, with an average of 84.25%. Furthermore, the size of the input does not affect the speed of the function.
### Release mode
![Results for Release Mode](Results/Release.png)
In release mode, the C function runs faster than the external x86-64 function for all three input sizes. In release mode, the compiler removes all debugging information and fully optimizes C code. This can be seen [here](https://learn.microsoft.com/en-us/visualstudio/debugger/how-to-set-debug-and-release-configurations?view=vs-2022)
|         | 2<sup>20</sup>      | 2<sup>24</sup>      | 2<sup>28</sup>   |
|---------|-----------|-----------|-----------|
| C       | 2.57      | 45.47     | 641.00    |
| SASM    | 2.67      | 48.80     | 648.80    |

With the percentage change formula, SASM is slower than C by 3.89% for 2<sup>20</sup>, 7.32% for 2<sup>24</sup>, and 1.22% for 2<sup>28</sup>, with an average of 84.25%. Similarly with debug mode, the size of the input does not affect the speed of the function.
## Authors
Jean Cabrera  
Bentley Lu
