#include <iostream>

int main() {
    int x=0;
    int n;
    scanf("%d", &n);
    scanf("%c", &x);
    x=0;
    while(n--){
        char s[4];
        scanf("%s", s);
        if(s[0]=='+' || s[2]=='+') x++;
        else if(s[0]=='-' || s[2]=='-') x--;
    }
    printf("%d\n", x);
    return 0;
}
