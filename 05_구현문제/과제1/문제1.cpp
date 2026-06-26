#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
	int command;			// 사용자 입력 권한
	int permission = 0;		// 누적 권한값 (비트 OR 연산)
	int mask = 1;			// 권한 판별용 마스크 (1, 2, 4, 8)
	string names[4] = {		// 권한 이름 배열
		"읽기 권한",
		"쓰기 권한",
		"실행 권한",
		"삭제 권한"
	};

	cout << "권한 설정 (1:읽기, 2:쓰기, 4:실행, 8:삭제, 0:설정 완료)" << endl;
	// [요구사항] 반복 입력하여 비트 OR로 권한 누적
	while (true) {
		cout << "권한 입력: ";
		cin >> command;
		if (command == 0)	break;

		permission |= command; // 비트 OR로 권한 누적
	}
	cout << "[권한 판별 결과]" << endl;
	// [요구사항] 비트 AND 연산으로 각 권한 포함 여부 판별, bool로 명시적 형 변환
	for (int i = 0; i < 4; i++) {
		cout << names[i] << ": " << std::boolalpha <<
			(bool)((permission & mask) != 0) << endl; // 명시적 형 변환 (bool)
		mask <<= 1; // 마스크 좌측 시프트로, 권한 판별
	}
	// [요구사항] 10진수와 2진수(bitset<8>)로 최종 권한값 출력
	cout << "권한 값: " << permission << " (" << bitset<8>(permission) << ")" << endl;

	return 0;
}