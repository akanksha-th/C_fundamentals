// gcc .\detectPalindrome.c -o out.exe; if ($?) { .\out.exe }

# include <stdio.h>
# include <string.h>

void check_palindrome(char *arr, int left, int right){
    // printf("%d, %d, %c, %c\n", left, right, arr[left], arr[right]);
    if (left >= right) {
        printf("The string is a palindrome.\n");
        return;
    }

    if (arr[left] != arr[right]) {
        printf("The string is not a palindrome.\n");
        return;
    }

    check_palindrome(arr, left+1, right-1);
}

int main(){
    char arr[50];
    printf("Enter a string: ");
    scanf("%s", arr);

    printf("The string is: %s\n", arr);
    check_palindrome(arr, 0, strlen(arr) - 1);

    return 0;
}