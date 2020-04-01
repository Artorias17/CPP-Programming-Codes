#include <bits/stdc++.h>

using namespace std;

bool getBooleanForX(const int *moves, const int *coords) {
    bool okX = false;
    int actualXmove = moves[1] - moves[0];
    int negativeXRegion = coords[0] - coords[2];
    int positiveXRegion = coords[4] - coords[0];
    if (actualXmove < 0 && abs(actualXmove) <= negativeXRegion) {
        okX = true;
    } else if (actualXmove > 0 && abs(actualXmove) <= positiveXRegion) {
        okX = true;
    } else if (actualXmove == 0 && moves[0] != 0 && moves[1] != 0 && (negativeXRegion >= 1 || positiveXRegion >= 1)) {
        okX = true;
    } else if (actualXmove == 0 && moves[0] == 0 && moves[1] == 0) {
        okX = true;
    }
    return okX;
}

bool getBooleanY(const int *moves, const int *coords) {
    bool okY = false;
    int actualYmove = moves[3] - moves[2];
    int negativeYRegion = coords[1] - coords[3];
    int positiveYRegion = coords[5] - coords[1];
    if (actualYmove < 0 && abs(actualYmove) <= negativeYRegion) {
        okY = true;
    }
    if (actualYmove > 0 && abs(actualYmove) <= positiveYRegion) {
        okY = true;
    }
    if (actualYmove == 0 && moves[2] != 0 && moves[3] != 0 && (negativeYRegion >= 1 || positiveYRegion >= 1)) {
        okY = true;
    }
    if (actualYmove == 0 && moves[2] == 0 && moves[3] == 0) {
        okY = true;
    }
    return okY;
}

int main() {
    int t, moves[4], coords[6];
    cin >> t;
    while (t--) {
        for (int i = 0; i < 4; i++) {
            cin >> moves[i];
        }
        for (int i = 0; i < 6; i++) {
            cin >> coords[i];
        }
        if (getBooleanForX(moves, coords) && getBooleanY(moves, coords)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
