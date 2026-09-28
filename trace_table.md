# Trace Table

Initial data (ID:weight):  
`P1:20, P2:15, P3:20, P4:10, P5:15, P6:20, P7:25, P8:10`

## Merge Sort — important merge stages

| Stage | Subarrays merged | Result of that merge |
|---|---|---|
| 1 | P1(20) + P2(15) | P2(15), P1(20) |
| 2 | P3(20) + P4(10) | P4(10), P3(20) |
| 3 | [P2(15), P1(20)] + [P4(10), P3(20)] | P4(10), P2(15), P1(20), P3(20) |
| 4 | P5(15) + P6(20) | P5(15), P6(20) |
| 5 | P7(25) + P8(10) | P8(10), P7(25) |
| 6 | [P5(15), P6(20)] + [P8(10), P7(25)] | P8(10), P5(15), P6(20), P7(25) |
| 7 | First sorted half + second sorted half | P4(10), P8(10), P2(15), P5(15), P1(20), P3(20), P6(20), P7(25) |

The merge operation selects the left item when weights are equal (`<=`), preserving the original order of equal-weight packages.

## Quick Sort
The program uses Lomuto partitioning and the last element of the current subarray as pivot. Each partition places the pivot in its final position; the program prints the active subarray after every partition. Because partition swaps can move equal-weight records past one another, the standard implementation is not stable.

For the exact sequence of pivot placements and subarray states, run `main.c`; the full console trace is saved in `output.txt`.
