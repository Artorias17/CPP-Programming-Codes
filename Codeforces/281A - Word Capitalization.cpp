#include <iostream>
#define ull unsigned long long
int main() {
    char text[(ull)1e3];
    scanf("%s", text);
    if(text[0]>='a' && text[0]<='z'){
        text[0]='A'+ text[0]-'a';
    }
    printf("%s", text);
    return 0;
}
