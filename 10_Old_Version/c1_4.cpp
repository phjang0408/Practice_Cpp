#include <iostream>
// 참조자에 대하여 p.35
int main(){
    // 1. 여러가지 참조자
    int x;
    int &y = x;
    int &z = y;

    x = 1;
    std::cout << "x : " << x << ", y = " << y << ", z = " << z << std::endl;
    
    y = 2;
    std::cout << "x : " << x << ", y = " << y << ", z = " << z << std::endl;
    
    z = 3;
    std::cout << "x : " << x << ", y = " << y << ", z = " << z << std::endl;
    /* 출력
        x : 1, y = 1, z = 1
        x : 2, y = 2, z = 2
        x : 3, y = 3, z = 3
        이와 같이, 참조자는 '별명'처럼 생각하면 된다.
    */

    // 2. 상수 참조자
    const int &ref = 4;
    int a = ref;

    std::cout << a << std::endl;
}