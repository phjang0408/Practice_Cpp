#include <iostream>
using namespace std;
/*
    C스타일의 매크로 함수도 "코드를 자리에 복사"하는 방식이다.
    하지만 매크로 함수는 "단순 치환"이므로, 인자에 대한 '타입 검사'가 없어 위험하다

    따라서, inline 함수의 장점은 다음과 같다.
    - 타입 검사를 함
    - 인자가 한 번만 계산됨
    - 디버거로 따라갈 수 있음
    - 네임스페이스와 접근 제어(private 등)를 지킴
*/
#define SQUARE(x) ((x) * (x))

inline int Square(int x) { return x * x; }

int main()
{
    int i = 3;
    int a = SQUARE(i++);  // ((i++) * (i++)) 로 바뀜 -> i가 두 번 증가, 정의되지 않은 동작
    
    int j = 3;
    int b = Square(j++);  // 정상: j는 한 번만 증가, b = 9
}