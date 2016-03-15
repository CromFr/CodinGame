#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<long> data;
    
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        long v;
        cin >> v; cin.ignore();
        data.push_back(v);
    }
    
    long maxloss = 0;
    
    long max=data.front()-1;
    for(int from=0 ; from<n ; from++){
        if(data[from]>max){
            max = data[from];
            for(int to=from+1 ; to<n ; to++){
                if(data[to]-max < maxloss)
                    maxloss = data[to]-max;
            }
            
        }
    }



    cout << maxloss << endl;
}
