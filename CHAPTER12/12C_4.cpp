// 순차 컨테이너 - 2. 벡터
// 가변적, 동적, 빠르게 접근, 기본적으로 많이 사용
#include <iostream>
#include <vector>

using namespace std;

// [복습용] 벡터의 모든 원소 출력 템플릿
template <typename T>
void print_vector_all(vector<T>& vec) {
	cout << "벡터 내 원소 개수 : " << vec.size() << endl;
	// 반복자로 모든 원소 탐색
	for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl << "--------------------" << endl;
}

int main() {
	vector<int> vec1;					// 크기 미지정 선언
	vector<int> vec2(5);				// 크기(원소 개수) 5인 벡터 선언
	vector<int> vec3(5, 1);				// 크기 5, 모두 1로 초기화
	vector<int> vec4 = { 1,2,3,4,5 };	// 직접 초기화 (유니폼 초기화)

	print_vector_all(vec3);

	// 접근 및 추가
	vec4[1] = 10;
	vec4.at(1) = 20;	// at함수 사용
	vec4.push_back(5);	// 맨 뒤에 5 추가

	print_vector_all(vec4);

	/* insert와 erase - 특정 index에 삽입/삭제 - O(n) 소요
	 매개변수는 iterator(반복자)임.
	 따라서 insert(3, 25)나 erase(3)은 안 됨 (int형 != iterator 객체형) */
	 
	vec4.insert(vec4.begin() + 3, 25);	// vec[0+3] = vec[3] '앞'에 25추가
	vec4.erase(vec4.begin() + 3);		// vec[3]을 삭제

	print_vector_all(vec4);

	return 0;
}