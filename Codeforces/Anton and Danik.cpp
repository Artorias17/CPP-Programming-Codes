#include <bits/stdc++.h>
using namespace std;

char text[100000];
int main() {
    int n, a=0, d=0;
    scanf("%d%c", &n, text);
    scanf("%s", text);
    for(int i=0; i<n; i++){
        if(text[i]=='A'){
            a++;
        }else{
            d++;
        }
    }
    if(a>d){
        printf("Anton\n");
    }else if(d>a){
        printf("Danik\n");
    }else{
        printf("Friendship\n");
    }
    return 0;
}
