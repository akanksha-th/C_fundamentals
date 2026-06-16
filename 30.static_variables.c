// gcc .\30.static_variables.c -o out.exe; if ($?) { .\out.exe }

#include<stdio.h>

void fun(int n){
    // a type of variable that retains its value between function calls and persists for the entire duration of the program.
    static int x = 0;

    if (n==0) return;

    x++;
    printf("%d:%d ", n, x);
    fun(n-1);
    printf("%d:%d ", n, x);

}

int main(){
    fun(3);  // 3:1 2:2 1:3 1:3 2:3 3:3
    printf("\n");
    fun(5);  // 5:4 4:5 3:6 2:7 1:8 1:8 2:8 3:8 4:8 5:8
    return 0;
}