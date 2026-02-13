// string 라이브러리 - 기본
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str1("hello");	// 생성자 호출로 초기화
	string str2 = "Hello";	// 대입 연산자로 초기화

	char strc[] = "Hello";	// 저수준의 char형(기본형) 배열, 끝에 '\0'인 Null 문자가 붙음

	cout << str1 << endl;
	cout << str2[0] << endl;

	// 길이 구하기
	cout << str1.length() << endl;	// 문자열의 길이 반환 - length
	cout << str1.size() << endl;	// 객체가 차지하는 메모리 크기 반환 - size

	// 검사하기
	cout << std::boolalpha;			// 논리형 값 -> 알파벳 형식
	cout << str1.empty() << endl;	// 비었으면 1(true), 있으면 0(false)

	// 추가하기
	str1.append(" World!");
	cout << str1 << endl;
	str2.append(" World@", 6, 1);	// 추가할 문자열, 추가 시작할 인덱스(여기서 @), 추가할 개수
	cout << str2 << endl;
}