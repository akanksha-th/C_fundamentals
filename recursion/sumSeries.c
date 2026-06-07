// gcc .\sumSeries.c -o out.exe; if ($?) { .\out.exe }

/*
Iteratively as well as recursively calculate the sum of the integer series from 1 to n*/

# include <stdio.h>

int sumSeries_iterative(int n){
    int sum = 0;
    for (int i=1; i<=n; i++) sum += i;
    return sum;
}

int sumSeries_recursive(int n){
    if (n==1) return 1;
    else if (n==0) return 0;
    return n + sumSeries_recursive(n-1);
}


int main(){
    int n = 10;

    // printf("Sum of integer series from 1 to %d: %d\n", n, (n*(n+1))/2); // direct formula
    printf("Sum of integer series from 1 to %d: %d\n", n, sumSeries_iterative(n));
    printf("Sum of integer series from 1 to %d: %d\n", n, sumSeries_recursive(n));

    return 0;
}