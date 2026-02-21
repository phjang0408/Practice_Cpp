// 컨테이너 어댑터 - 2. 큐(quieue)
// 내부적으로 deque(덱) 사용
//  순차적 이벤트 처리, 너비 우선 탐색, 캐시 구현, 멀티스레딩 동기화
#include <iostream>
#include <queue>
using namespace std;
int main() {
	queue<int> myQueue;

	// 1. push - 삽입
	myQueue.push(1);
	myQueue.push(2);
	myQueue.push(3);

	// 2. front, back - 조회
	cout << "큐의 맨 앞 : " << myQueue.front() << endl;
	cout << "큐의 맨 뒤 : " << myQueue.back() << endl;

	// 3. pop - 삭제
	myQueue.pop();

	cout << "pop후의 큐의 맨 앞 : " << myQueue.front() << endl;
	cout << "pop후의 큐의 맨 뒤 : " << myQueue.back() << endl;

	// 4. empty, size
	cout << "queue의 크기 : " << myQueue.size() << endl;
	cout << "큐가 비었나요? : " << (myQueue.empty() ? "yes" : "No") << endl;

	return 0;
}