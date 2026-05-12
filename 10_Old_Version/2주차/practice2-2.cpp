#include <iostream>
//get 메소드 배워보기
int main() {
    char ch1, ch2;
    char buffer[10];

    std::cout << "get(ch) 사용 / 문자 하나 입력: ";
    std::cin.get(ch1);               // 문자 하나만 입력받음 (개행은 남겨둠)
    std::cout << "입력된 문자: " << ch1 << "\n";

    std::cout << "get() 사용 / 버퍼에 남은 문자 반환 : ";
    ch2 = std::cin.get();            // 다음 문자 확인 (엔터면 \n)
    std::cout << (ch2 == '\n' ? "\\n" : std::string(1, ch2)) << "\n";

    // ----------------------------

    std::cout << "\nget(buffer, size) 사용 / (size = 10)\n문자열 입력 : ";
    std::cin.get(buffer, 10);        // 최대 9자까지 문자열 입력받기 (\n은 남김)
    std::cout << "입력된 문자열: " << buffer << "\n";

    std::cin.get();                  // 남은 \n 제거 (버퍼 정리용)

    // ----------------------------

    std::cout << "\nget(buffer, size, delim) 사용 / (size = 10, delim = ' ')\n공백이 포함된 문자열 입력: ";
    std::cin.get(buffer, 10, ' ');   // 공백 전까지 입력, 공백은 버퍼에 남김
    std::cout << "공백 전까지 입력된 문자열: " << buffer << "\n";
}