#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;


class Node{
public:
    Node(int i){
        index = i;   
    }
    
    int index;
    bool isGateway = false;
    vector<int> neighbour;
};
vector<Node> nodes;

using Path = vector<int>;

Path GetShortestPath(int startNodeIndex){
    
    bool visitedNodes[nodes.size()] = {false};
    
    list<Path> paths;
    paths.push_back(Path(1, startNodeIndex));
    vector<Path> pathsToBeAdded;
    
    
    do{
        cerr<<"ITERATION"<<endl;
        for(auto& path : paths){
            cerr<<"From: ";
            for(auto n : path)
                cerr<<n<<" ";
            cerr<<endl;
            
            
            for(int nearNodeIndex : nodes[path.back()].neighbour){
                cerr<<"    Looking at "<<nearNodeIndex<<endl;
                
                if(visitedNodes[nearNodeIndex]==false){
                    visitedNodes[nearNodeIndex] = true;
                    
                    if(nodes[nearNodeIndex].isGateway){
                        //return path~nearNodeIndex
                        path.push_back(nearNodeIndex);
                        return path;
                    }
                    else{
                        //mark path for iteration
                        auto newPath = path;
                        newPath.push_back(nearNodeIndex);
                        pathsToBeAdded.push_back(newPath);
                    }
                }
                else{
                    //abandon path (there is a faster path)
                }
                
            }
            
        }
        for(auto& path : pathsToBeAdded)
            paths.push_back(path);
            
    }while(1);//There should always be a path found
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
    
    for(int i=0 ; i<N ; i++)
        nodes.push_back(Node(i));
    
    
    for (int i = 0; i < L; i++) {
        int N1; // N1 and N2 defines a link between these nodes
        int N2;
        cin >> N1 >> N2; cin.ignore();
        
        nodes[N1].neighbour.push_back(N2);
        nodes[N2].neighbour.push_back(N1);
    }
    for (int i = 0; i < E; i++) {
        int EI; // the index of a gateway node
        cin >> EI; cin.ignore();
        
        nodes[EI].isGateway = true;
    }

    // game loop
    while (1) {
        int SI; // The index of the node on which the Skynet agent is positioned this turn
        cin >> SI; cin.ignore();
        
        auto path = GetShortestPath(SI);
        
        cerr<<"Shortest path: ";
        for(auto n : path)
            cerr<<n<<" ";
        cerr<<endl;
        
        cout<<path[0]<<" "<<path[1]<<endl;
        

    }
}
