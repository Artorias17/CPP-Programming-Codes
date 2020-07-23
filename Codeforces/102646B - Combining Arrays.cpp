#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0, j = 0, k = 0; k < 2 * n; k++) {
        if (i < n && j < n) {
            if (a[i] < b[j]) {
                cout << a[i];
                i++;
            } else if (a[i] > b[j]) {
                cout << b[j];
                j++;
            }
        } else if (i == n && j < n) {
            cout << b[j];
            j++;
        } else if (j == n && i < n) {
            cout << a[i];
            i++;
        }
        if (k == 2 * n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}
