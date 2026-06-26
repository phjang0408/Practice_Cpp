#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for(auto x : queries){
        swap(arr[x[0]],arr[x[1]]);
    }
    return arr;
}