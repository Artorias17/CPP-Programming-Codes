//
// Created by theab on 13-Feb-22.
//
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int days = 0 , totalSum = 0;
    cin >> days >> totalSum;
    vector<int> minTime(days, 0);
    vector<int> maxTime(days, 0);
    int minSum = 0, maxSum = 0;

    for(int i=0; i<days; i++){
        cin >> minTime[i] >> maxTime[i];
        minSum += minTime[i];
        maxSum += maxTime[i];
    }

    if(totalSum >= minSum && totalSum <= maxSum){
        for(int i=0; i<days; i++){
            if(totalSum >= minSum -minTime[i] + maxTime[i]){
                minSum = minSum -minTime[i] + maxTime[i];
                minTime[i] = maxTime[i];
            }
            else if(totalSum - minSum <= maxTime[i] - minTime[i]){
                minTime[i] += totalSum-minSum;
                minSum = totalSum;
            }
        }
        if(totalSum == minSum){
            cout << "YES" << endl;
            for(int i=0; i<days-1; i++){
                cout << minTime[i] << " ";
            }
            cout << minTime[days-1] << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;

}
