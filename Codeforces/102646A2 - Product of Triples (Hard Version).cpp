#include <iostream>
#include <cstring>
#include <bitset>
#include <math.h>
#include <vector>
using namespace std;

int main() {
    vector<unsigned int> arr(10000+1, 0);
    unsigned long long int mul=1;
    for(unsigned int i=1; i<=10000; i++){
        if(i<=10000){
            mul=i;
            for(unsigned int j=i; j<=10000; j++){
                if(mul*j<=10000){
                    mul*=j;
                    for(unsigned int k=j; k<=10000; k++){
                        if(k*mul<=10000){
                            mul*=k;
                            arr[mul]++;
                            mul/=k;
                        }else{
                            break;
                        }
                    }
                    mul/=j;
                }else{
                    break;
                }
            }
            mul/=i;
        }else{
            break;
        }
    }
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        cout << arr[i] << endl;
    }
    return 0;
}
//Logic:
// Brute Force but with constraint at every loop
