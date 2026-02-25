// C++에는 두 가지 상수가 있다. => 리터럴(literal)과 심볼릭(symbolic)
// 리터럴(literal)은 코드에 직접 삽입된 값이다. 
// 이 값은 변경할 수 없는 '상수'이다.
#include <iostream>
using namespace std;

int main() {
	// 1. 기본 리터럴
	bool myBool = true;				// 부울 리터럴 true가 할당
	int myInt = 5;					// int 리터럴 5가 할당
	std::cout << 2 * 3 << '\n';		// 2와 3은 정수 리터럴

	// 2. 부동 소수점 리터럴
	double pi = 3.14;				// 기본형
	double avoga = 6.02e23;			// 지수형 (6.02 * 10^23)
	double elec = 1.6e-19;			// 지수형 (1.6 * 10^-19) 음수

	// 3. 접미사 - 대소문자 상관없음
	unsigned int myUnsigned = 5u;	// u = unsigned int
	float myFloat = 5.0f;			// f = float
	long myLong = 5l;				// l = long

	// 4. 문자 리터럴
	char c = 'A';
	std::cout << "hello world" << '\n';

	// 5. 8진수 - 리터럴 앞에 '0'을 붙이면 된다.
	int my8 = 012;					// 8진수로 10 (8 + 2)
	cout << my8 << '\n';

	// 6. 16진수 - 리터럴 앞에 '0x'를 붙이면 된다.
	int my16 = 0xF;					// 16진수로 16( = F)
	cout << my16 << '\n';

	return 0;
}