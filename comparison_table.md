# Comparison Table

| Criterion | Merge Sort | Standard Quick Sort | Stable Quick Sort modification |
|---|---|---|---|
| Duplicate weights | Handles duplicates; equal keys can retain order | Handles duplicates, but equal-key order may change | Groups equal weights together and preserves their input order |
| Stability | Stable with left-first tie handling | Not stable in general | Stable by construction |
| Comparisons | O(n log n) overall | O(n log n) average; O(n²) worst | O(n log n) balanced; O(n²) worst |
| Time predictability | Guaranteed O(n log n) | Depends on pivot choices | Depends on pivot balance |
| Extra space | O(n) | O(log n) average stack; O(n) worst stack | Additional temporary arrays; higher memory use |
| Equal-weight order important? | Suitable | Not suitable without modification | Suitable |

## Stable order verification

Input order within equal weights:
- Weight 10: `P4` before `P8`
- Weight 15: `P2` before `P5`
- Weight 20: `P1` before `P3` before `P6`

Expected stable sorted order:
`P4(10), P8(10), P2(15), P5(15), P1(20), P3(20), P6(20), P7(25)`

Check the stable Merge Sort and Stable Quick Sort lines in `output.txt` against this order.
