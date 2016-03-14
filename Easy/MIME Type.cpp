#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    map<string, string> mimeTypes;

    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();

        for(auto& c : EXT) c = toupper(c);

    	mimeTypes.insert(pair<string,string>(EXT, MT));
    }
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);

        auto found = FNAME.rfind(".");
        if(found!=string::npos){
            string ext = FNAME.substr(found+1, string::npos);
            for(auto& c : ext) c = toupper(c);

            auto search = mimeTypes.find(ext);
            if(search != mimeTypes.end()){
                cout<<search->second<<endl;
            }
            else{
                cout<<"UNKNOWN"<<endl;
            }
        }
        else{
            cout<<"UNKNOWN"<<endl;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    //cout << "UNKNOWN" << endl; // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
}
