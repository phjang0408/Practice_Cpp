#include <iostream>
#include <thread>
#include <mutex>

int count = 0;
std::mutex mtx;	// 자물쇠역할 mutex, 전역변수로 하나 존재

void increment() {
	for (int i = 0; i < 10000; i++) {
		mtx.lock();		// 자물쇠 잠금
		count++;
		mtx.unlock();	// 자물쇠 해제
	}
}
int main() {
	std::thread t1(increment);
	std::thread t2(increment);

	t1.join();
	t2.join();

	std::cout << count;	// 올바르게 20,000이 나옴
	return 0;

	/*
	t1: lock() → count++ → unlock()
	t2: lock() 시도 → 대기... → t1 unlock()이 되면
		t2가 들어감 → lock() → count++ → unlock()

	=> 하지만, t1이 들어가서, '예외가 발생하면' t1.unlock()이 실행안됨!
	=> 그래서 나온 게 std::lock_guard
	*/
}