// switch문
#include <iostream>
using namespace std;

int main() {
	int input_number;
	cout << "Enter number(1~5) : ";
	cin >> input_number;

	switch (input_number) {
	case 1:
		cout << "입력한 수는 1입니다." << endl;
		break; // break 생략 시, default까지 or 다음 break까지 아래 구문들을 전체 실행
	case 2:
		cout << "입력한 수는 2입니다." << endl;
		break;
	case 3:
		cout << "입력한 수는 3입니다." << endl;
		break;
	case 4:
		cout << "입력한 수는 4입니다." << endl;
		break;
	case 5:
		cout << "입력한 수는 5입니다." << endl;
		break;

	default:
		cout << "입력한 수는 범위 밖입니다." << endl;
	}
	return 0;
}