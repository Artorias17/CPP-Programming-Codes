#include <iostream>

int main() {
    long long totalHeight=0;
    int arrSize;
    std::cin>>arrSize;
    int arr[arrSize];
    for(int i=0, x; i<arrSize; i++){
        std::cin>>x;
        arr[i]=x;
        if(i!=0){
            if(arr[i-1]>arr[i]){
                totalHeight+=arr[i-1]-arr[i];
                arr[i]=arr[i-1];
            }
        }
    }
    std::cout << totalHeight << std::endl;
    return 0;
}
