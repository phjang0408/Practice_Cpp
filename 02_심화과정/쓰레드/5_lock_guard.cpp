#include <iostream>
#include <thread>
#include <mutex>

int count = 0;
std::mutex mtx;	// mutex : mtx

void increment() {
	for (int i = 0; i < 10000; i++) {
		std::lock_guard<std::mutex> lock(mtx);
		// lock_guard 객체 생성, 생성되는 순간, mtx.lock() 자동호출

		count++;
	}	// 객체 소멸되는 순간, mtx.unlock() 자동호출
}
int main() {
	std::thread t1(increment);
	std::thread t2(increment);

	t1.join();
	t2.join();

	std::cout << count;	// 올바르게 20,000이 나옴
	return 0;

	/* "스택 언와인딩"
	* C++은, 예외가 발생하면, 지금 스코프 지역변수 소멸자 전부 호출
	* -> 상위 스코프로 예외 전파
	* -> 전파받은 스코프에서, 지역변수 소멸자 전부 호출
	* -> catch를 만날 때 까지 반복...
	*/
}