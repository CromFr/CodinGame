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
    int N; // the number of temperatures to analyse
    cin >> N; cin.ignore();
    string TEMPS; // the N temperatures expressed as integers ranging from -273 to 5526
    vector<int> temps;
    for(int i=0 ; i<N ; i++){
        int nTemp;
        cin>>nTemp;
        temps.push_back(nTemp);

        cerr<<nTemp<<" ";
    }cerr<<endl;
    
    //getline(cin, TEMPS);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    
    
    
    if(N==0)cout<<0<<endl;
    else{
        int nBestTemp = 10000;
        for(int t : temps){
            if(abs(t)<abs(nBestTemp))
                nBestTemp = t;
            else if(abs(t)==abs(nBestTemp) && t>nBestTemp)
                nBestTemp = t;
        }
        cout<<nBestTemp<<endl;
        
    }
}
