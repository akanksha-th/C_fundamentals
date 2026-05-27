// gcc .\27.selection_sort.c -o out.exe; if ($?) { .\out.exe }

/*
Selection Sort: it sorts by repeatedly selecting the smallest (or largest) element from the unsorted portion of the array and swapping it with the first unsorted element.
    1. Start with the first element as the minimum.
    2. Compare the minimum with the next element. If the next element is smaller, update the minimum.
    3. Continue this process for the entire array. After the first pass, the minimum element is placed at the beginning of the array.
    4. Repeat the process for the remaining unsorted portion of the array until the entire array is sorted.

Write a program that implements selection sort. 
*/

# include <stdio.h>

void selection_sort(int *arr, int n){
    for (int i=0; i<n-1; i++){
        int min = i;
        int swapped = 0;
        for (int j=i+1; j<n; j++){
            if (arr[j] < arr[min]){ 
                min = j; // track the index of the minimum value, don't swap yet
            }
        }
        if (min !=i){ // // swap once after finding true minimum
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            swapped = 1;
        }
        if (!swapped) break;
    }
};

void print_array(int *arr, int n){
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
};

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: \n");
    print_array(arr, n);

    selection_sort(arr, n);
    printf("Sorted array: \n");
    print_array(arr, n);

    return 0;
}
