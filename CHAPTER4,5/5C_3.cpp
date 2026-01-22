// noexcept로 명시된 함수에서 예외 던지기
#include <iostream>
#include <cstdlib> // exit 함수 포함

using namespace std;

void Foofunc() noexcept; // 이 함수는 예외를 던지지 않는다고 약속
void real_noexcept() noexcept
{
	cout << "real_noexcept func" << endl;
}

// noexcept로 명시된 함수에서, 예외 발생
void fake_noexcept() noexcept 
{
	cout << "fake_noexcept func" << endl;
	throw 1; // 일부러 예외 발생시키기 -> 경고 발생
}

// 종료 처리 함수 set_terminate
void myterminate() {
	cout << "myterminate called!" << endl;
	exit(-1);	// -1이면 비정상, 0이면 정상 종료
}

int main() {
	set_terminate(myterminate);	// 종료함수 지정

	bool does_not_throw = noexcept(Foofunc());	// 함수가 예외를 던지는지 확인
	cout << does_not_throw << "<- 1이면 'true' (noexcept가 설정됨)" << endl;
	real_noexcept();

	try {
		fake_noexcept();
	}
	catch (int exec) {
		cout << "catch " << exec << endl;
	}

	return 0;
}