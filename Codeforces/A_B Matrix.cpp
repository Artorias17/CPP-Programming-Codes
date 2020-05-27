#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while (t--){
        int n, m, a, b;
        cin>>n>>m>>a>>b;
        if(n*a==m*b){
            cout<< "YES" << endl;
            vector<int> rowCount(n, 0);
            vector<int> colCount(m, 0);
            bool matrix[n][m];
            int j=0;
            for(int i=0; i<n; i++) {
                memset(matrix[i], false, sizeof(matrix[i]));
                for (; rowCount[i]<a; j=(j+1)%m) {
                    if(colCount[j]<b){
                        matrix[i][j]=true;
                        rowCount[i]++;
                        colCount[j]++;
                    }
                }
            }
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    cout<< matrix[i][j];
                }
                cout << endl;
            }
        }else{
            cout<< "NO" << endl;
        }
    }

    return 0;
}

/*Logic:
 * For an A/B matrix to exist, rows*a == columns*b.
 * Meaning going row-wise, the number of blocks
 * that will be 1 must equal to the number of blocks
 * that will be 1 going column-wise.
 *
 * Now, matrix is filled up in the manner spiralling
 * manner. For instance, n=17 m=17 a=13 b=13, results in
 * the following pattern
 * 11111111111110000
 * 11111111100001111
 * 11111000011111111
 * 10000111111111111
 * 01111111111111000
 * 11111111110000111
 * 11111100001111111
 * 11000011111111111
 * 00111111111111100
 * 11111111111000011
 * 11111110000111111
 * 11100001111111111
 * 00011111111111110
 * 11111111111100001
 * 11111111000011111
 * 11110000111111111
 * 00001111111111111
 */
