// 4. const_cast
// [포인터나 참조자]의, const/volatile 속성 추가 및 제거 기능
// 그러나 원래 객체가 const라면, 수정 시 정의되지 않은 동작을 할 수 있음
// API 연결, const 오버로드 구현할 때, 제한적으로 사용
#include <iostream>
using namespace std;

void ModifyValue(int* p) {
	*p = 50;
}

int main() {
	int value = 10;
	const int* constPtr = &value;

	// 1. const 제거 - 포인터나 참조자의 const 속성
	int* nonConstPtr = const_cast<int*>(constPtr);	//const int* -> int*
	ModifyValue(nonConstPtr);						// const가 제거되면, 값이 변경됨
	cout << "const_cast 후, 지정 값을 변경 : " << value << endl;

	// 2. 객체 const라면
	const int realConst = 100;
	int* dangerous = const_cast<int*>(&realConst);	// const 객체를 제거는 안 됨
	// *dangerous = 200;	// 정의되지 않은 동작-절대 금지

	return 0;
}