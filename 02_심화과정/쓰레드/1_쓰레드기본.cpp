#include <iostream>
#include <thread>

void worker() {
	std::cout << "워커 스레드 실행\n";
}

void greet(std::string name) {
	std::cout << "안녕 " << name << '\n';
}

int main() {
	// 1. 기본 스레드 생성 - std::thread 이름()
	std::thread t(worker);			// 생성과 동시에 실행 시작
	t.join();						// 끝날때까지 기다림

	// 2. join v.s. detach
	// join은 끝날때까지 대기, detach는 따로 실행
	

	// 3. 인자전달
	std::thread t2(greet, "지욱"); 	// 인자는, 함수 뒤에 나열하는 형식
	t2.detach();

	// 4. 람다식
	std::thread t3([]() {
		std::cout << "람다 스레드\n";
		});
	t3.join();
	
	return 0;
}