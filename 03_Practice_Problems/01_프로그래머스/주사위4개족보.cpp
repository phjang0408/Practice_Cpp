#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d)
{
    vector<int> num = {a, b, c, d};
    sort(num.begin(), num.end());

    // 4개 동일
    if (num[0] == num[3])
    {
        return 1111 * num[0];
    }

    // 3개 동일
    if (num[0] == num[2])
    {
        return (10 * num[0] + num[3]) * (10 * num[0] + num[3]);
    }

    // 2개 - 2개
    if (num[1] == num[3])
    {
        return (10 * num[1] + num[0]) * (10 * num[1] + num[0]);
    }

    // 2 - 1 - 1 개
    if(num[0] == num[1] && num[2] == num[3]){
        return (num[0] + num[2]) * (num[2] - num[0]);
    }

    if(num[0] == num[1]){
        return num[2] * num[3];
    }
    else if(num[1] == num[2]){

        return num[0] * num[3];
    }
    else if(num[2] == num[3]){
        return num[0] * num[1];
    }

    // 전부 다름
    return num[0];
}