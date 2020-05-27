#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        cin.ignore();
        long long int median=(long long int)pow(2, m-1)-1;
        long long int numbersLeft=pow(2, m);
        const long long int totalNumbers=numbersLeft;
        set<long long int> isDelete;
        string text;
        long long int num=0;
        for(int i=0; i<n; i++){
            cin>>text;
            for(int p=m-1; p>=0; p--){
                num+=(text[p]-'0')*(long long int)pow(2, (m-1)-p);
            }
            if(numbersLeft%2==0){
                if(num<=median) {
                    for (long long int j = median + 1; j < totalNumbers; j++) {
                        if (isDelete.find(j)==isDelete.end()) {
                            median = j;
                            break;
                        }
                    }
                }
            }
            else{
                if(num>=median){
                    for(long long int j=median-1; j>=0; j--){
                        if(isDelete.find(j)==isDelete.end()){
                            median=j;
                            break;
                        }
                    }
                }
            }
            isDelete.insert(num);
            numbersLeft--;
            num=0;
        }
        bitset<60> ans(median);
        text=ans.to_string();
        for(int i=60-m; i<ans.size(); i++){
            cout<< text[i];
        }
        cout<< endl;
    }
    return 0;
}

/*Logic:
 * We are required to find the median number from 0 to (2^m)-1
 * after deleting some numbers from them. Numbers will be given
 * in binary and we are required to output the median in binary.
 * Let, length=current number of numbers. [0....ln-1]
 * If number of numbers is even median position=floor(((length/2)+((length/2)-1))/2)
 * If number of number is odd median position= (length+1)/2
 *--------------------------------------------------------------------------
 * Assume, the numbers present at the moment is even:
 * 0 1 2 3 4 5 6 7     length=8
 * Median is 3.
 *
 * Case 1: Median which is 3 is deleted.
 * 0 1 2 4 5 6 7       length=7
 * Median is 4.
 *
 * Case 2: Some number less than median is deleted. Assuming the number is 2.
 * 0 1 3 4 5 6 7       length=7
 * Median is 4.
 *
 * Case 3: Some number greater than median is deleted. Assuming the number is 5.
 * 0 1 2 3 4 6 7       length=7
 * Median is 3.
 *
 *-------------------------------------------------------------------------------
 * Assume, the numbers present at the moment is odd:
 * 0 1 2 3 4 5 6      length=7
 * Median is 3.
 *
 * Case 1: Median which is 3 is deleted.
 * 0 1 2 4 5 6        length=6
 * Median is 2.
 *
 * Case 2: Some number less than median is deleted. Assuming the number is 2.
 * 0 1 3 4 5 6         length=6
 * Median is 3.
 *
 * Case 3: Some number greater than median is deleted. Assuming the number is 5.
 * 0 1 2 3 4 6         length=6
 * Median is 2.
 *
 */
