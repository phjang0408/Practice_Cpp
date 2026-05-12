#include <iostream>
//ignore()메소드 배워보기
int main() {
    char ch;

    // 예시 1: cin.ignore() - 문자 하나만 clear
    std::cout << "ignore() 사용 / 아무 문자 하나 입력 후 엔터: ";
    std::cin.get(ch); // 첫 글자만 받아서 ch에 저장
    std::cout << "첫 문자: " << ch << "\n";

    std::cin.ignore(); // 버퍼에 남은 '\n' 하나만 제거
    std::cout << "나머지 문자 없이 바로 출력됨 (엔터 제거 완료)\n\n";


    // 예시 2: cin.ignore(n) - n개의 문자 clear
    std::cout << "ignore(n) 사용 / 최소 5(= n)글자 이상 입력: ";
    std::cin.ignore(5); // 처음부터 5문자 clear

    std::cin.get(ch); // 6번째 문자 읽기
    std::cout << "6번째 문자: " << ch << "\n\n";


    // 예시 3: cin.ignore(n, delim) - delim 전까지 clear
    std::cout << "ignore(n,delim) 사용 / 'x' 전까지 읽을 문자열 입력: ";
    std::cin.ignore(100, 'x'); // 최대 100개, 또는 'x'가 나올 때까지 무시

    std::cin.get(ch); // 'x' 다음 문자 읽기
    std::cout << "'x' 다음 문자: " << ch << "\n";

    return 0;
}