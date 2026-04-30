#include <iostream>
#include <string>
using namespace std;

// [요구사항] 부모 클래스 Vehicle 정의
class Vehicle {
protected:
	string name;			// 탈것 이름
	int max_speed;			// 최대 속도
	int current_speed;		// 현재 속도

public:
	// 생성자
	Vehicle(string n, int max_s) : name(n), max_speed(max_s), current_speed(0) {}

	// 정보 출력 메서드
	void print_info() {
		cout << "-> " << name << " | 최대 속도: " << max_speed
			 << " | 현재 속도: " << current_speed << endl;
	}

	// [요구사항] 가속 함수 (virtual로 자식 클래스에서 override)
	virtual void accelerate() = 0;

	// 정지 메서드
	void stop() {
		current_speed = 0;
	}

	// 소멸자
	virtual ~Vehicle() {}
};

// [요구사항] 자식 클래스 1: Car (가속 시 +20)
class Car : public Vehicle {
public:
	Car() : Vehicle("자동차", 200) {}

	// [요구사항] 자동차 가속: 현재 속도에 20 더하기
	void accelerate() override {
		current_speed += 20;
		if (current_speed > max_speed) {
			current_speed = max_speed;
		}
		cout << "[자동차] 엔진 가속: 현재 속도 " << current_speed << endl;
	}
};

// [요구사항] 자식 클래스 2: Bicycle (가속 시 +5)
class Bicycle : public Vehicle {
public:
	Bicycle() : Vehicle("자전거", 30) {}

	// [요구사항] 자전거 가속: 현재 속도에 5 더하기
	void accelerate() override {
		current_speed += 5;
		if (current_speed > max_speed) {
			current_speed = max_speed;
			cout << "[자전거] 페달 가속: 최대 속도 도달 (" << current_speed << ")" << endl;
		} else {
			cout << "[자전거] 페달 가속: 현재 속도 " << current_speed << endl;
		}
	}
};

// [요구사항] 자식 클래스 3: Airplane (가속 시 +100)
class Airplane : public Vehicle {
public:
	Airplane() : Vehicle("비행기", 900) {}

	// [요구사항] 비행기 가속: 현재 속도에 100 더하기
	void accelerate() override {
		current_speed += 100;
		if (current_speed > max_speed) {
			current_speed = max_speed;
		}
		cout << "[비행기] 엔진 풀파워 가속: 현재 속도 " << current_speed << endl;
	}
};

int main() {
	// [요구사항] Vehicle 포인터 배열[3], 각 탈것 객체 동적 생성
	Vehicle* vehicles[3];
	vehicles[0] = new Car();
	vehicles[1] = new Bicycle();
	vehicles[2] = new Airplane();

	cout << "===== 탈것 가속 테스트 =====" << endl;

	// [요구사항] 반복문으로 포인터 배열 순회, 가속 함수 3회씩 호출
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			vehicles[i]->accelerate();
		}
		vehicles[i]->print_info();
		cout << endl;
	}

	// [요구사항] 추가 테스트: Bicycle 4회 가속 (최대 속도 도달 확인)
	cout << "===== 가속 추가 테스트 =====" << endl;
	for (int i = 0; i < 4; i++) {
		vehicles[1]->accelerate();
	}
	vehicles[1]->print_info();

	// [요구사항] 동적 할당한 메모리 해제
	cout << endl << "메모리 해제 완료" << endl;
	for (int i = 0; i < 3; i++) {
		delete vehicles[i];
	}
	cout << "프로그램을 종료합니다." << endl;

	return 0;
}
