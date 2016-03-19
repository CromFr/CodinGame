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
    int road; // the length of the road before the gap.
    cin >> road; cin.ignore();
    int gap; // the length of the gap.
    cin >> gap; cin.ignore();
    int platform; // the length of the landing platform.
    cin >> platform; cin.ignore();
    
    cerr<<"road="<<road<<endl;
    cerr<<"gap="<<gap<<endl;
    cerr<<"platform="<<platform<<endl;
    
    
    int accelStart = 0;
    //int slowStart
    

    // game loop
    while (1) {
        int speed; // the motorbike's speed.
        cin >> speed; cin.ignore();
        int coordX; // the position on the road of the motorbike.
        cin >> coordX; cin.ignore();

        
        
        if(coordX<=road){
            if(coordX+speed >= road+gap)
                cout<<"JUMP"<<endl;
            else{
                int targetSpeed = gap+1;
                int speedDiff = targetSpeed - speed;
                
                if(speedDiff>0)
                    cout<<"SPEED"<<endl;
                else if(speedDiff<0)
                    cout<<"SLOW"<<endl;
                else
                    cout<<"WAIT"<<endl;
            }
        }
        else{
            cout<<"SLOW"<<endl;
        }
    }
}
