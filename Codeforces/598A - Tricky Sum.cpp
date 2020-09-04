#include <iostream>
#include <cmath>
using namespace std;
int main() {
    auto size = (long long) (log(1e9) / log(2));
    long long arr[size + 1];
    for (int i = 0; i <= size; i++) {
        arr[i] = pow(2, i);
    }
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        ans=n*(n+1)/2;
        for (int i = 0; i <= size; i++) {
            if (arr[i] <= n) ans -= 2*  arr[i];
            else break;
        }
        cout << ans << endl;
    }
}
