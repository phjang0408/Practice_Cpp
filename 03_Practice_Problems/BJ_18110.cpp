#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, user_ipt;
    double sum = 0;
    cin >> n;
    // n이 0일때
    if (n == 0)
    {
        cout << "0";
        return 0;
    }
    // 절삭평균을 위해 제외할 개수
    int real_n = round(n * 0.15);

    vector<int> levels;
    for (int i = 0; i < n; i++)
    {
        cin >> user_ipt;
        levels.push_back(user_ipt);
    }

    // 정렬
    std::sort(levels.begin(), levels.end());

    // 절삭평균 구하기위한 합 구하기
    // erase로 앞 뒤 삭제도 가능
    for (auto x = real_n; x < levels.size() - real_n; x++)
    {
        sum += levels[x];
    }
    // 합으로 평균치내기
    cout << round(sum / (n - 2 * real_n)); // erase였으면, sum / levels.size()
    return 0;
}