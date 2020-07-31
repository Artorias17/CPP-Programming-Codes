#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin>>n>>k;

    //DP matrix
    long long int arr[n+1][k+1];

    //DP matrix initialization
    for(int i=0; i<n+1; i++){
        for(int j=0; j<k+1; j++){
            if(i==0 || j==0) arr[i][j]=0;
            else arr[i][j]=-1;
        }
    }

    //a and b array
    long long int a[n+1], b[k+1];
    a[0]=b[0]=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=1; i<=k; i++){
        cin>>b[i];
    }

    //DP start
    int start=1;
    while(arr[n][k]==-1){
        for(int i=start, j=1; i<=n && j<=k; i++, j++){
            arr[i][j]=max(arr[i-1][j-1]+a[i]*b[j], arr[i-1][j]);
        }
        start++;
        if(start==n+1) break;
    }

    cout << arr[n][k] << endl;
    return 0;
}

/*Logic:
 * For this problem we require the use of dynamic programming.
 * The problem is similar to lcs and 0/1 knapsack.
 * First
 * we need to create 2 arrays
 * a[0.....n] and b[0.....n] where a= players and b=multiplier.
 * a[0] and b[0] indicates that there is no player at position 0
 * and  0th player chosen will not have any multiplier.
 * Next we will create a matrix of values where the row is the players
 * and the column is the multiplier.
 * This matrix will hold the summation of values.
 * Initialize the matrix with -1 except for places where row or column is 0.
 * Next for any player we have to decide whether to pick him or not.
 * If we pick him then we get a[that player's position]* b[place of player chosen from k]
 * else nothing is gained.
 * For this,
 * For player i, and multiplier j,
 * if multiplier is the first one, then we simply choose the max(matrix[i-1][j], a[i]*b[j])
 * else we are always moving diagonally. This is because the next player
 * in line will have (or have not) the next multiplier as players can only be chosen in order.
 * So for those player we choose the max(matrix[i-1][j-1]+a[i]*b[j], arr[i-1][j])
 *
 * The max is basically checking, till that multiplier any players have been chosen
 * or not. This is seen by the summation value.
 *
 * Example
 * x	0   50  	1   	9   	3
 * 0    0   0       0       0       0
 * 1	0   50  	-1  	-1  	-1
 * 9	0   450 	59  	-1  	-1
 * 3	0   450 	453 	86  	-1
 * 8	0   450 	458 	525 	110
 * 19	0   -1  	469 	629 	582
 * 3	0   -1  	-1  	629 	638
 * 2	0   -1  	-1  	-1  	638
 */
