// constexpr 함수 -> 컴파일 타임에, [상수인 객체]를 만드는 함수
#include <iostream>
using namespace std;

// constexpr가 붙어서, Factorial의 반환값은 [컴파일]타임에 [상수] 가 됨.
constexpr int Factorial(int n) {
	int total = 1;
	for (int i = 1; i <= n; i++) {
		total *= i;
	}
	return total;
}
template <int N>
struct A {
	int operator()() { return N; }
};
int main() {
	A<Factorial(10)> a;	
	// 템플릿 인자는 상수식이 들어가야 함.
	// 이때, Factorial(10)가 컴파일 타임에 계산되고, 
	// 런타임에는 상수처럼 취급
	cout << a() << endl;
}