#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Point{
    long x;
    long y;
};


int main()
{
    vector<struct Point> houses;
    
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        long X;
        long Y;
        cin >> X >> Y; cin.ignore();
        cerr<<"    "<<X<<" "<<Y<<endl;
        houses.push_back({X, Y});
    }
    
    sort(houses.begin(), houses.end(), [](const Point& a, const Point& b){ 
            return a.y < b.y; 
        });
    long cableY = houses[houses.size()/2].y;
    
    long cableLength = 0;
    long cableXStart=LONG_MAX, cableXEnd=LONG_MIN;
    for(auto& house : houses){
        if(house.x < cableXStart) cableXStart = house.x;
        if(house.x > cableXEnd)   cableXEnd = house.x;
        
        cableLength += abs(house.y - cableY);
    }
    cableLength += cableXEnd-cableXStart;

    cout << cableLength << endl;
}
