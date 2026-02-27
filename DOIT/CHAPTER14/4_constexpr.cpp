// 상수 지정자 - constexpr
// const -> 런타임에 값이 결정, constexpr -> 컴파일 시점에 값이 결정
// [상수식] : 컴파일 타임에, 값이 결정되는 식 + [정수상수식] = 정수인 상수식
#include <iostream>
using namespace std;

template <int N>
struct A {
	int operator()() { return N; }
};

int main() {
	// 1. constexpr와 const의 차이점

	int a = 1;
	// Do Something..
	const int b = a;		// 런타임 중에서, a값에 따라 b가 결정
	
	int ce_a = 1;
	// Do Something..
	constexpr int ce_b = ce_a;	// 컴파일에서, a값은 알 수 없어서, b 결정 X => [빌드오류]

	// 2. 정수 상수식으로의 활용법
	constexpr int size = 3;
	int arr[size];	// 2.1 배열의 크기

	constexpr int N = 10;
	A<N> Str;		// 2.2 템플릿 인자

	constexpr int number = 3;
	enum B {
		x = number,	// 2.3 enum 값 지정
		y,
		z
	};
	cout << B::x << '\n';	// 출력 : 3
}