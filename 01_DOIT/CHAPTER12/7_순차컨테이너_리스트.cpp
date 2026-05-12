// 순차 컨테이너 - 3. 리스트
// 이중 연결 리스트 구조
// 데이터가 '노드'라 불리는 개별 객체(다음 노드를 가리키는 포인터를 포함)
// 삽입/삭제에 효율적{O(1)}, 탐색은 비효율적{O(n)} - 순차적으로 노드를 타고 가기에
#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> myList;	// 선언

	// 1. 추가
	myList.push_back(2);	// push_back
	myList.push_back(3);
	myList.push_front(1);	// push_front
	myList.push_front(0);
	
	// 출력
	cout << "리스트 출력 : ";
	for (const int& element : myList) {
		cout << element << " ";
	}
	cout << endl;

	// 2. 제거
	myList.pop_back();		// pop_back
	myList.pop_front();		// pop_front

	// 출력
	cout << "리스트 출력 : ";
	for (const int& element : myList) {
		cout << element << " ";
	}
	cout << endl;

	// 3. 확인
	cout << "리스트 크기 : " << myList.size() << endl;		// size (원소 개수)
	cout << "리스트가 비었는가 : " << myList.empty() << endl;	// empty (비었는지 확인)

	return 0;
}