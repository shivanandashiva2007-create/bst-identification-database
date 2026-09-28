#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8

typedef struct {
    int id;
    int weight;
} Package;

void printArray(const char *label, Package a[], int n) {
    printf("%s\n", label);
    for (int i = 0; i < n; i++) {
        printf("P%d(%d)%s", a[i].id, a[i].weight, i == n - 1 ? "\n" : "  ");
    }
}

/* Merge sort: choosing from the left on equal weights makes it stable. */
void merge(Package a[], int left, int mid, int right, int trace) {
    int n1 = mid - left + 1, n2 = right - mid;
    Package *L = malloc(n1 * sizeof(Package));
    Package *R = malloc(n2 * sizeof(Package));
    if (!L || !R) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(L); free(R);
        exit(1);
    }

    for (int i = 0; i < n1; i++) L[i] = a[left + i];
    for (int j = 0; j < n2; j++) R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].weight <= R[j].weight) a[k++] = L[i++];
        else a[k++] = R[j++];
    }
    while (i < n1) a[k++] = L[i++];
    while (j < n2) a[k++] = R[j++];

    if (trace) {
        printf("Merge [%d..%d] and [%d..%d] -> ", left + 1, mid + 1, mid + 2, right + 1);
        for (int x = left; x <= right; x++)
            printf("P%d(%d)%s", a[x].id, a[x].weight, x == right ? "\n" : " ");
    }
    free(L); free(R);
}

void mergeSort(Package a[], int left, int right, int trace) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(a, left, mid, trace);
    mergeSort(a, mid + 1, right, trace);
    merge(a, left, mid, right, trace);
}

/* Standard Lomuto quicksort; it is not stable. */
int partition(Package a[], int low, int high, int trace) {
    int pivot = a[high].weight;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j].weight < pivot) {
            i++;
            Package t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    Package t = a[i + 1]; a[i + 1] = a[high]; a[high] = t;
    int p = i + 1;

    if (trace) {
        printf("Pivot %d, placed at position %d -> ", pivot, p + 1);
        for (int x = low; x <= high; x++)
            printf("P%d(%d)%s", a[x].id, a[x].weight, x == high ? "\n" : " ");
    }
    return p;
}

void quickSort(Package a[], int low, int high, int trace) {
    if (low < high) {
        int p = partition(a, low, high, trace);
        quickSort(a, low, p - 1, trace);
        quickSort(a, p + 1, high, trace);
    }
}

/* Stable quicksort: stable-partition into < pivot, = pivot, > pivot.
   Relative order within each group is preserved. */
void stableQuickSort(Package a[], int n, int trace, int depth) {
    if (n <= 1) return;
    int pivot = a[n - 1].weight;
    Package *less = malloc(n * sizeof(Package));
    Package *equal = malloc(n * sizeof(Package));
    Package *greater = malloc(n * sizeof(Package));
    if (!less || !equal || !greater) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(less); free(equal); free(greater);
        exit(1);
    }
    int nl = 0, ne = 0, ng = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].weight < pivot) less[nl++] = a[i];
        else if (a[i].weight == pivot) equal[ne++] = a[i];
        else greater[ng++] = a[i];
    }
    if (trace) {
        printf("Stable pivot %d: < group %d, = group %d, > group %d\n", pivot, nl, ne, ng);
    }
    stableQuickSort(less, nl, trace, depth + 1);
    stableQuickSort(greater, ng, trace, depth + 1);
    int k = 0;
    for (int i = 0; i < nl; i++) a[k++] = less[i];
    for (int i = 0; i < ne; i++) a[k++] = equal[i];
    for (int i = 0; i < ng; i++) a[k++] = greater[i];

    if (trace) {
        printf("Stable quicksort level %d -> ", depth);
        for (int i = 0; i < n; i++)
            printf("P%d(%d)%s", a[i].id, a[i].weight, i == n - 1 ? "\n" : " ");
    }
    free(less); free(equal); free(greater);
}

int main(void) {
    Package original[N] = {
        {1, 20}, {2, 15}, {3, 20}, {4, 10},
        {5, 15}, {6, 20}, {7, 25}, {8, 10}
    };
    Package a[N];

    printf("PACKAGE WEIGHT SORTING PROJECT\n");
    printf("Format: P<package ID>(weight)\n\n");
    printArray("Input:", original, N);

    memcpy(a, original, sizeof(original));
    printf("\n--- MERGE SORT (trace) ---\n");
    mergeSort(a, 0, N - 1, 1);
    printArray("Merge sort result:", a, N);

    memcpy(a, original, sizeof(original));
    printf("\n--- QUICK SORT (trace; last element as pivot) ---\n");
    quickSort(a, 0, N - 1, 1);
    printArray("Quick sort result:", a, N);

    memcpy(a, original, sizeof(original));
    printf("\n--- STABLE MERGE SORT ---\n");
    mergeSort(a, 0, N - 1, 0);
    printArray("Stable merge sort result:", a, N);

    memcpy(a, original, sizeof(original));
    printf("\n--- STABLE QUICK SORT ---\n");
    stableQuickSort(a, N, 1, 0);
    printArray("Stable quick sort result:", a, N);

    return 0;
}
