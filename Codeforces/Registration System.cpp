#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
   unordered_map<string, int> mp;

   int n;
   cin >> n;
   string s;
   while(n--){
       cin >> s;

       if(!mp.count(s)){
           mp[s] = 1;
           cout << "OK" << endl;
       }else{
           cout << s << mp[s]++ << endl;
       }
   }
   return 0;
}
