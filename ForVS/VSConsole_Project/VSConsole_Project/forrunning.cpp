// 문제 2
// try, catch를 이용해 예외를 처리하고, 생략된 예외와 실패에 대응하는 코드
#include <iostream>

using namespace std;

void process(int value) {
	// value가 음수일 때 예외 던지기
	// 예외발생시 "예외 발생!" 출력, 발생하지 않으면 value 출력
	try {
		if (value < 0)	throw 1;
		cout << value << endl;
	}
	catch (int exec) {
		cout << "예외 발생!" << endl;
	}
	catch (...) {
		cout << "알 수 없는 오류 발생" << endl;
	}

}

int main() {
	process(10);
	process(-5);

	return 0;
}