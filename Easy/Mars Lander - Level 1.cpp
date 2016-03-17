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
    int N; // the number of points used to draw the surface of Mars.
    cin >> N; cin.ignore();
    
    int nLastLandX = -1;
    int nLastLandY = -1;
    int nLandX0, nLandX1, nLandY;
    for (int i = 0; i < N; i++) {
        int LAND_X; // X coordinate of a surface point. (0 to 6999)
        int LAND_Y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> LAND_X >> LAND_Y; cin.ignore();
        
        if(nLastLandY == LAND_Y){
            nLandX0 = nLastLandX;
            nLandX1 = LAND_X;
            nLandY = LAND_Y;
        }
        nLastLandY = LAND_Y;
        nLastLandX = LAND_X;
    }

    // game loop
    while (1) {
        int X;
        int Y;
        int HS; // the horizontal speed (in m/s), can be negative.
        int VS; // the vertical speed (in m/s), can be negative.
        int F; // the quantity of remaining fuel in liters.
        int R; // the rotation angle in degrees (-90 to 90).
        int P; // the thrust power (0 to 4).
        cin >> X >> Y >> HS >> VS >> F >> R >> P; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        int VP, HP;
        
        if(X<nLandX0 || X>nLandX1){//out of land
            if(X<nLandX0)       HP = 5;
            else if(X>nLandX1)  HP = -5;
        }
        else{
            HP = -10*HS;
        }
        
        VP = (VS-40)*3.711;
        
        //int angle = 180.0*atan(HP/VP)/3.1415;
        int power;// = sqrt(HP*HP+VP*VP);
        //if(power>4)power=4;
        
        if(fabs(VS)>39)
            power = 4;
        else
            power = 0;

        cout << 0<<" "<<power<< endl; // R P. R is the desired rotation angle. P is the desired thrust power.
    }
}
