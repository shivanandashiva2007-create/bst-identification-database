# Final Conclusion

Both Merge Sort and Quick Sort can arrange the package records in ascending order of weight. The package IDs are essential because they make it possible to verify the treatment of duplicate weights.

Merge Sort is stable when the merge step chooses the left-side record on equal weights. The standard Quick Sort implementation is not stable because partition swaps can change the relative order of packages with the same weight. The stable Quick Sort modification preserves that order by using stable groups around the pivot, but it needs additional memory.

When maintaining the original order of equal-weight packages is a requirement, Merge Sort is a natural choice: it provides stability and guaranteed `O(n log n)` time with `O(n)` auxiliary space. The stable Quick Sort modification also satisfies stability, but uses more temporary storage than standard Quick Sort.
