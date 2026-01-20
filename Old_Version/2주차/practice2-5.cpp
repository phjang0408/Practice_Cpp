#include <iostream>
#include <string>
//string 객체 cin 방식
int main() {
	std::string st = "Hello!"; // st라는 string 객체
	std::cout << st << std::endl;

	std::cout << "cin 방식 사용 / 다음 문자열을 말해주세요 : ";
	std::cin >> st;
	std::cout << "저장된 문자열 : " << st << "\n" << "(cin)방식은 공백을 기준으로 끊는다.";
}