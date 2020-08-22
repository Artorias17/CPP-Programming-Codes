#include <iostream>
int main() {
    int n, x, t;
    std::cin>>n>>x>>t;
    long long y= n/x;
    if(n%x!=0){
        y++;
    }
    y*=t;
    std::cout << y << std::endl;
    return 0;
}
