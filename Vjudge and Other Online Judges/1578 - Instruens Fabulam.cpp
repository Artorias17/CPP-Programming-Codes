#include <iostream>
#include <vector>

using namespace std;
void Output(vector<vector <string> > &r, vector<int> &cS, string just){
    int totalWidth=cS.size()+1;
    for(int i=0; i<cS.size(); i++){
        totalWidth+=cS[i];
    }
    //First Line
    for(int i=0; i<totalWidth; i++){
        if(i==0) cout<< "@";
        else if(i==totalWidth-1) cout<< "@\n";
        else cout<< "-";
    }
    //Body
    for(int row=0; true; row++){
        if(r[row].size()==0) break;
        if(row==1){
            for(int block=0; block<cS.size(); block++){
                if(block==0) cout<< "|";
                for(int i=0; i<cS[block]; i++){
                    cout<< "-";
                }
                if(block==cS.size()-1) cout<< "|\n";
                else cout<< "+";
            }
        }
        for(int col=0; col<cS.size(); col++){
            if(col==0) cout<< "|";
            if(just[col]=='<'){
                cout<< r[row][col];
                for(int i=0; i<cS[col]- r[row][col].size(); i++){
                    cout<< " ";
                }
                cout<< "|";
            }else if(just[col]=='='){
                for(int i=0; i<(cS[col]-r[row][col].size())/2; i++){
                    cout<< " ";
                }
                cout<< r[row][col];
                for(int i=0; i<cS[col]-r[row][col].size()-(cS[col]-r[row][col].size())/2; i++){
                    cout<< " ";
                }
                cout<< "|";
            }else if(just[col]=='>'){
                for(int i=0; i<cS[col]-r[row][col].size(); i++){
                    cout<< " ";
                }
                cout<< r[row][col];
                cout<< "|";
            }
        }
        cout<< "\n";
    }
    //Last Line
    for(int i=0; i<totalWidth; i++){
        if(i==0) cout<< "@";
        else if(i==totalWidth-1) cout<< "@\n";
        else cout<< "-";
    }
}

int main() {
    vector< vector<string> > row(21); //row Strings
    int rowCounter=0; //row pointer
    string text, justifier; // < left justify, = centered, > right justify
    getline(cin, text);
    justifier=text;
    vector<int> colSize(justifier.size(), 0); //max size of block of string in each column
    
    while(true){
        getline(cin, text);
        if(text.size()==1 && text[0]=='*'){ //EOF
            Output(row, colSize, justifier);
            break;
        }else if(text[0]=='>' || text[0]=='<' || text[0]=='='){ //New table information found, output the current and move to the next.
            Output(row, colSize, justifier);
            justifier=text;
            rowCounter=0;
            colSize.clear();
            colSize.resize(justifier.size(), 0);
            row.clear();
            row.resize(21);
        }else{ //New row found. Every & seperated phrase is part of a column. Find the max size for the column and store the phrases. Phrases have 1 leasding and 1 trailing space.
            int maxColSize=1;
            int currentCol=0;
            row[rowCounter].push_back(" ");
            for(int i=0; i<text.size(); i++){ //String split at &. Checking character by character.
                if(text[i]=='&'){ 
                    row[rowCounter][currentCol]+=" ";
                    maxColSize++;
                    colSize[currentCol]=max(maxColSize, colSize[currentCol]);
                    row[rowCounter].push_back(" ");
                    currentCol++;
                    maxColSize=1;
                }else{
                    row[rowCounter][currentCol]+=text[i];
                    maxColSize++;
                }
            }
            row[rowCounter][currentCol]+=" ";
            maxColSize++;
            colSize[currentCol]=max(maxColSize, colSize[currentCol]);
            rowCounter++;
        }
    }
    return 0;
}

//Brute Force
