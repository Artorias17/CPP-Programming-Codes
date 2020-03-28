#include <iostream>
using namespace std;
static int arr[10001];
static int a, b, c, d, e, f;
int fn( int n ) {
    if(arr[n]!=-1){
        return arr[n];
    }
    if( n == 0 ){
        arr[n]=a;
        return a;
    }
    if( n == 1 ){
        arr[n]=b;
        return b;
    }
    if( n == 2 ){
        arr[n]=c;
        return c;
    }
    if( n == 3 ){
        arr[n]=d;
        return d;
    }
    if( n == 4 ){
        arr[n]=e;
        return e;
    }
    if( n == 5 ){
        arr[n]=f;
        return f;
    }

    int modder=10000007;
    int uno=fn(n-1)%modder;
    int dos=fn(n-2)%modder;
    int tres=fn(n-3)%modder;
    int cuatro=fn(n-4)%modder;
    int cinco=fn(n-5)%modder;
    int sies=fn(n-6)%modder;

    arr[n]=( uno + dos + tres + cuatro + cinco + sies ) % modder;
    return arr[n];
}

int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        fill(arr, arr+10001, -1);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0;
}
