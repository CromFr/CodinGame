#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

double toRad(double deg){
    return 3.141592 * deg / 360.0;   
}
double GetDistSq(double lon, double lat, double userlon, double userlat){
    double x = toRad(userlon - lon) * cos(toRad(lat+userlat)/2.0);
    double y = toRad(userlat - lat);
    return x*x + y*y;
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string LON;
    cin >> LON; cin.ignore();
    string LAT;
    cin >> LAT; cin.ignore();
    
    LON[LON.find(',')] = '.';
    LAT[LAT.find(',')] = '.';
    long double userlon = stod(LON);
    long double userlat = stod(LAT);
    
    double bestDist = 10000000000000000;
    string bestName;
    
    
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        /*string DEFIB;
        getline(cin, DEFIB);*/
        
        string _, name, lats, lons;
        
        getline(cin, _, ';');//id
        getline(cin, name, ';');
        getline(cin, _, ';');//addr
        getline(cin, _, ';');//tel
        getline(cin, lons, ';');//lon
        getline(cin, lats);//lat
        
        lons[lons.find(',')] = '.';
        lats[lats.find(',')] = '.';
        
        double dist = GetDistSq(userlon, userlat, stod(lons), stod(lats));
        if(dist<bestDist){
            bestName = name;
            bestDist = dist;
        }
        
        cerr<<name<<"=>"<<stod(lons)<<":"<<stod(lats)<<"\t\t"<<dist<<endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    cerr<<"BEST= "<<bestName<<"\t\t"<<bestDist<<endl;
    cout << bestName << endl;
}
