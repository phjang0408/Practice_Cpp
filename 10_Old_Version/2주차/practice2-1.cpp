#include <iostream>
// c 기본방식
int main() {
	char name[100];
	std::cout << "당신의 이름은 : ";
	std::cin >> name;
	std::cout << name << "님 환영합니다!";
}