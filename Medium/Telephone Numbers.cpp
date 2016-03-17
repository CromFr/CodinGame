#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;



class Digit{
public:
    Digit(){
    }
    
    int add(list<int> numbers){
        if(numbers.empty())
            return 0;
        else{
            int size = 0;
            
            auto next = nextDigits.find(numbers.front());
            if(next==nextDigits.end()){
                size++;
                next = nextDigits.insert({numbers.front(), Digit()}).first;
            }
            
            numbers.pop_front();
            return size + next->second.add(numbers);
        }
    }
    
    map<int, Digit> nextDigits;
};




int main()
{
    Digit nb;
    int size = 0;
    
    
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string telephone;
        cin >> telephone; cin.ignore();
        
        list<int> number;
        for(auto& c : telephone)
            number.push_back(c-0x30);
        
        size += nb.add(number);
    }

    cout<<size<<endl;
}
