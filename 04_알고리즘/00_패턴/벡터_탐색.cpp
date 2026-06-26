#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v = {10,40,20,30,20,30,30,10,40};
    // [1] 정렬되지 않은 벡터
    // 1. find : 정렬되지 않은 벡터에서, 값 찾기 : O(N)
    auto it = find(v.begin(),v.end(),30);   // 찾으면 해당 위치 반복자, 없으면 end()반복자

    if(it != v.end()){
        cout << "값 : " << *it
        << " 인덱스 : " << it - v.begin() << endl;
    }

    // 2. count, count_if : 개수 세기 : O(N)
    int cnt = count(v.begin(), v.end(), 20);
    int cnt_if = count_if(v.begin(), v.end(), [](int x){
        return x >= 30;
    });
    cout << "count : " << cnt << " count_if : " << cnt_if << endl;

    // [2] 정렬된 벡터
    sort(v.begin(),v.end());    // 오름차순을 기본으로, 아니면 마지막 인자로 비교 함수(정렬기준)를 넣어야 함.

    // 1. upper_bound : target < x인 x 중 가장 처음 값. 반복자로 반환, O(log N)
    auto upb = upper_bound(v.begin(),v.end(),20); 

    // 2. lower_bound : target <= x인 x 중 가장 처음 값. 반복자로 반환, O(log N)
    auto lpb = lower_bound(v.begin(), v.end(), 20);

    // 3. binary_search : target이 존재하는 지 TF만 반환. O(log N)
    bool bns = binary_search(v.begin(), v.end(), 20);
    return 0;
}