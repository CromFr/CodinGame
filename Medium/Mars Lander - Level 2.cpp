#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

float toDeg(float angle){return angle*180.0/3.141592;}
float toRad(float angle){return angle*3.141592/180.0;}


//Game constants
constexpr float GRAVITY = 3.711;
constexpr int LANDING_MAX_VSPEED = 40;
constexpr int LANDING_MAX_HSPEED = 20;
constexpr int POWER_MAX = 4;
constexpr int POWER_MIN = 0;

constexpr int TILT_SPEED = 15;
constexpr float TILT_CONSTANT_Y_RAD = acos(GRAVITY/(float)POWER_MAX);


//Customizable constants
constexpr int LANDING_XMARGIN = 50;


int main()
{
    vector<Point> surface;
    Point flatSurface[2];
    Point flatSurfaceCenter;


    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();
    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY; cin.ignore();
        
        surface.push_back({landX, landY});
    }
    
    //Find landing site
    Point lastPoint;
    for(int i=0 ; i<surfaceN ; i++){
        if(i>0){
            if(surface[i].y == lastPoint.y){
                flatSurface[0] = lastPoint;
                flatSurface[1] = surface[i];
                flatSurfaceCenter = {
                    (flatSurface[0].x+flatSurface[1].x)/2.0,
                    flatSurface[0].y
                };
                break;
            }
        }
        lastPoint = surface[i];
    }
    
    int maxHSpeed;
    //Simulate deceleration
    {
        int flatSurfaceLength = (flatSurface[1].x - flatSurface[0].x) - 2*LANDING_XMARGIN;
        
        float distanceToDecelerate = 0;
        float hrzAccelMax = sin(TILT_SPEED)*1.0;//we allow only TILT_SPEED tilt when landing
        float speed = 0;
        while(distanceToDecelerate<flatSurfaceLength){
            maxHSpeed = speed;
            speed += hrzAccelMax;
            distanceToDecelerate += speed;
        }
        cerr<<"Deceleration simulation results:"<<endl;
        cerr<<"    maxHSpeed="<<maxHSpeed<<endl;
    }
    
    

    // game loop
    while (1) {
        Point pos;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> pos.x >> pos.y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();
        
        
        int nextPeakY;
        {
            nextPeakY = 0;
            int dir = pos.x<flatSurfaceCenter.x? 1 : -1;
            int size = surface.size();
        
            bool counting = false;
            for(int i=dir>0? 0 : size-1 ; -1<i && i<size ; i+=dir){
                if(i>0 && i<size-1){
                    if(!counting){
                        //Searching lander position in surface
                        if(    dir>0 && pos.x>surface[i].x
                            || dir<0 && pos.x<surface[i].x
                            ){
                            nextPeakY = surface[i].y;
                            counting = true;
                        }
                    }
                    else{
                        if(    dir>0 && surface[i].x == flatSurface[1].x
                            || dir<0 && surface[i].x == flatSurface[0].x){
                            //Landing area, stop here
                            break;
                        }
                        else{
                            if(surface[i].y>nextPeakY)
                                nextPeakY = surface[i].y;
                        }
                    }
                }
            }
        }
        
        
        if(flatSurface[0].x+LANDING_XMARGIN <= pos.x && pos.x <= flatSurface[1].x-LANDING_XMARGIN && abs(hSpeed)<=maxHSpeed){
            //In landing zone
            // Adjust hspeed with tilts of 15°
            // Make sure tilt is 0° on landing
            cerr<<"Landing"<<endl;
            
            if(abs(vSpeed)>=LANDING_MAX_VSPEED)
                power = POWER_MAX;
            else
                power = POWER_MAX/2;
            
            if(pos.y + 2*vSpeed > flatSurfaceCenter.y){
                //not landing next round
                
                cerr<<"hspeed OK, slowly moving toward center"<<endl;
                /*int direction = pos.x < flatSurfaceCenter.x ? 1 : -1;
                rotate = -direction*TILT_SPEED;*/
                int targetMaxSpeed = LANDING_MAX_HSPEED/2.0 * (pos.x<flatSurfaceCenter.x ? 1 : -1);
                int speedDiff = targetMaxSpeed - hSpeed;
                
                if(abs(speedDiff)<LANDING_MAX_HSPEED/2.0)
                    rotate = 0;
                else{
                    //negative angle to go to the right (positive X)
                    rotate = (speedDiff>0? -1 : 1)*toDeg(TILT_CONSTANT_Y_RAD);
                }
            }
            else
                rotate = 0;
        }
        else{
            //Out of landing zone
            cerr<<"Approching landing site"<<endl;
            
            int targetMaxSpeed;
            if(flatSurface[0].x<pos.x && pos.x<flatSurface[1].x)
                targetMaxSpeed = 0;
            else
                targetMaxSpeed = maxHSpeed * (pos.x<flatSurfaceCenter.x ? 1 : -1);
            int speedDiff = targetMaxSpeed - hSpeed;
            
            if(abs(speedDiff)<LANDING_MAX_HSPEED/2.0){
                cerr<<"hspeed OK"<<endl;
                rotate = 0;
                power = vSpeed<0 ? POWER_MAX : POWER_MAX-1;
            }
            else{
                cerr<<"hspeed too fast"<<endl;
                rotate = (speedDiff>0? -1 : 1)*toDeg(TILT_CONSTANT_Y_RAD);
                power = POWER_MAX;
            }
            
            
            
            
            
        }


        cout<<rotate<<" "<<power<<endl;
    }
}
