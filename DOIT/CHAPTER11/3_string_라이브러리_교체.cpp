// string 라이브러리 - 교체 'replace'
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "Hello, World!";
	cout << "Original string : " << str << endl;

	//문자열 일부분 교체
	str.replace(7, 5, "C++");	// 교체 시작 index, 삭제할 길이, 삽입할 문자열

	cout << "Replaced string : " << str << endl;


	//find 함수와 함께 사용하는 replace
	string text = "The C++ programming language is one of the hardest languages";
	
	// 1. 찾을 문자열과 교체할 문자열 정의
	string target = "hardest";
	string replacement = "most powerful";

	// 2. 등장 위치 찾기
	size_t pos = text.find(target);	//size_t 타입 상수 : 문자열 존재 여부를 나타내는 상수

	// 3. 교체
	if (pos != string::npos) {	//string::npos는 못 찾은 경우의 상수, npos가 '!='아니면 교체
		text.replace(pos, target.length(), replacement);
		cout << "교체 후 문장 : " << text << endl;
	}
	else {
		cout << target << "을 찾을 수 없음" << endl;
	}

	// 번외 static const size_t npos = -1;
	return 0;
}