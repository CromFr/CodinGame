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
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    
    int X=X0, Y=Y0;
    int Xmin=-1, Xmax=W,
        Ymin=-1, Ymax=H;

    // game loop
    while (1) {
        string BOMB_DIR; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> BOMB_DIR; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        if(BOMB_DIR[0]=='U'){
            Ymax = Y;
            Y -= (Y-Ymin)/2;
        }
        else if(BOMB_DIR[0]=='D'){
            Ymin = Y;
            Y += (Ymax-Y)/2;
        }
            
            
        if(BOMB_DIR[BOMB_DIR.length()-1]=='L'){
            Xmax = X;
            X -= (X-Xmin)/2;
        }
        else if(BOMB_DIR[BOMB_DIR.length()-1]=='R'){
            Xmin = X;
            X += (Xmax-X)/2;
        }
        

        cout << X <<" "<<Y << endl; // the location of the next window Batman should jump to.
    }
}
