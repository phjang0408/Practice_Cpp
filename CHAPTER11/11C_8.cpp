// 11-4 기타 유용한 함수 - 난수
#include <iostream>
#include <random>
#include <chrono>	// 시간 기간 및 시간 인스턴스를, 나타내고 조작하는, 클래스와 함수 정의

using namespace std;

int main() {
	int seed = 5;
	srand(seed);		// 1. srand함수
	cout << "rand함수 : " << rand() << endl;		// 2. rand함수


	// <chrono>
	auto curTime = chrono::system_clock::now();
	auto duration = curTime.time_since_epoch();
	auto millis = chrono::duration_cast<chrono::milliseconds>(duration).count();

	mt19937_64 mt_rand(millis);	// 3. <random> 헤더파일에 있는 std::mt19937

	cout << "chrono와 random 헤더로 난수 생성" << endl;
	for (int i = 0; i < 10; i++) {
		cout << mt_rand() << endl;
	}

	random_device rng;	// 4. 하드웨어 엔트로피로 난수 생성하기
	cout << "엔트로피로 난수 생성" << endl;
	for (int i = 0; i < 10; i++) {
		auto result = rng();
		cout << result << endl;
	}
	return 0;
}