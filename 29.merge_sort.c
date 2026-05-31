// gcc .\29.merge_sort.c -o out.exe; if ($?) { .\out.exe }

/*
Merge Sort: "Divide and Conquer" -> works by recursively dividing the input array into 2 halves until we reach arrays of size 1 or 0, which are inherently sorted. Then, it merges those halves back together in a sorted manner.

Write a program that implements the merge sort algorithm to sort an array of integers.
*/

# include <stdio.h>

void merge(int *arr, int left, int mid, int right){
    // 1. calculate the size of each half
    int left_size = mid - left + 1;
    int right_size = right - mid;

    // 2. copy both halves into temporary arrays
    int L[left_size], R[right_size];
    for (int i=0; i<left_size; i++) L[i] = arr[left + i];
    for (int j=0; j<right_size; j++) R[j] = arr[mid + 1 + j];

    // 3. merge back using 2 fingers
    int i=0, j=0, k = left;
    while (i < left_size && j < right_size){
        if (L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++; 
    }

    // 4. copy remaining elements - {one half will be exhausted before the other}
    while (i < left_size) { arr[k] = L[i]; i++; k++; }
    while (j < right_size) { arr[k] = R[j]; j++; k++; }

}

void merge_sort(int *arr, int left, int right){
    if (left >= right) return;  // best case - single element
    int mid = (left+right)/2;
    merge_sort(arr, left, mid);  // sort left half
    merge_sort(arr, mid+1, right);  // sort right half 
    merge(arr, left, mid, right);  // merge sorted halves
}

void print_arr(int *arr, int n){
    for (int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {5, 3, 8, 1, 9, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Before: "); print_arr(arr, n);
    merge_sort(arr, 0, n-1);
    printf("After sorting: "); print_arr(arr, n);

    return 0;
}