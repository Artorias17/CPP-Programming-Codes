#include <iostream>

int main() {
    std::string n;
    std::cin>>n;
    long long ans=0;
    for(char x : n){
        ans+=x-'0';
    }
    if(ans%9==0){
        std::cout << "Yes" << std::endl;
    }else{
        std::cout << "No" << std::endl;
    }
    return 0;
}
