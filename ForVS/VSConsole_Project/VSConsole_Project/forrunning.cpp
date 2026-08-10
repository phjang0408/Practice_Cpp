#include <iostream>

using namespace std;

class class_object {
public:
	class_object() {
		cout << "메모리 할당" << endl;
	}
	~class_object() {
		cout << "메모리 해제" << endl;
	}
	void print_out() {
		cout << "객체의 함수 호출" << endl;
	}
};

int main() {
	// 기존 힙 생성 방식 : delete하지 않으면 메모리 누수!
	class_object* heap_pointer = new class_object();	
	
	// 스마트 포인터 [unique_ptr] 사용 : delete하지 않아도, 자동으로 소멸자 호출
	unique_ptr<class_object> unique_pointer(new class_object());

	// make_unique 함수로 unique_ptr 스마트 포인터 생성하기 (auto키워드 추가로 간결하게)
	auto unique_ponter = make_unique<class_object>();

	return 0;
}