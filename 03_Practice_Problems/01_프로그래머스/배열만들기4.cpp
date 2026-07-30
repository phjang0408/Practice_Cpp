#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    for (int x : arr) {
        if (stk.empty() || *(stk.end() - 1) < x) {
            stk.push_back(x);
        }
        else if (*(stk.end() - 1) >= x) {
            stk.pop_back();
        }
    }
    return stk;
}