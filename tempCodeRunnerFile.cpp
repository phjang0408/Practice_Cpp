#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 구간합이 m의 배수 : 각 구간 합의 차도 m의 배수
    // (prefix[j] - prefix[i]) % m == 0
    // → prefix[j] % m == prefix[i] % m
    // 구간합 -> 1 3 6 7 9
    // 나머지 -> 1 0 0 1 0
    vector<long long> cnt(m, 0); // index = 나머지, index의 값 = 등장횟수
    cnt[0] = 1;                  // prefix sum[0] = 0이므로, 나머지 0이 1개 존재

    long long part_sum = 0, answer = 0;
    for (int i = 0; i < n; i++)
    {
        int call;
        cin >> call;
        part_sum += call;

        int r = part_sum % m;

        // 이전에 나머지가 r인 prefix sum이 cnt[r]개 있었다면,
        // 그 각각과 현재 위치가 쌍을 이루어 m의 배수 구간이 됨
        answer += cnt[r];
        cnt[r]++;
    }

    cout << answer;
    return 0;
}