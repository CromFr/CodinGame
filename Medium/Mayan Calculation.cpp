#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using Numeral = vector<string>;
vector<Numeral> digits;

int getDigitValue(Numeral& digit){
    for(int i=0 ; i<digits.size() ; i++){
        bool match = true;
        for(int j=0 ; j<digit.size() ; j++){
            if(digit[j] != digits[i][j]){
                match = false;
                break;
            }
        }
        if(match)
            return i;
    }
    cerr<<"Block did not match any digit"<<endl;
    return -1;//no match, sould not happen
}

long long getNumberValue(Numeral& number){
    int digitHeight = digits[0].size();
    int digitCount = number.size()/digitHeight;
    
    long long sum = 0;
    for(int i=0 ; i<digitCount ; i++){
        Numeral num;
        for(int j=0 ; j<digitHeight ; j++)
            num.push_back(number[(digitCount-1-i)*digitHeight+j]);
                
        sum += getDigitValue(num) * pow(20, i);
    }
    
    return sum;
}

int main()
{
    
    digits.resize(20);
    
    Numeral a, b;
    
    
    int L;
    int H;
    cin >> L >> H; cin.ignore();
    for (int i = 0; i < H; i++) {
        string line;
        cin >> line;
        cin.ignore();
        
        for(int j=0 ; j<20 ; j++){
            digits[j].push_back(line.substr(j*L, L));
        }
    }
    int S1;
    cin >> S1; cin.ignore();
    for (int i = 0; i < S1; i++) {
        string num1Line;
        cin >> num1Line; cin.ignore();
        a.push_back(num1Line);
    }
    int S2;
    cin >> S2; cin.ignore();
    for (int i = 0; i < S2; i++) {
        string num2Line;
        cin >> num2Line; cin.ignore();
        b.push_back(num2Line);
    }
    string operation;
    cin >> operation; cin.ignore();
    
    
    long long aInt = getNumberValue(a),
        bInt = getNumberValue(b);
    
    long long result;
    if(operation=="*")      result=aInt*bInt;
    else if(operation=="/") result=aInt/bInt;
    else if(operation=="+") result=aInt+bInt;
    else if(operation=="-") result=aInt-bInt;
    
    cerr<<getNumberValue(a)<<operation<<getNumberValue(b)<<" = "<<result<<endl;
    
    vector<int> base20digits;
    if(result==0)
        base20digits.push_back(0);
    else{
        
        long long multiplier = 1;
        while(multiplier<result){
            multiplier *= 20;
        }
        
        while(multiplier>1){
            multiplier /= 20;
            
            int digit = result/multiplier;
            result %= multiplier;
            
            base20digits.push_back(digit);
        }
    }
    
    cerr<<"==========> ";
    for(auto& d : base20digits)
        cerr<<d<<" ";
    cerr<<endl;
    
    for(auto d : base20digits){
        for(auto& l : digits[d]){
            cout<<l<<endl;
        }
    }
    
    
    
}
