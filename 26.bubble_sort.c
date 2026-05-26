// gcc .\26.bubble_sort.c -o out.exe; if ($?) { .\out.exe }

/*
Bubble Sort: a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.

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
};

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

    return 0;
}