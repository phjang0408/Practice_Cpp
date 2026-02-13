// string 라이브러리 - wstirng - 유니코드 문자열
#include <iostream>
#include <string>
using namespace std;

int main() {
	//프로그램 지역 설정
	setlocale(LC_ALL, "");	// LC_ALL은 모든 지역

	// 유니코드 문자열 초기화
	wstring korString = L"안녕하세요";

	// 유니코드 문자열 출력
	wcout << korString << endl;

	return 0;
}