// 연관 컨테이너 - 1. 세트(set)
// 데이터 빠른 저장 및 검색에 유용 (O(logn)이나 O(1))
// 중복값 허용하지 않음
#include <iostream>
#include <set>

using namespace std;
int main() {
	set<int> mySet;

	// 값 삽입
	mySet.insert(5);
	mySet.insert(8);
	mySet.insert(2);

	// 검색 - 확인
	// find로 검색, 해당 값이 없으면, set::end를 반환함
	if (mySet.find(5) != mySet.end()) {
		cout << "5는 저장되지 않음" << endl;
	}

	// 검색 - 순회
	for (auto it = mySet.begin(); it != mySet.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;

	// 크기
	int size = mySet.size();
	cout << "크기는  : " << size << endl;

	return 0;
}