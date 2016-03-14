#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    for(auto& c : T) c = toupper(c);
    
    
    for (int i = 0; i < H; i++) {
        string ROW;
        getline(cin, ROW);
        //cerr<<ROW<<endl;
        
        for(char c : T){
            int nCharPos;
            if(c>='A' && c<='Z')
                nCharPos=c-'A';
            else
                nCharPos=26;
            
            cout<<ROW.substr(nCharPos*L, L);
            
        }
        cout<<endl;
    }
}
