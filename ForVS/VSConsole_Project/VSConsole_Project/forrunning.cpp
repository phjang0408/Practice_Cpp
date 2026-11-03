#include <string>
#include <vector>

using namespace std;

int solution(int slice, int n) {
    int answer = 0;
    while (answer < n) {
        answer += slice;
    }
    return answer / slice;
}