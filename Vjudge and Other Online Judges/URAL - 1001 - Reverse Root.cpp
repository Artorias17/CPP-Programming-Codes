#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<double> arr;
    long long int x;
    while(cin>>x){
        arr.push_back(round(std::sqrt(x)*10000)/10000);
    }
    for(auto i=arr.rbegin(); i!=arr.rend(); i++){
        printf("%.4lf\n", *i);
    }
}
