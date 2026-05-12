#include <iostream>
/* 1-2 함수 오버로딩
매개변수 선언이 다르다면, 서로 다른 함수로 정의된다.
자료형이 다르거나, 개수가 다르면 가능하다.
다만, '반환형의 차이'는 불가능하다.(void, int등)*/

void MyFunc(int num)
{
    std::cout << "매개 변수가 하나인 경우 : " << num << std::endl;
}
void MyFunc(int num1, int num2)
{
    std::cout << "매개 변수가 둘 인 경우 : " << num1 << " " << num2 << std::endl;
}
int MyFunc(char ch)
{
    std::cout << "매개 변수가 문자인 경우 : " << ch << std::endl;
    return 0;
}
int main()
{
    MyFunc(10);
    MyFunc(10, 20);
    MyFunc('c');
}