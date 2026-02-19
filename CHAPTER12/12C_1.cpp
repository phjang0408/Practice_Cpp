// 12-1 컨테이너와 반복자
#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 1. vector 컨테이너 기초
	std::vector<int> v;
	for (int i = 1; i < 5; i++) {
		v.push_back(i);	// vector 원소 추가 : push_back()
	}
	for (int i = 0; i < v.size(); i++) {	// size함수로 크기 반환
		cout << v[i];	// 배열처럼 접근
	}
	cout << endl;

	// 2. 반복자
	vector<int> vec;	// vector 컨테이너 선언

	vec.push_back(0);	// vec에 원소 추가 : push_back()
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	std::vector<int>::iterator it = vec.begin();	// 반복자 it 선언, vec 시작 위치로 초기화
	cout << *it;
	cout << *(it + 1) << endl;	// 반복자를 포인터와 같이, 역참조 연산자 '*' 사용

	// 반복자를 이용한 순회
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it;
	}
	// [포인트] end 함수는 '컨테이너'에 저장된, 마지막 원소의 '바로 다음 위치'를 반환한다
	// 맨 마지막 원소를 지나친 'past-the-end' 반복자 라고 부른다.
    
	return 0;
}