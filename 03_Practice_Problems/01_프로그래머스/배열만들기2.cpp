#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    for (int i = l; i <= r; i++) {
        if (i % 5 != 0)    continue;    // 5단위로 끊기
        int temp = i;                   // [!] 반복용 i를 수정하려면 따로 담아야지 
        bool correct = true;

        while (temp > 0) {
            int c = temp % 10;          // 굳이 문자로 할 필요 없음, 근데 하면 char c = '0' + temp % 10; // 굳이 형 변환함수까지는 좀
            if (c != 0 && c != 5) {     // 조건문 잘 확인하기. 0과 5가 둘 다 아니어야하니까 &&
                correct = false;
                break;
            }
            temp /= 10;
        }
        if (correct) answer.push_back(i);
    }

    if (answer.empty())  answer.push_back(-1);  // size조사대신, 그냥 empty쓰는게 깔끔

    return answer;
}