# Package Weight Sorting — DSA Project

**Subject:** Data Structures and Algorithms  
**Language:** C  
**Topic:** Merge Sort, Quick Sort, Stability and Complexity

## Problem
A logistics company receives eight packages with weights `20, 15, 20, 10, 15, 20, 25, 10`. Sort them in ascending order by weight using Merge Sort and Quick Sort, record intermediate steps, then examine whether equal-weight packages retain their original relative order.

Each package is represented by a unique ID (`P1` to `P8`) and its weight. IDs are assigned in the order the packages appear in the question.

## Files
- `main.c` — complete C implementation and trace output
- `input.txt` — supplied package data
- `output.txt` — sample execution output
- `trace_table.md` — important intermediate steps
- `complexity_analysis.md` — time and auxiliary-space complexity
- `comparison_table.md` — algorithm comparison
- `conclusion.md` — final conclusion

## Compile and run
Using GCC:

```bash
gcc main.c -o package_sort
./package_sort
```

On Windows with GCC:

```bash
gcc main.c -o package_sort.exe
package_sort.exe
```

The input is initialized from the assignment data in `main.c`, so no interactive input is required. The program prints trace steps for Merge Sort, standard Quick Sort, and the stable Quick Sort modification.
