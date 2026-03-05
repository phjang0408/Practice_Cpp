// 3. find
// first!last 범위에서 value와 일치하는 [첫 번째 원소]의 [반복자] 반환
// 찾지 못하면 last 반환
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class my_class {
public:
	int value;
	string name;
	bool operator==(const my_class& other) const {
		return value == other.value && name == other.name;
	}
};
int main() {
	vector<int> numbers = { 7,2,5,1,8,9,3,6,4 };

	cout << "찾을 숫자 : ";
	int target;
	cin >> target;

	// 1. find 함수
	vector<int>::iterator it = find(numbers.begin(), numbers.end(), target);
	if (it != numbers.end()) {
		cout << "위치한 index : " << distance(numbers.begin(), it) << '\n';
	}
	else {
		cout << "찾을 수 없음" << '\n';
	}
	// 2. find는 operator==을 사용하기에
    // 사용자 정의 타입 객체를 비교하려면, 연산자 오버로딩
	vector<my_class> objects = {
		{1,"one"},
		{2,"two"},
		{3,"three"}
	};

	vector<my_class>::iterator target_class;
	target_class = find(objects.begin(), objects.end(), my_class{ 3,"three" });

	if (target_class != objects.end()) {
		cout << "객체 타입 지정 : " << distance(objects.begin(), target_class) << '\n';
	}
	else {
		cout << "찾을 수 없음" << '\n';
	}


	return 0;
}