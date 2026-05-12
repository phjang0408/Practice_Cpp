// 컨테이너 어댑터 - 1. 스택(stack)
// 함수 호출 관리, 임시 저장, 역순 처리, 재귀 알고리즘 등에 활용
#include <iostream>
#include <stack>

using namespace std;
int main() {
	stack<int> myStack;

	// 1. push - 삽입
	myStack.push(1);
	myStack.push(2);
	myStack.push(3);

	// 2. top - 원소 확인
	cout << "맨 위의 원소 : " << myStack.top() << endl;

	// 3. pop - 제거
	myStack.pop();
	cout << "제거 후 맨 위의 원소 : " << myStack.top() << endl;

	// 4. size - 확인(크기)
	cout << "스택 크기 : " << myStack.size() << endl;

	// 5. empty - 확인(비었는지)
	if (myStack.empty()) {
		cout << "스택이 비었습니다." << endl;
	}
	else {
		cout << "스택이 비어있지 않습니다." << endl;
	}
	return 0;
}