#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum Direction{
    TOP, BOT, LEFT, RIGHT,
    DEATH=-1,
    INVALID
};

int main()
{
    int W; // number of columns.
    int H; // number of rows.
    cin >> W >> H; cin.ignore();
    
    int map[H][W];
    
    for (int i = 0; i < H; i++) {
        //string LINE; // represents a line in the grid and contains W integers. Each integer represents one room of a given type.
        //getline(cin, LINE);
        
        for(int j=0 ; j<W ; j++){
            cin>>map[i][j];
            cerr<<map[i][j]<<(map[i][j]>9? " " : "  ");
        }
        cin.ignore();
        cerr<<endl;
    }
    int EX; // the coordinate along the X axis of the exit (not useful for this first mission, but must be read).
    cin >> EX; cin.ignore();
    
    

    // game loop
    while (1) {    
        int XI;
        int YI;
        string POS;
        cin >> XI >> YI >> POS; cin.ignore();
        
        cerr<<"Entering type "<<map[YI][XI]<<" from "<<POS<<endl;;
        
        enum Direction from = POS=="TOP"?TOP : POS=="LEFT"? LEFT : POS=="RIGHT"? RIGHT : DEATH;
        enum Direction nextDir = INVALID;
        switch(map[YI][XI]){
            //case 0:  nextDir= DEATH; break;
            
            case 1:  nextDir= BOT; break;
            
            case 2:  nextDir= from==LEFT? RIGHT : from==RIGHT? LEFT : DEATH; break;
            case 3:  nextDir= from==TOP? BOT : DEATH; break;
            
            case 4:  nextDir= from==TOP? LEFT : from==RIGHT? BOT : DEATH; break;
            case 5:  nextDir= from==TOP? RIGHT : from==LEFT? BOT : DEATH; break;
            
            case 6:  nextDir= from==LEFT? RIGHT : from==RIGHT? LEFT : DEATH; break;
            case 7:  nextDir= from==TOP? BOT : from==RIGHT? BOT : DEATH; break;
            case 8:  nextDir= from==LEFT? BOT : from==RIGHT? BOT : DEATH; break;
            case 9:  nextDir= from==LEFT? BOT : from==TOP? BOT : DEATH; break;
            
            case 10: nextDir= from==TOP? LEFT : DEATH; break;
            case 11: nextDir= from==TOP? RIGHT : DEATH; break;
            case 12: nextDir= from==RIGHT? BOT : DEATH; break;
            case 13: nextDir= from==LEFT? BOT : DEATH; break;
            
            default: cerr<<"UNKNOWN CELL"<<endl;
        }
        
        switch(nextDir){
            case BOT: YI++; break;
            case LEFT: XI--; break;
            case RIGHT: XI++; break;
            case TOP: cerr<<"Indiana is levitating !"<<endl; return 0;
            case DEATH: cerr<<"HAN SOLO IS DEAD !"<<endl; return 0;
        }
        
        cout<<XI<<" "<<YI<<endl;
    }
}
