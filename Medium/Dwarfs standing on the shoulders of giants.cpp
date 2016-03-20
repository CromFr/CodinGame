#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person{
public:
    Person(){}
    Person(int _id) : id(_id){}
    int id;
    
    vector<int> influences;
    bool influencedBySomeone = false;
};

map<int, Person> people;

int countLonguestChain(int from){
    
    int chainLength = 0;
    for(auto& p : people[from].influences){
        auto length = countLonguestChain(p);
        if(length>chainLength)
            chainLength = length;
    }
    return chainLength+1;//current node counts
}

int main()
{
    int n; // the number of relationships of influence
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int x; // a relationship of influence between two people (x influences y)
        int y;
        cin >> x >> y; cin.ignore();
        
        if(people.find(x)==people.end()){
            people.insert({x, Person(x)});
        }
        
        if(people.find(y)==people.end())
            people.insert({y, Person(y)});
            
        people[x].influences.push_back(y);
        people[y].influencedBySomeone =  true;
    }
    
    vector<int> leaders;
    for(auto& p : people){
        if(!p.second.influencedBySomeone){
            cerr<<"leader: "<<p.first<<endl;
            leaders.push_back(p.first);
        }
    }
    
    int max = 0;
    for(auto l : leaders){
        int chainLength = countLonguestChain(l);
        max = chainLength>max? chainLength : max;
    }

    cout << max << endl; // The number of people involved in the longest succession of influences
}
