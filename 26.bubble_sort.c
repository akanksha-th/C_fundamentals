// gcc .\26.bubble_sort.c -o out.exe; if ($?) { .\out.exe }

/*
Sorting: 2 types of sorting algorithms:
1. Comparison-based sorts:  1. bubble sort
                            2. selection sort
                            3. insertion sort
                            4. merge sort
                            5. quick sort
                            6. heap sort
2. Non-comparison-based sorts:  1. counting sort
                                2. radix sort
                                3. bucket sort

*/

/*
Bubble Sort: a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
Bubble sort makes repeated passes through the array. On each pass it compares every pair of adjacent elements and swaps them if they're in the wrong order. 
After each pass the largest unsorted element has "bubbled up" to its correct position at the end. With the early exit optimisation, if a full pass completes with no swaps, the array is already sorted and we stop early.

Worst case:   O(n²)  — array is reverse sorted, every pair swaps every pass
Best case:    O(n)   — array already sorted, swapped flag exits after 1 pass
Average case: O(n²)  — random data, roughly n²/4 comparisons

Write a program that implements bubble sort:
1. void bubble_sort(int *arr, int n) — ascending order
2. void print_arr(int *arr, int n) — print helper
3. Test with {5, 3, 8, 1, 9, 2, 7, 4, 6}
*/

# include <stdio.h>

void bubble_sort(int *arr, int n){
    for (int j=0; j<n-1; j++){
        int swapped = 0;
        for (int i=0; i<n-1; i++){
            int next = arr[i+1];
            if (arr[i] > next){
                arr[i+1] = arr[i];
                arr[i] = next;
                swapped = 1;
            }
        }
        if (!swapped) break;
    }
}

void bubble_sort_cmp(int *arr, int n, int (*cmp)(int, int)){
    for (int i=0; i<n-1; i++){
        int swappped = 0;
        for (int j=0; j<n-1; j++){
            if (cmp(arr[j], arr[j+1]) > 0 ){ // checks if "true" => 1 > 0 condition is met, swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swappped = 1;
            }
        }
        if (!swappped) break;
    }
}

// comparators - return 1 (true) or 0 (false)
int ascending(int a, int b) { return a>b; }
int descending(int a, int b) { return a<b; }

void print_arr(int *arr, int n){
    printf("Sorted array: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {5, 3, 8, 1, 9, 2, 7, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, n);
    print_arr(arr, n);

    bubble_sort_cmp(arr, n, descending);
    print_arr(arr, n);

    return 0;
}