#include <iostream>

using namespace std;

int value = 1; // 전역변수

int main()
{
    // 지역변수와 전역변수 접근하기
    int value = -1; // 지역변수
    cout << "[지역변수와 전역변수]" << endl;
    cout << "지역변수는 그대로 출력 : " << value << endl; // 지역변수 출력
    cout << "전역변수는 '::'를 앞에 붙여서 출력 : " << ::value << endl
         << endl; // 전역변수 출력

    // 형식 변환 두 가지
    // 1. 암시적 형 변환 - 컴파일러가 자동 변환
    float float_value = 1.5f;

    double double_value = float_value; // 숫자 승격 -> 데이터 유실 X
    int int_value = float_value;       // 숫자 변환 -> 데이터 유실 O

    cout << "[암시적 형 변환]" << endl;
    cout << "float_value : " << float_value << endl;
    cout << "double_value : " << double_value << endl;
    cout << "int_value : " << int_value << endl
         << endl;

    // 2. 명시적 형 변환 - 개발자가 직접 변환
    int int_a = 10;
    int int_b = 5;

    int int_avg = int_a + int_b;
    float float_avg_1 = (int_a + int_b) / 2;
    float float_avg_2 = float(int_a + int_b) / 2;

    cout << "[명시적 형 변환]" << endl;
    cout << "int_avg : " << int_avg << endl;
    cout << "float_avg_1 : " << float_avg_1 << endl;
    cout << "float_avg_2 : " << float_avg_2 << endl;
}
