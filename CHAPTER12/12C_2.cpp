// 복사 (copy 함수)
#include <iostream>
#include <vector>
#include <algorithm>	// copy 정의
// 깊은 복사를 반복문으로 구현하면, 코드가 길고 오래걸림. 이를 보완하고자 'copy' 함수.
// 범위 내의 원소들을, 다른 컨테이너나 배열, 벡터로 복사할 때 사용
// 구문 : std::copy(input_begin, input_end, output_begin);

using namespace std;

int main() {
	// 원본 벡터
	vector<int> src = { 1,2,3,4,5 };

	// 타겟 벡터
	vector<int> target(src.size());	// 크기를 맞춰야 함

	// 깊은 복사 수행
	copy(src.begin(), src.end(), target.begin());

	// 결과 출력
	cout << "src : ";
	for (int v : src) { cout << v << " "; }
	cout << endl;

	cout << "target : ";
	for (int v : target) { cout << v << " "; }
	cout << endl;

	return 0;
}