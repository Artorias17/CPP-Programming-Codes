#include <bits/stdc++.h>
using namespace std;
map<int, bool> numbers;

bool isPrime(int x){
    auto i=numbers.find(x);
    if(i != numbers.end()){
        return i->second;
    }

    for(int j=2; j<=sqrt(x); j++){
        if(x%j==0){
            numbers[x]=false;
            return false;
        }
    }
    numbers[x]=true;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num;
    vector<int> arr;
    while(cin>>num && num!=0){
        cout<< num <<" = ";
        if(num<0){
            num=abs(num);
            arr.push_back(-1);
        }

        for(int i=2; i<=sqrt(num);){
            if(num<i){
                break;
            }
            else if(isPrime(i) && num%i==0){
                num=num/i;
                arr.push_back(i);
            }
            else{
                i++;
            }
        }
        if(!(num==0 || num==1)){
            arr.push_back(num);
        }
        if(!arr.empty()){
            cout<< arr[0];
            for(int i=1; i<arr.size(); i++){
                cout<< " x " << arr[i];
            }
        }
        cout<< endl;
        arr.clear();
    }
    return 0;
}
