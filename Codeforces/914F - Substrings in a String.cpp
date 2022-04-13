#include <iostream>
#include <bitset>
using namespace std;

bitset<100001> bs[26], ans;

void replaceChar(string& s, int a, char p){
    bs[s[a] - 'a'][a] = false;
    s[a] = p;
    bs[s[a] - 'a'][a] = true;
}

unsigned int countSubString(const string& k, int m, int n){
    if(n - m + 1 < k.size()) return 0;

    ans.set();
    for(int i=0; i<k.size(); i++){
        ans &= bs[k[i] - 'a'] >> i;
    }

    return (ans >> m).count() - (ans >> (n + 1 - k.size() + 1)).count();
}


int main() {
    string s, subs;
    int z, operationType, start, end;
    char p;

    cin >> s >> z;
    s = " " + s;
    for(int i=1; i<s.size(); i++){
        bs[s[i]-'a'][i] = true;
    }

    while(z--){
        cin >> operationType >> start;
        if(operationType == 1){
            cin >> p;
            replaceChar(s, start, p);
        }
        else{
            cin >> end >> subs;
            cout << countSubString(subs, start, end) << endl;
        }
    }
    return 0;
}

/*
 * Logic:
 * Take in the string. Since the index provided is 1-indexed, set an arbitrary character at index 0. Here space is used.
 * Use a bitset of size (1e5 + 1) for every alphabet, so 26 bitsets are required.
 * Each of these bitsets represents the character's position in the given string. (Here 1 at a position means the character exists in that place).
 * For swapping a character -> set false for old character, and true for the new character at that position.
 * For finding out the number of substrings->
 * First check if the given range (m, n) both inclusive is >= the size of the substring.
 * If so, take a new bitset of equal size as the others, and set all of its bits to 1.
 * Then perform bitwise AND operation with positional bitset of every character from substring, right shifted by the index number.
 * The right shift is performed to group the substring characters into a single bit.
 * The right shift is also performed because MSB -> LSB
 * In order to count the number of substrings found, find the difference between ->
 * the number of 1s in the new bitset right shifted by m amount.
 * the number of 1s in the new bitset right shifted by n + 1 - size of the substring + 1.
 * n + 1 - size of the substring + 1 because ->
 * n is inclusive, so the last character of the substring can be at an earlier position or at n.
 * If at n, then (n + 1 - size of substring) will give the start index of the last substring to exist.
 * Then from the next index any other substrings should be omitted.
 *
 * Time complexity = O(n^2 / 32) = O(n^2)
 */
