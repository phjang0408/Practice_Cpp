#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main(){
    vector<string> s = {"r c", "r c", "r c"};
    for(auto x : s){cout << x << endl;}
    cout << endl;
    
    unique(s.begin(), s.end());
    for(auto x : s){cout << x << endl;}
    return 0;
}