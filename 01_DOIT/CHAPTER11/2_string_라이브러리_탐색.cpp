// string 라이브러리 - 탐색 find()
#include <iostream>
#include <string>
using namespace std;

void check_found(string::size_type n) {
	if (n == string::npos) {	// 문자열을 못 찾으면 반환하는 상수
		cout << "Not found!" << endl;
	}
	else {
		cout << "found index: " << n << endl;
	}
}

int main() {
	string::size_type n;	// 문자열의 크기를 나타내는 형식
	string str = "This is an example of a standard string.";

	// 문자열 시작부터 example 탐색
	n = str.find("example");	// 찾으면 index 반환, 못 찾으면 string::npos 반환
	check_found(n);

	// index 위치 4부터 "is" 탐색
	n = str.find("is", 4);
	check_found(n);

	// 문자 하나 탐색
	n = str.find('k');
	check_found(n);

	return 0;
}