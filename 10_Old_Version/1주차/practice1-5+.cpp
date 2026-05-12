#include <iostream>

// 5. using을 이용한 이름공간의 명시
using std::cin;
// 이후부터 cin은 std::cin을 의미한다는 선언
using std::cout;
using std::endl;

// 똑같은 활용이 가능한 아래 코드
// using namespace std;
// -> std라는 이름공간을 선언 없이 접근하겠다는 뜻

// 6. 이름공간의 별칭
namespace AAA
{
    namespace BBB
    {
        namespace CCC
        {
            int num1;
            int num2;
        }

    } // namespace BBB

}

namespace ABC = AAA::BBB::CCC;
// AAA::BBB::CCC에 대해서, ABC라는 '별칭'지정

// 7. 전역변수
int val = 1000;

int main()
{
    cout << "이름공간 사용하기" << endl;

    int num;
    cout << "입력도 받아보기 : ";
    cin >> num;
    cout << "입력값 : " << num << endl;

    // 6. 별칭
    ABC::num1 = 10;
    ABC::num2 = 20;
    cout << ABC::num1 + ABC::num2 << endl;

    // 지역변수와 전역변수
    int val = 20; // 지역변수
    val += 3;     // 지역변수 값 증가
    ::val += 7;   // 전역변수 값 증가

    cout << "지역변수 val의 값 : " << val << endl;
    cout << "전역변수 val의 값 : " << ::val << endl;
}