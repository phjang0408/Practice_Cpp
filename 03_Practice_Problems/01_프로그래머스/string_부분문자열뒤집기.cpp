#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(string my_string, vector<vector<int>> queries) {
    for(vector<int> x : queries){
        cout << x[0] << "  " << x[1] << endl;
        reverse(my_string.begin() + x[0], my_string.begin() + x[1] + 1);
        cout << "mystr = " << my_string << endl<<endl;
    }
    return my_string;
}

int main(){
    vector<vector<int>> q = {{2, 3}, {0, 7}, {5, 9}, {6, 10}};
    solution("rermgorpsam",q);
    return 0;
}