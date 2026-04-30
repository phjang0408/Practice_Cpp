#include <iostream>
using namespace std;

int main() {
	int start, end;
	int count = 0; // 출력된 곱셈 결과 개수
	bool validInput = false;

	// [요구사항] do-while으로 유효 입력받기 (2~9, start <= end)
	do {
		validInput = true;
		cout << "시작 단 입력: ";
		cin >> start;
		cout << "끝 단 입력: ";
		cin >> end;

		// start > end 체크
		if (start > end) {
			cout << "잘못된 입력입니다." << endl;
			validInput = false;
		}

		// 범위 체크 (2 이상 9 이하)
		if ((start < 2 || start > 9) || (end < 2 || end > 9)) {
			cout << "단의 범위는 2 이상 9 이하입니다." << endl;
			validInput = false;
		}
	} while (!validInput);

	// [요구사항] 각 단 출력 (홀수 결과만, 50 초과 시 중단)
	for (int dan = start; dan <= end; dan++) {
		cout << "[" << dan << "단] (홀수 결과만, 50 초과 시 중단)" << endl;
		bool stopDan = false;

		for (int i = 1; i <= 9; i++) {
			int result = dan * i;

			// [요구사항] 50 초과 시 해당 단 중단
			if (result > 50) {
				cout << "-> " << dan << "단 중단 (50 초과)" << endl;
				stopDan = true;
				break; // break로 현재 단 종료
			}

			// [요구사항] continue로 홀수 결과만 출력
			if (result % 2 == 0) {
				continue; // 짝수는 건너뛰기
			}

			cout << dan << " x " << i << " = " << result << endl;
			count++; // 출력 개수 증가
		}

		// 50 초과로 중단되지 않은 경우 메시지 출력
		if (!stopDan && (dan * 9) > 50) {
			cout << "-> " << dan << "단 중단 (50 초과)" << endl;
		}
	}

	// [요구사항] 출력된 곱셈 결과 총 개수 출력
	cout << "출력된 곱셈 결과 총 개수: " << count << endl;

	return 0;
}
