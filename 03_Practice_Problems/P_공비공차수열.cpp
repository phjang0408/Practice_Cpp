#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> common) {
    if(common[0] - common[1] == common[1] - common[2]){
        return common.back() + (common[1]-common[0]);
    }
    else{
        return common.back() * (common[1] / common[0]);
    }
}

int main(){
    vector<int> v = {1,2,3,4,5};
    vector<int> v2 = {2,4,8};
    cout << solution(v) << "and" << solution(v2) << endl;
}