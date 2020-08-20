#include <iostream>
using namespace std;
int main() {
    string text;
    while(getline(cin, text) && text!="DONE"){
        int i=0, j=text.size()-1;
        bool eat=false;
        while(i<=j){
            if(text[i]=='.' || text[i]==',' || text[i]=='!' || text[i]=='?' || text[i]==' '){
                i++;
                continue;
            }
            if(text[j]=='.' || text[j]==',' || text[j]=='!' || text[j]=='?' || text[j]==' '){
                j--;
                continue;
            }
            if(toupper(text[i])!=toupper(text[j])){
                eat=true;
                break;
            }else{
                i++, j--;
            }
        }
        if(eat){
            cout << "Uh oh.." << endl;
        }else{
            cout << "You won't be eaten!" << endl;
        }
    }
    return 0;
}
