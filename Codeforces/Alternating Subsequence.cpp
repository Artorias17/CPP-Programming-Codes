#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, len, temp;
    vector<int> add;
    long long int sum;
    cin>>t;
    while(t--){
        cin>>len;
        add.clear();
        sum=0;
        for(long i=0; i<len; i++){
            cin >> temp;
            if(i==0){
                add.push_back(temp);
            }
            else if(add[add.size() - 1] < 0 && temp < 0 && temp > add[add.size() - 1]){
                add[add.size() - 1]=temp;
            }
            else if(add[add.size() - 1] > 0 && temp > 0 && temp > add[add.size() - 1]){
                add[add.size() - 1]=temp;
            }else if(add[add.size() - 1] > 0 && temp < 0){
                add.push_back(temp);
            }else if(add[add.size() - 1] < 0 && temp > 0){
                add.push_back(temp);
            }
        }
        for(int i=0; i < add.size(); i++){
            sum+=(long long int)add[i];
        }
        cout << sum << endl;
    }
    return 0;
}

/*Logic:
 * Suppose, there are blocks like |-2| |8 3 8| |-4 -15| |5| |-2 -3| |1|
 * For the largest sequence of alternating signed numbers, a number from each
 * block have to be taken. For largest sum, add largest number from each
 * positive and negative block.
 */
