#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex mtx1;
mutex mtx2;

void thread1() {
	std::lock_guard<std::mutex> lock1(mtx1);	// lock1은 mtx1관리
	std::this_thread::sleep_for(std::chrono::milliseconds(100));	//데드락 재현용
	
	lock_guard<mutex> lock2(mtx2);
	cout << "thread1 완료\n";
}

void thread2() {
	lock_guard<mutex> lock2(mtx2);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));	//데드락 재현용

	lock_guard<mutex> lock1(mtx1);
	cout << "thread2 완료\n";
}

int main() {
	thread t1(thread1);
	thread t2(thread2);
	t1.join();
	t2.join();

	// 해결방법
	// 1. 잠금 순서 통일 : 모든 스레드가 순서를 통일시킨ㅌ다.
	// 2. std::lock(mtx1, mtx2)처럼 동시에 잠그기
	// 3. std::scoped_lock 사용하기

	return 0;
}