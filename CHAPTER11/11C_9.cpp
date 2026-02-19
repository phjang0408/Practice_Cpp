// 11-4 기타 유용한 함수 - 수학 함수
#include <iostream>
#include <cmath>	// 수학 '함수' 제공 (sin, cos, sqrt, pow 등)
#include <numbers>	// 수학 '상수' 제공 (pi, e, sqrt2 등, c++20 부터 사용 가능)

using namespace std;

int main() {
	double x = 2;
	double y = 3;
	cout << "x = " << x << ", y = " << y << endl;
	cout << "pow(x,y) = " << pow(x, y) << endl;		// 거듭제곱
	cout << "sqrt(x) = " << sqrt(x) << endl;		// 제곱근
	cout << "log(x) = " << log(x) << endl << endl;	// 자연 로그

	x = 2.847;
	y = -3.234;
	cout << "x = " << x << ", y = " << y << endl;
	cout << "ceil(x) = " << ceil(x) << ", ceil(y) = " << ceil(y) << endl;		// 올림
	cout << "floor(x) = " << floor(x) << ", floor(y) = " << floor(y) << endl;	// 내림
	cout << "round(x) = " << round(x) << ", ceil(y) = " << round(y) << endl;	// 반올림
	cout << "abs(x) = " << abs(x) << ", abs(y) = " << abs(y) << endl << endl;			// 절댓값

	cout << "PI = " << numbers::pi << endl;
	cout << "cos(PI/3)" << cos(numbers::pi / 3) << endl;

	return 0;
}