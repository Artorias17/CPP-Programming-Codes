#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

long long pointGenerator(int row, int column, int width){
    return (1LL*row*width)+column;
}

vector<int> getMax(vector<int> &men) {
    int maxSize=0;
    vector<int> ret;
    for(int & i : men) maxSize=max(maxSize, i);
    for(int i=0; i<men.size(); i++){
        if(maxSize==men[i]) ret.push_back(i);
    }
    return ret;
}

int main() {

    int h, w, m;
    scanf("%d%d%d", &h, &w, &m);

    vector<int> x(m), y(m);
    unordered_set<long long> coords;
    vector<int> menInRow(h, 0);
    vector<int> menInColumn(w, 0);

    for(int i=0; i<m; i++){
        scanf("%d%d", &x[i], &y[i]);
        x[i]--, y[i]--;
        coords.insert(pointGenerator(x[i], y[i], w));
        menInRow[x[i]]++;
        menInColumn[y[i]]++;
    }

    vector<int> maxRow = getMax(menInRow), maxCol = getMax(menInColumn);

    long long total=menInRow[maxRow[0]]+menInColumn[maxCol[0]];
    for(auto & currentRow : maxRow){
        for(auto & currentCol : maxCol){
            if(coords.find(pointGenerator(currentRow, currentCol, w))==coords.end()){
                printf("%lld\n", total);
                return 0;
            }
        }
    }
    printf("%lld\n", total-1);
    return 0;
}

/*Logic:
 * This problem was giving me TLE because some of the data structures such as
 * map, set used were slow as their insertion and deletion took logarithmic time.
 *
 * Main idea is that, for any row and column chosen, there are 2 possibilities.
 * 1. The bomb placed at a coordinate where there is no one. In that case,
 * summation of people in both row and column is the answer.
 *
 * 2. The bomb placed at a coordinate where there is a person. In, that case,
 * subtract 1 from summation of people in both row and column because we would be
 * counting the the guy on the bomb coordinates twice.
 *
 * So, all we need to do is to find rows where number of people is maxed.
 * Same goes for columns. In this case, row and column are independent to each other.
 *
 * Now, we know that case 1 is the best case. So we  need to find evidence from all
 * possible combinations of rows and columns where the number of people is maximum for each.
 * Once we have the evidence we can say case 1 is the answer. If no evidence is found, then
 * case 2 is the answer.
 */
