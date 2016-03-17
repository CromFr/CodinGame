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
    list<int> neighbour;
};
vector<Node> nodes;

using Path = vector<int>;

Path GetShortestPath(int startNodeIndex){
    
    bool visitedNodes[nodes.size()] = {false};
    int nodesStrength[nodes.size()] = {0};
    
    vector<Path> paths;
    paths.push_back(Path(1, startNodeIndex));
    visitedNodes[startNodeIndex] = true;
        
    vector<Path> pathsNextIter;
    
    
    vector<Path> endingPaths;
    
    bool unvisitedNodesFound;
    do{
        pathsNextIter.clear();
        unvisitedNodesFound=false;
        
        cerr<<"ITERATION"<<endl;
        for(auto& path : paths){
            cerr<<"From: ";
            for(auto n : path)
                cerr<<n<<" ";
            cerr<<endl;
            
            
            for(int nearNodeIndex : nodes[path.back()].neighbour){
                cerr<<"    Looking at "<<nearNodeIndex<<"\t";
                if(nodes[nearNodeIndex].isGateway){
                    //Register path~nearNodeIndex in endingPaths
                    cerr<<"Gateway";
                    nodesStrength[path.back()]++;
                    
                    auto endingPath(path);
                    endingPath.push_back(nearNodeIndex);
                    endingPaths.push_back(endingPath);
                }
                else if(visitedNodes[nearNodeIndex]==false){
                    //Add a new path
                    cerr<<"unvisited node";
                    unvisitedNodesFound = true;
                    
                    visitedNodes[nearNodeIndex] = true;
                    
                    //mark path for iteration
                    auto newPath(path);
                    newPath.push_back(nearNodeIndex);
                    
                    pathsNextIter.push_back(newPath);
                }
                else{
                    //abandon path (there is a faster path)
                    cerr<<"already visited";
                }
                cerr<<endl;
            }
            
        }
        paths = pathsNextIter;
        cerr<<"        ===> "<<pathsNextIter.size()<<" paths to be explored"<<endl;
            
    }while(unvisitedNodesFound);//There should always be a path found
    
    //Return found paths if they leads to a gateway
    auto endingPathsSize = endingPaths.size();
    if(endingPathsSize>0){
        cerr<<endingPathsSize<<" paths found:"<<endl;
        
        if(endingPathsSize==1)
            return endingPaths[0];
        else{
            //Find path connected with the most gateways
                        
            Path* bestPath = nullptr;
            int bestPathStrength;
            for(auto& path : endingPaths){
                
                cerr<<"  \t";
                int strength = 0;
                strength -= path.size()-1;
                for(auto nodeIndex : path){
                    cerr<<nodeIndex<<":"<<nodesStrength[nodeIndex]<<"\t";
                    strength += nodesStrength[nodeIndex];
                }
                cerr<<"\t\t("<<strength<<")"<<endl;
                
                
                if(    bestPath==nullptr
                    || strength > bestPathStrength
                    ){
                    bestPath = &path;
                    bestPathStrength = strength;
                }
            }
            return *bestPath;
        }
    }
    else
        cerr<<"OUCH IT HURTZ"<<endl;
}




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
        
        
        int from = path[path.size()-2];
        int to = path[path.size()-1];
        
        nodes[from].neighbour.remove(to);
        nodes[to].neighbour.remove(from);
        
        cout<<from<<" "<<to<<endl;
        

    }
}
