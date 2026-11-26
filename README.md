# DAA Practical Assignments (C++)

All **14 Design and Analysis of Algorithms** practical programs are collected here, named by assignment number. They are standalone, exam-practice C++ implementations that use ordinary arrays instead of `vector` or `priority_queue`. Compile and run one file at a time (each has its own `main()`).

| No. | Topic | Source |
|---|---|---|
| 01 | Merge Sort | [Assignment_01_Merge_Sort.cpp](Assignment_01_Merge_Sort.cpp) |
| 02 | Strassen's Matrix Multiplication (2x2) | [Assignment_02_Strassens_Matrix_Multiplication.cpp](Assignment_02_Strassens_Matrix_Multiplication.cpp) |
| 03 | Fractional Knapsack (Greedy) | [Assignment_03_Fractional_Knapsack.cpp](Assignment_03_Fractional_Knapsack.cpp) |
| 04 | Huffman Coding | [Assignment_04_Huffman_Coding.cpp](Assignment_04_Huffman_Coding.cpp) |
| 05 | 0/1 Knapsack (Dynamic Programming) | [Assignment_05_Zero_One_Knapsack_DP.cpp](Assignment_05_Zero_One_Knapsack_DP.cpp) |
| 06 | Matrix Chain Multiplication (Dynamic Programming) | [Assignment_06_Matrix_Chain_Multiplication.cpp](Assignment_06_Matrix_Chain_Multiplication.cpp) |
| 07 | N Queens (4x4 Backtracking) | [Assignment_07_N_Queens_Backtracking.cpp](Assignment_07_N_Queens_Backtracking.cpp) |
| 08 | Sum of Subsets (Backtracking) | [Assignment_08_Sum_of_Subsets_Backtracking.cpp](Assignment_08_Sum_of_Subsets_Backtracking.cpp) |
| 09 | 0/1 Knapsack (Branch and Bound) | [Assignment_09_Zero_One_Knapsack_Branch_and_Bound.cpp](Assignment_09_Zero_One_Knapsack_Branch_and_Bound.cpp) |
| 10 | Travelling Salesperson Problem (Branch and Bound) | [Assignment_10_TSP_Branch_and_Bound.cpp](Assignment_10_TSP_Branch_and_Bound.cpp) |
| 11 | Naive String Matching | [Assignment_11_Naive_String_Matching.cpp](Assignment_11_Naive_String_Matching.cpp) |
| 12 | Rabin-Karp and Boyer-Moore String Matching | [Assignment_12_Rabin_Karp_and_Boyer_Moore.cpp](Assignment_12_Rabin_Karp_and_Boyer_Moore.cpp) |
| 13 | Randomized Quick Sort | [Assignment_13_Randomized_Quick_Sort.cpp](Assignment_13_Randomized_Quick_Sort.cpp) |
| 14 | CAPTCHA Generation and Verification | [Assignment_14_CAPTCHA_Generation_and_Verification.cpp](Assignment_14_CAPTCHA_Generation_and_Verification.cpp) |

## How to run

For example:

```bash
g++ -std=c++17 Assignment_09_Zero_One_Knapsack_Branch_and_Bound.cpp -o knapsack
./knapsack
```

On Windows, use `-o knapsack.exe` and run `knapsack.exe`.

## Important notes about simplified exam-practice versions

These are the versions studied for the DAA practical, **not exact copies of the uploaded assignment PDFs**.

- **04 Huffman:** finds two minimum frequencies by scanning the array; the PDF uses a priority queue. Huffman tree construction remains the same.
- **05 DP Knapsack:** displays the maximum profit; the PDF also demonstrates tracing selected items.
- **07 N Queens:** fixed to the 4x4 version practiced; the PDF accepts variable N.
- **09 Branch-and-Bound Knapsack:** ratio-sorted items and fractional upper bound (as discussed); depth-first recursive search instead of the PDF's best-first priority queue. Prints selected item weight/profit pairs and total weight.
- **10 TSP:** follows the PDF's min-outgoing-cost bound and backtracking method.
- **12 Rabin-Karp:** intentionally uses an **additive rolling hash** for memorization instead of the PDF's polynomial hash (d=256, q=101); actual characters are checked before reporting a match. **Boyer-Moore** uses the bad-character rule, with a one-position shift after successful matches.
- **13 Randomized Quick Sort:** random pivot moved to the first position instead of the last.
- **08 Subset Sum:** assumes positive integers; **02 Strassen** uses 2x2 matrices, as practiced.

## Study status (2026-11-26)

All 14 programs are uploaded. **12 of 14 are marked studied/completed; 09 and 10 remain to practice from memory.**
