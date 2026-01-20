#include <iostream>
//참조자

int main(){
    int a = 5;
    int& reference_a = a;

    reference_a = 12345;
    std::cout << "a = " << a << std::endl;
    std::cout << "reference_a = " << reference_a << std::endl;

    /* 
    참조자의 규칙 1. 반드시 누구의 별명인지 명시해야 함.
        ex) int& reference_a; <- 이와 같이 명시하지 않으면 불가능!

    참조자의 규칙 2. 한 번 참조하면, 변경 불가능
        ex) int a = 10;
            int &reference_a = a; <= 'a'를 참조하도록 명시하면,

            int b = 20;
            reference_a = b; <= 'b'를 참조하도록 변경 X / a에 b값을 대입하게 됨

    참조자의 규칙 3. 메모리 상에 공간 할당 X
    => 참조자의 자리는, 자기가 가리키는 자리로 변경됨
    */
}