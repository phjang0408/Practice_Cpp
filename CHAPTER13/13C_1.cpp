// 
#include <iostream>
using namespace std;

// auto + decltype
// 반환값의 형식이 : auto 이면, '후행반환형식'으로 decltype를 지정해야 한다.
template <typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {	// 타입을 알고자 하는 식 : a + b
	return a + b;
}

int main() {
	// 1. auto : 컴파일러가 타입을 추론, 반복자, 람다, 템플릿에 사용
	// 함수에서 매개변수의 형식 지정자, 구조체나 클래스의 멤버 변수는 X
	auto a = 10;		// int
	auto b = 3.14;		// double
	auto c = a + b;		// double

	// 2. decltype : 식의 타입을 그대로 가져옴, 함수 반환 타입, 템플릿 정확한 형식
	int x = 10;
	decltype(x) a = 20;		// x의 형식인 int로 a를 초기화
	decltype((x)) b = x;	// int& 형식, lvalue이면 참조형으로
	
}