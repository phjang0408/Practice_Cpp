#include <iostream>
#include <string>
// string 객체의 getline() 메소드 배워보기
int main() {
    std::string input;

    std::cout << "C++ string 문자열 입력: ";
    std::getline(std::cin, input);  // 한 줄 전체를 읽어서 input에 저장

    std::cout << "입력된 문자열: " << input << std::endl;

    return 0;
}