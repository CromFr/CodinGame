#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
int main()
{
    vector<string> grid;
    
    
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    cerr<<width<<"x"<<height<<endl;
    for (int i = 0; i < height; i++) {
        string line; // width characters, each either 0 or .
        getline(cin, line);
        
        grid.push_back(line);
        cerr<<"  "<<line<<endl;
    }
    
    for(int h=0 ; h<height ; h++){
        for(int w=0 ; w<width ; w++){
            if(grid[h][w]=='0'){
                cout<<w<<" "<<h<<" ";
                
                bool wfound=false;
                for(int i=1 ; !wfound && w+i<width ; i++){
                    if(grid[h][w+i]=='0'){
                        cout<<w+i<<" "<<h<<" ";
                        wfound = true;
                    }
                }
                if(!wfound) cout<<"-1 -1 ";
                
                
                bool hfound=false;
                for(int i=1 ; !hfound && h+i<height ; i++){
                    if(grid[h+i][w]=='0'){
                        cout<<w<<" "<<h+i<<" ";
                        hfound = true;
                    }
                }
                if(!hfound) cout<<"-1 -1 ";
                    
                cout<<endl;
            }
        }
    }
}
