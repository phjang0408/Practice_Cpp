// 순차 컨테이너 - 4. 덱(deque)
// vector는 하나의 메모리 블록에 저장
// deque 컨테이너는 '여러 개의 메모리 블록을 나눠서 저장'
// 저장 공간이 부족하면, 일정 크기의 새로운 메모리 블럭을 만들어 연결. => '복사 저장' 발생하지 않음
#include <iostream>
#include <deque>

using namespace std;

int main() {
	deque<int> myDeque;	// 선언

	// 1. 추가
	myDeque.push_back(2);	// push_back
	myDeque.push_back(3);
	myDeque.push_front(1);	// push_front
	myDeque.push_front(0);

	// 출력
	cout << "리스트 출력 : ";
	for (const int& element : myDeque) {
		cout << element << " ";
	}
	cout << endl;

	// 2. 제거
	myDeque.pop_back();		// pop_back
	myDeque.pop_front();		// pop_front

	// 출력
	cout << "리스트 출력 : ";
	for (const int& element : myDeque) {
		cout << element << " ";
	}
	cout << endl;

	// 3. 확인
	cout << "리스트 크기 : " << myDeque.size() << endl;		// size (원소 개수)
	cout << "리스트가 비었는가 : " << myDeque.empty() << endl;	// empty (비었는지 확인)

	// 4. 접근
	cout << "deque 첫 번째 원소 : " << myDeque.front() << endl;
	cout << "deque 마지막 원소 : " << myDeque.back() << endl;

	return 0;
}