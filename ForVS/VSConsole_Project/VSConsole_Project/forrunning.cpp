#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> result;
    for (auto x : queries) {
        int inst = 1000000;
        if (x[2] >= x[1] || x[2] <= x[0]) {
            inst = -1;
            result.push_back(inst);
            continue;
        }

        for (int i = x[0]; i <= x[1]; i++) {
            if (arr[i] > x[2] && arr[i] < inst){
                inst = arr[i];
            }
        }
        if (inst == 1000000) {
            inst = -1;
        }
        result.push_back(inst);
    }
    return result;
}