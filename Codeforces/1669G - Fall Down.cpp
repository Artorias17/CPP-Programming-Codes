#include <iostream>
#include <unordered_map>

typedef unsigned long long int u_long;

using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    int t, n, m;
    cin >> t;
    char arr[50][51];
    int obstacle;
    while(t--){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }

        for(int column = 0; column < m; column++){
            obstacle = n;
            for(int row = n-1; row >= 0; row--){
                if(arr[row][column] == '*'){
                    swap(arr[--obstacle][column], arr[row][column]);
                }else if(arr[row][column] == 'o'){
                    obstacle = row;
                }
            }
        }
        for(int i=0; i<n; i++){
            cout << arr[i] << endl;
        }
        cout << endl;
    }
    return 0;
}

/*
 * Logic:
 * Using a 2 pointer approach, start from the bottom row for each column.
 * One pointer points to the top-most row from the bottom that has an obstacle.
 * Another pointer moves up, starting from one row above the obstacle row.
 * If * is found, position is swapped with the row above the obstacle row and move the pointer for obstacle there.
 * If o is found which is an obstacle, simply move the pointer for obstacle to that row.
 */
