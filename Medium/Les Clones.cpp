#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Floor{
public:
    //int elevatorPos = -1;
    //int exitPos = -1;
    int target;
};


int main()
{
    int nbFloors; // number of floors
    int width; // width of the area
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    
    vector<Floor> floors;
    for(int i=0 ; i<nbFloors ; i++){
        floors.push_back(Floor());
    }
    floors[exitFloor].target = exitPos;
    
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        
        floors[elevatorFloor].target = elevatorPos;
    }

    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        
        if(cloneFloor==-1){
            cout<<"WAIT"<<endl;
        }
        else{
            int targetPosition = floors[cloneFloor].target;
            if(direction=="LEFT")targetPosition--;
            else if(direction=="RIGHT")targetPosition++;
            
            string targetDirection;
            if(targetPosition-clonePos<0)       targetDirection = "LEFT";
            else if(targetPosition-clonePos>0)  targetDirection = "RIGHT";
            else{
                cout<<"BLOCK"<<endl;
                continue;
            }
            
            if(direction!=targetDirection)
                cout<<"BLOCK"<<endl;
            else{
                cout<<"WAIT"<<endl;
            }
        }
    }
}
