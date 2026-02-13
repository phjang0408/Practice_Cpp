// string 라이브러리 - 비교 '연산자'
#include <iostream>
#include <string>
using namespace std;

int main() {
	// 같을 때,
	string s1 = "Hello";
	string s2 = "Hello";
	if (s1 == s2) {
		cout << "두 문자열 일치" << endl;
	}

	// s1이 더 짧을 때
	s2 = "Hello World!";
	if (s1 != s2) {
		cout << "두 문자열 불일치" << endl;
	}
	if (s1 < s2) {
		cout << "s2가 더 길다" << endl;
	}
	return 0;
}