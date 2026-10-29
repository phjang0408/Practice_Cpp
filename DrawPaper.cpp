#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> nums = {6, 3, 1, 4, 2};
    sort(nums.begin(), nums.end());

    for(int x : nums){
        if(x%2==0){cout << x << " ";}
    }
    return 0;
}