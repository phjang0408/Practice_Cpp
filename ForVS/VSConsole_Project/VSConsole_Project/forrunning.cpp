#include <iostream>
using namespace std;

class class_object {
public:
	class_object() {
		cout << "메모리 할당 완료" << endl;
	};

	~class_object() {
		cout << "메모리 해제 완료" << endl;
	};

	void print_out() {
		cout << "객체의 함수를 호출" << endl;
	}
};

int main() {

	unique_ptr<class_object> Its_Unique(new class_object());
	Its_Unique->print_out();

	auto Use_make_unique = make_unique<class_object>();

	return 0;
}