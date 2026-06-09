// gcc .\sumNumbersInArray.c -o out.exe; if ($?) { .\out.exe }

/*
*/

# include <stdio.h>

int sum_itr(int *arr, int n){
    int sum = 0, i=0;
    while (i<n){
        sum += arr[i];
        i++;
    }
    return sum;
}

int sum_recur(int *arr, int n){
    if (n==1) return arr[0];
    return arr[n-1] + sum_recur(arr, n-1);
}

int main(){
    int arr[6] = {2, 4, 5, 7, 8, 9};
    int n = sizeof(arr)/sizeof(int);

    printf("Iteratively: %d\n Recursively: %d\n", 
        sum_itr(arr, n), sum_recur(arr, n));
    return 0;
}