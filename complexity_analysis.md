# Complexity Analysis

Let `n` be the number of packages.

| Algorithm | Best time | Average time | Worst time | Auxiliary space |
|---|---:|---:|---:|---:|
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Standard Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) average recursion; O(n) worst recursion |
| Stable Quick Sort modification used here | O(n log n) in balanced cases | O(n log n) under balanced partitions | O(n²) | O(n) temporary arrays per level; up to O(n²) cumulative allocation in a skewed recursion |

## Notes
- Merge Sort performs predictable `O(n log n)` work regardless of input order. Its merge buffers require linear extra memory.
- Quick Sort is in-place apart from recursion in this implementation, but a poor pivot sequence can cause quadratic time.
- The stable Quick Sort here uses stable three-way grouping (`< pivot`, `= pivot`, `> pivot`) with temporary arrays. This preserves equal-key order but sacrifices the usual low auxiliary-space advantage of in-place Quick Sort.
- Actual comparison counts depend on implementation details and the input. The trace output provides the sequence of partition operations; asymptotic complexity describes growth as `n` increases.
