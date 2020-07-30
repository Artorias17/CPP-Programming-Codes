#include <bits/stdc++.h>

const long long int s =2e5;

std::vector<int> seive(){
    std::bitset<s>p(0);
    p.flip();
    p[0]=p[1]=false;
    std::vector<int> prime;
    prime.push_back(2);
    for(int i=4; i*1L<s; i+=2){
        p[i]=false;
    }
    for(long long int i=3; i<s; i+=2){
        if(p[i]){
            prime.push_back(i);
            for(long long int j=i*i; j<s; j+=i+i){
                p[j]=false;
            }
        }
    }
    return prime;
}

std::vector<int> generateNumbers(std::vector<int>&p){
    std::vector<int> num;
    for(int i=0; 1L*p[i]*p[i]<s; i++){
        for(int j=i+1; 1L*p[i]*p[j]<s; j++){
            if(i!=j) num.push_back(p[i]*p[j]);
        }
    }
    std::sort(num.begin(), num.end());
    return num;
}

std::vector<int> func(int n, std::vector<int> &a){
    std::vector<int> re;
    for(int i=0; a[i]<n; i++){
        for(int j=i+1; a[i]+a[j]<n; j++){
            for(int k=j+1; a[i]+a[j]+a[k]<n; k++){
                if(i!=j && j!=k && i!=k){
                    re.clear();
                    re.push_back(a[i]);
                    re.push_back(a[j]);
                    re.push_back(a[k]);
                    re.push_back(n-a[i]-a[j]-a[k]);
                    if(re[0]!=re[3] && re[1]!=re[3] && re[2]!=re[3]) return re;
                }
            }
        }
    }
    return re;
}


int main() {
    std::vector<int> prime= seive();
    std::vector<int> gen= generateNumbers(prime);
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        std::vector<int> ans= func(n, gen);
        if(ans.empty()){
            printf("NO\n");
        }else{
            printf("YES\n%d %d %d %d\n", ans[0], ans[1], ans[2], ans[3]);
        }
    }
    return 0;
}

/*Logic:
 * Use seive to generate prime numbers.
 * Then from those prime numbers to generate the "nearly prime" numbers
 * Using those number search for three numbers whose summation is less than n
 * and they are all unique.
 *
 * Misc:
 * Let i= prime which is less than sqrt(2e5)
 * Let j= The next prime after i which is less than 2e5
 * Multiplying them is enough to generate "nearly prime"
 */
