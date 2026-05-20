// gcc .\11.pointers_and_arrays.c -o out.exe; if ($?) { .\out.exe }

/*
Write a C program that:
1. Declares an array of 5 integers and fills it with values
2. Prints all elements using pointer arithmetic — *(arr + i) — instead of arr[i]
3. Writes a function void print_array(int *arr, int len) that does the printing
*/

# include <stdio.h>

void print_array(int *arr, int len){
    for (int j=0; j<len; j++){
        printf("%d%s",  *(arr + j), (j+1==len) ? "\n" : " ");
    }
}

int main(){
    int arr[5];
    for (int i=0; i<5; i++){
        printf("Enter the array elements: \n");
        // arr+i is already the address of element i
        scanf("%d", arr+i); // passes the ADDRESS -> same as scanf("%d", &arr[i]);
    }
    
    printf("The array looks like:\n");
    print_array(arr, 5);
    return 0;
}

// BONUS: If arr points to the first element, what does arr + 1 point to? What about arr + 2? What's actually happening in memory?

/*
'''arr     → address 0x100   (element 0)
arr + 1 → address 0x104   (element 1)
arr + 2 → address 0x108   (element 2)'''

it jumps by 4 bytes, not 1! Because each int is 4 bytes. C automatically scales pointer arithmetic by the size of the type
This is why the type of a pointer matters — int *p vs char *p arithmetic behaves differently!
*/