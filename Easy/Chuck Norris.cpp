#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


void PrintChar(string s){
    
    int length = s.length();
    
    
    
    int lv = -1;
    int count = 0;
    
    for(int i=length*8-1 ; i>=0 ; i--){
        if(i%8==7)
            continue;
            
        int b = ((s[length-1-i/8])&(1<<(i%8)))>>(i%8);
        //cerr<<i%8<<"="<<b<<endl;
        
        if(lv==-1)lv=b;
        
        if(b==lv){
            count++;
        }
        else{
            if(lv==0)cout<<"00 ";
            else    cout<<"0 ";
            
            for(int j=0 ; j<count ; j++){
                cout<<"0";
            }
            cout<<" ";
            
            lv=b;
            count=1;
        }
    }
    if(lv==0)cout<<"00 ";
    else    cout<<"0 ";
    
    for(int j=0 ; j<count ; j++){
        cout<<"0";
    }
    
    
    
    cout<<endl;
    
}


/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
    
    cerr<<MESSAGE<<endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    PrintChar(MESSAGE);
}
