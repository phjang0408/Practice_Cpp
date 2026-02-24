// this 포인터
// 객체가 자기 자신에게 접근하는 방법
#include <iostream>

class Rectangle {
	int width, height;	// 접근 지정자 안 붙임 -> 'private' 디폴트
public:
	void set(int width, int height) {
		//'this' 포인터는 '멤버 함수 내부'에서만 가능.
		this->width = width;
		this->height = height;
	}
	void print() {
		// this-> 사용 하지 않아도, 묵시적으로 작동. 하지만 가독성을 위해 명시하는 게 좋음.
		std::cout << "width : " << this->width << " height : " << this->height << std::endl;
	}
};

int main() {
	Rectangle table;
	table.set(20, 50);
	table.print();
}