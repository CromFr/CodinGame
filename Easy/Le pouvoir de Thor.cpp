#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        //cout << "SE" << endl; // A single line providing the move to be made: N NE E SE S SW W or NW
        
        int diffX = lightX - initialTX;
        int diffY = lightY - initialTY;
        
        if(diffY<0){
            cout<<"N";
            initialTY--;
        }
        else if(diffY>0){
            cout<<"S";
            initialTY++;
        }
         
        
        if(diffX>0){
            cout<<"E";
            initialTX++;
        }
        else if(diffX<0){
            cout<<"W";
            initialTX--;
        }
        cout<<endl;
        
    }
}