#include <bits/stdc++.h>
using namespace std;
int main() {
    long long int n;
    cin>>n;
    long long int ans=floor((n-1)/2.0);
    ans*=n;
    if(n%3==0){
        ans-=(n/3)*2;
    }
    printf("%lld\n", ans);
    return 0;
}

/*Logic:
 * This problem was really hard despite its size.
 * The following link gives somewhat of an idea about its
 * derivation
 * https://math.stackexchange.com/questions/94425/how-many-maximum-number-of-isosceles-triangle-are-possible-in-a-regular-polygon
 * However, this is what I found as conclusion.
 * Take, square for example.
 * For a vertex, if that is centre of a circle, then 2 sides will be its
 * radius. So they will be of same length. Then a chord of the circle can
 * be made. This chord will be the base of the isosceles triangle.
 * There are 4 vertices.
 * So (for a vertex number of chords that can be made inside the polygon)*(number of vertices)=number of isosceles triangle
 *
 * Take, pentagon for example.
 * For a vertex, if that is a centre of a circle, then 2 sides will be its
 * radius. So they will be of same length. Then a chord of the circle can
 * be made. This chord will be the base of the isosceles triangle.
 *
 * For that same vertex, another circle can be made, if the chord from the last
 * circle is taken as radius.
 *
 * From this,
 * n*floor((n-1)/2) isosceles triangles can be determined where n is number of sides for that polygon.
 *
 * Special cases,
 * For any polygon whose sides are multiples of 3, it can be seen that
 * we will be counting the same triangle 3 times.
 * This is because that triangle is an equilateral triangle.
 * Now, equilateral triangle is a special case of an isosceles triangle,
 * because it has 2 sides which are same but the base is same as the other 2 sides.
 * Therefore, (2/3)*n is subtracted.
 *
 * Haven't figured out why 2 is multiplied, but
 * For n=6, 6 vertices are used to make 2 equilateral triangle.
 * But total equilateral counted as 6.
 * So, subtract 4.
 * For n=9, 9 vertices are used to make 3 equilateral triangle.
 * But total equilateral counted as 9.
 * So, subtract 6.
 * This results in subtracting (2/3)*n
 */
