#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int main() {
	int command;			// 사용자가 입력할 권한
	int permission = 0;		// 최종 권한값
	int mask = 1;			// 포함여부 판별용 
	string names[4] = {		// 권한 목록
		"읽기 권한",
		"쓰기 권한",
		"실행 권한",
		"삭제 권한"
	};

	cout << "권한 설정 (1:읽기, 2:쓰기, 4:실행, 8:삭제, 0:설정 완료)" << endl;
	while (true) {
		cout << "권한 입력: ";
		cin >> command;
		if (command == 0)	break;

		permission |= command;
	}
	cout << "[권한 판별 결과]" << endl;
	for (int i = 0; i < 4; i++) {
		cout << names[i] << ": " << std::boolalpha <<
			((permission & mask) != 0) << endl;
		mask <<= 1;
	}
	cout << "권한 값: " << permission << " (" << bitset<8>(permission) << ")" << endl;

	return 0;
}