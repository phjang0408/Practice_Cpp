// static : 정적 변수
#include <iostream>
using namespace std;

void func() {
	int a = 10;
	static int b = 10;

	a++;
	b++;

	cout << "a : " << a << ", b : " << b << endl;
}

int main() {
	func();
	func();
	func();
	func();
	func();
}

/* a는 지역변수, b는 전역변수로 지정되었다.
그래서 func가 종료되면, a는 사라지지만, b는 func가 종료되어도 사라지지 않는다

의문점은 func()마다 b가 10으로 매번 초기화 될 거 같지만,
'정적변수는 처음 호출 될 때만 초기화 된다.'
그리고 그 값은 프로그램이 종료될 때 까지 지속된다.

나아가 수명 주기가 서로 다른 이유는
'메모리의 위치'가 다르기 때문이다.

지역변수는 메모리 구조에서 '스택'에 저장되고,
정적변수는 메모리 구조에서 '데이터 영역(힙)'에 저장된다.
*/