#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    for (auto x : queries) {
        int k = 0;
        for (int i = x[0]; i <= x[1]; i++) {
            if (i % x[2] == 0) {
                arr[i]++;
            }
        }
    }
    return arr;
}