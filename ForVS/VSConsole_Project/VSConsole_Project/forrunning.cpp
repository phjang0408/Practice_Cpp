#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void PrintVector(const string& title, const vector<T>& v) {
	cout << "[" << title << "]" << '\n';
	for (auto x : v)	cout << x << " ";
	cout << '\n';
}
template <typename U>
typename vector<U>::iterator MyUniqueFunc(vector<U>& vec) {
	auto first = vec.begin(), result = vec.begin(), last = vec.end();

	if (vec.empty())	return vec.begin();
	while (++first != last) {
		if (*first != *result) {
			*(++result) = *first;
		}
	}
	return ++result;
}

int main() {
	vector<int> parent_vec = { 10, 10, 20, 30, 20, 10, 10 };
	vector<int> myUnique = parent_vec;
	vector<int> stdUnique = parent_vec;

	// 내가 만든 유니크함수
	sort(myUnique.begin(), myUnique.end());
	auto new_end = MyUniqueFunc(myUnique);		// 새로운 끝을 반환

	myUnique.erase(new_end, myUnique.end());	// 새로운 끝을 토대로 삭제
	PrintVector("내가 만든 유니크", myUnique);

	// std::unique함수
	sort(stdUnique.begin(), stdUnique.end());
	stdUnique.erase(unique(stdUnique.begin(), stdUnique.end()),stdUnique.end());

	PrintVector("std::unique", stdUnique);

	return 0;
}