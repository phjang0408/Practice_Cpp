#include <iostream>
//getline() 메소드 배워보기
int main() {
    char buffer1[100], buffer2[100];

    std::cout << "문자열을 입력: ";
    std::cin.getline(buffer1, 100); // 최대 99자
    std::cout << "입력받은 문자열은 " << buffer1 << "입니다." << "\n";

    //cin.ignore()없이 바로 다음 입력

    std::cout << "다음 문자열을 입력: ";
    std::cin.getline(buffer2, 100);
    std::cout << "두 번째 문자열은 " << buffer2 << "입니다.";
}