# DAA Practical Assignments (C++)

Nine completed Design and Analysis of Algorithms practical programs, organized by assignment number and name. These are simplified, standalone exam-practice versions using ordinary arrays instead of vector or priority_queue.

| Assignment | Topic | File |
|---|---|---|
| 01 | Merge Sort | Assignment_01_Merge_Sort.cpp |
| 02 | Strassen's Matrix Multiplication (2x2) | Assignment_02_Strassens_Matrix_Multiplication.cpp |
| 03 | Fractional Knapsack (Greedy) | Assignment_03_Fractional_Knapsack.cpp |
| 05 | 0/1 Knapsack (Dynamic Programming) | Assignment_05_Zero_One_Knapsack_DP.cpp |
| 07 | N Queens (4x4 Backtracking) | Assignment_07_N_Queens_Backtracking.cpp |
| 08 | Sum of Subsets (Backtracking) | Assignment_08_Sum_of_Subsets_Backtracking.cpp |
| 11 | Naive String Matching | Assignment_11_Naive_String_Matching.cpp |
| 13 | Randomized Quick Sort (first-position pivot) | Assignment_13_Randomized_Quick_Sort.cpp |
| 14 | CAPTCHA Generation and Verification | Assignment_14_CAPTCHA_Generation_and_Verification.cpp |

## Pending (not uploaded yet)
04 Huffman Coding; 06 Matrix Chain Multiplication; 09 0/1 Knapsack (Branch and Bound); 10 TSP (Branch and Bound); 12 Rabin-Karp and Boyer-Moore.

## How to run
Compile one source file at a time (each defines main):

    g++ -std=c++17 Assignment_01_Merge_Sort.cpp -o merge_sort
    ./merge_sort

On Windows, use -o merge_sort.exe and run the EXE.

## Notes
- Array-only practice versions, not exact copies of assignment PDFs.
- A few programs use standard algorithm functions sort, max or swap.
- Strassen's is 2x2 and N Queens is fixed to 4x4 as practiced.
- The subset-sum version assumes positive integers.
- For exam preparation, practice writing each program from memory.
