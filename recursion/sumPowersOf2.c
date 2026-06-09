// gcc .\sumPowersOf2.c -o out.exe; if ($?) { .\out.exe }

/*
Iteratively and recursively calculate the sum of the first n powers of 2 in a function.
*/

# include <stdio.h>

int sumPowersOf2_iterative(int n){
    int sum = 0;
    for (int i=1; i<=n; i++){
        sum += i*i;
    }
    return sum;
}

int sumPowersOf2_recursive(int n){
    if (n==0) return 0;
    else if (n==1) return 1;
    return n*n + sumPowersOf2_recursive(n-1);
}


int main(){
    int n = 10;

    // printf("%d\n", (n*(n+1)*((2*n)+1))/6); // direct -> n(n+1)(2n+1)/6
    printf("%d\n", sumPowersOf2_iterative(n));
    printf("%d\n", sumPowersOf2_recursive(n));

    return 0;
}