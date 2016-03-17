#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    
    vector<int> list;
    
    for (int i = 0; i < N; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        
        list.push_back(Pi);
    }
    
    int minDist = 100000000;//int.max?
    
    /* Too complex
    int baseIndex=0, floatIndex=1;
    int length = list.size();
    for(; baseIndex<length ; baseIndex++){
        
        for(floatIndex=baseIndex+1; floatIndex<length ; floatIndex++){
            int dist = abs(list[floatIndex] - list[baseIndex]);
            if(dist<minDist)
                minDist = dist;
        }
    }
    */
    
    sort(list.begin(), list.end());
    for(int i=0 ; i<list.size()-1 ; i++){
        int dist = abs(list[i] - list[i+1]);
        if(dist<minDist)
            minDist = dist;
    }
        
    
    

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << minDist << endl;
}
