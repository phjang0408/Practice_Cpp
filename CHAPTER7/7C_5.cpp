// 추가 - 깊은복사
#include <iostream>

class MyBuffer {
public:
	int* data;
	int size;

	//생성자
	MyBuffer(int s) : size(s) {
		data = new int[size];	// 동적 할당
		for (int i = 0; i < size; i++) {
			data[i] = i + 1;
		}
	}

	// 깊은 복사
	MyBuffer(const MyBuffer& other) : size(other.size) {
		// 새로운 메모리 확보
		data = new int[size];

		// 루프돌며 하나씩 복사
		for (int i = 0; i < size; i++) {
			data[i] = other.data[i];
		}

		std::cout << "깊은 복사 완료" << std::endl;
	}

	~MyBuffer() {
		delete[] data;
	}
};

int main() {
	MyBuffer obj1(5);
	MyBuffer obj2 = obj1;

	std::cout << "obj1 주소 : " << obj1.data << std::endl;
	std::cout << "obj1 주소 : " << obj2.data << std::endl;
}