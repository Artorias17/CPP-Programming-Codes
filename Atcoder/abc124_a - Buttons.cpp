#include <iostream>

int main() {
    int x, y;
    std::cin>>x>>y;
    if(x<y) std::swap(x, y);
    std::cout << std::max(x+x-1, x+y)  << std::endl;
    return 0;
}
