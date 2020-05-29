#include <bits/stdc++.h>
using namespace std;

double x, y, c;
double eqn(double RoadDis){
    double OneByD=1/(sqrt(pow(x, 2)-pow(RoadDis, 2)));
    double OneByE=1/(sqrt(pow(y, 2)-pow(RoadDis, 2)));
    double OneByC=1/c;
    return OneByD+OneByE-OneByC;
}
int main() {
    int t;
    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%lf%lf%lf", &x, &y, &c);
        double left=0, right=min(x, y), mid, eqnResult;
        while(abs(left-right)>0.0000001){
            mid=(left+right)/2;
            eqnResult=eqn(mid);
            if(eqnResult<0){
                left=mid;
            }else if(eqnResult>0){
                right=mid;
            }else{
                break;
            }
        }
        if(abs(round(mid)-mid)<0.0000001){
            printf("Case %d: %.0lf\n", i, mid);
        }else{
            printf("Case %d: %.10lf\n", i, mid);
        }

    }


}

/*Logic:
 * This problem requires the idea of use bisection method.
 * |\X
 * | \ Y/|
 * |d x  |e
 * |/ | \|
 * -------
 *    r
 * We can see that, the bigger right angled triangle on the left side is a bigger
 * version of the smallest right angled triangle on the lower right.
 * Also, the bigger right angled triangle on the right is bigger version
 * of the smallest right angled triangle on the lower right.
 * Both of the smaller version has the same vertical side of size c.
 * Therefore,
 * Formula can be derived using triangle side-side-side theorem.
 * This leads us with the formula
 * (1/(x^2)-(r^2))+(1/(y^2)-(r^2))-(1/c)=0
 * Then, using bisection to find the mid point where lower and upper r
 * differ by 0.000001.
 * For any midpoint the equation is negative, then r was small, so we need to increase r.
 * For any midpoint the equation is positive, then r was big, so we need to decrease r.
 */
