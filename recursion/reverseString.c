// gcc .\reverseString.c -o out.exe; if ($?) { .\out.exe }

/*
*/

# include <stdio.h>
# include <string.h>

void reverse_str(char *str, int start, int end){
    if (start>=end) return ;
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reverse_str(str, start+1, end-1);
}


int main(){
    printf("Enter the string to be reversed:\n");
    char str[50];
    scanf("%s", &str); // no whitespaces

    reverse_str(str, 0, strlen(str)-1);
    printf("Reversed string: %s\n", str);

    return 0;
}