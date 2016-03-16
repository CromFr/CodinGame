#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

enum State{
    MOVING,
    TURNING
};

struct Context{
    State state;
    int x, y;//x: hrz, y: vrt. 0 is top left
    string direction = "SOUTH";
    bool stucked = false;
    bool breakerMode = false;
    bool inverted = false;
};
bool isContextInHistory(struct Context& ctx, vector<struct Context>& history){
    for(auto& c : history){
        if(
               c.state == ctx.state
            && c.x == ctx.x
            && c.y == ctx.y
            && c.direction == ctx.direction
            && c.stucked == ctx.stucked
            && c.breakerMode == ctx.breakerMode
            && c.inverted == ctx.inverted
        )
            return true;
    }
    return false;
}

string nextDirection(string dir, bool inverted){
    static vector<string> directions = {"SOUTH", "EAST", "NORTH", "WEST"};
    
    for(int i=0 ; i<4 ; i++){
        if(directions[i]==dir){
            int dirIndex = (i + (inverted? -1 : 1) + 4)%4;
            return directions[dirIndex];
        }
    }
}
int getDirectionX(string dir){
    if(dir == "EAST")
        return 1;
    else if(dir == "WEST")
        return -1;
    return 0;
}
int getDirectionY(string dir){
    if(dir == "SOUTH")
        return 1;
    else if(dir == "NORTH")
        return -1;
    return 0;
}




int main()
{
    vector<string> map;
    vector<int> teleporterX;
    vector<int> teleporterY;
    
    
    int R;
    int C;
    cin >> R >> C; cin.ignore();
    for (int i = 0; i < R; i++) {
        string row;
        getline(cin, row);
        
        //cerr<<row<<endl;
        map.push_back(row);
    }
    
    //Bender state
    struct Context currentContext;
    vector<struct Context> contextHistory;
    
    //Actions done
    vector<string> actions;
    
    //init position
    for(int i=0 ; i<R ; i++){
            
        for(int j=0 ; j<C ; j++){
            
            cerr<<map[i][j]<<" ";
            
            if(map[i][j]=='@'){
                currentContext.x = j;
                currentContext.y = i;
            }
            else if(map[i][j]=='T'){
                teleporterX.push_back(j);
                teleporterY.push_back(i);
            }
        }
        
        cerr<<endl;
        
    }
    cerr<<"Starting on cell "<<currentContext.x<<" "<<currentContext.y<<endl;
    
    
    
    
    while(!isContextInHistory(currentContext, contextHistory)){
        contextHistory.push_back(currentContext);
        
        int nextCellX = currentContext.x+getDirectionX(currentContext.direction);
        int nextCellY = currentContext.y+getDirectionY(currentContext.direction);

        switch(currentContext.state){
            case MOVING:{
                switch(map[nextCellY][nextCellX]){
                    case 'X':
                        if(currentContext.breakerMode){
                            //Break block
                            map[nextCellY][nextCellX] = ' ';
                            cerr<<"    Breaking cell "<<nextCellX<<"/"<<nextCellY<<endl;
                            contextHistory.clear();//world has changed, context history is now invalid
                            continue;
                        }
                    //fallthrough blocking cells
                    case '#':
                        if(!currentContext.inverted)
                            currentContext.direction = "SOUTH";
                        else
                            currentContext.direction = "WEST";

                        currentContext.state = TURNING;
                        cerr<<"    Bump !"<<endl;
                        break;

                    default:{
                        //effectively moving
                        cerr<<"    Moving "<<currentContext.direction<<" to cell "<<nextCellX<<"/"<<nextCellY<<"='"<<map[nextCellY][nextCellX]<<"'"<<endl;

                        currentContext.x = nextCellX;
                        currentContext.y = nextCellY;
                        actions.push_back(currentContext.direction);

                        switch(map[currentContext.y][currentContext.x]){
                            case '$':
                                //suicide
                                cerr<<"============================="<<endl;
                                for(auto& action : actions)
                                    cout<<action<<endl;
                                return 0;

                            case 'S':
                                currentContext.direction = "SOUTH";
                                cerr<<"    Set direction="<<currentContext.direction<<endl;
                                break;
                            case 'E':
                                currentContext.direction = "EAST";
                                cerr<<"    Set direction="<<currentContext.direction<<endl;
                                break;
                            case 'N':
                                currentContext.direction = "NORTH";
                                cerr<<"    Set direction="<<currentContext.direction<<endl;
                                break;
                            case 'W':
                                currentContext.direction = "WEST";
                                cerr<<"    Set direction="<<currentContext.direction<<endl;
                                break;

                            case 'I':
                                currentContext.inverted = !currentContext.inverted;
                                cerr<<"    Inverted mode="<<currentContext.inverted<<endl;
                                break;
                                
                            case 'B':
                                currentContext.breakerMode = !currentContext.breakerMode;
                                cerr<<"    Breaker mode="<<currentContext.breakerMode<<endl;
                                break;
                                
                            case 'T':
                                if(teleporterX[0]==currentContext.x && teleporterY[0]==currentContext.y){
                                    currentContext.x = teleporterX[1];
                                    currentContext.y = teleporterY[1];
                                }
                                else{
                                    currentContext.x = teleporterX[0];
                                    currentContext.y = teleporterY[0];
                                }
                                cerr<<"    Teleported to "<<currentContext.x<<"/"<<currentContext.y<<endl;
                                break;
                        }


                    }break;

                    

                }


            }break;

            case TURNING:{
                if(map[nextCellY][nextCellX]=='#'
                    || (map[nextCellY][nextCellX]=='X' && currentContext.breakerMode==false)){
                    currentContext.direction = nextDirection(currentContext.direction, currentContext.inverted);
                    cerr<<"    Turning "<<currentContext.direction<<endl;
                }
                else{
                    currentContext.state = MOVING;
                }
            }break;
        }
    }
    
    cout<<"LOOP"<<endl;
}
