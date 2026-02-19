// 순차 컨테이너 - 2.벡터
// 추가 - 정적 반복자와 리버스 반복자
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector <int> vec = { 10,20,30,40,50 };

	// 1. 정적 반복자 const_iterator
	// const_iterator는 'cbegin'과 'cend'함수로 얻을 수 있다.
	cout << "[정적 반복자 활용]" << endl;
	vector<int>::const_iterator const_it = vec.cbegin();	//cbegin함수
	cout << *const_it << endl;	
	
	++const_it;
	cout << *const_it << endl;

	const_it = vec.cend();		// cend함수
	--const_it;
	cout << *const_it << endl << endl;

	// 2.리버스 반복자
	// reverse_iterator는 'rbegin'과 'rend'함수로 얻을 수 있다.
	// rbegin은 가장 마지막 위치, 증가 연산은 '이전 위치' 
	// => 그냥 begin, end와 반대!, 연산 결과도 반대!
	cout << "[리버스 반복자 활용]" << endl;
	vector<int>::reverse_iterator rev_it = vec.rbegin();	// rbegin함수
	for (rev_it; rev_it != vec.rend(); rev_it++) {			// rend 함수
		cout << *rev_it << endl;
	}

	return 0;
}