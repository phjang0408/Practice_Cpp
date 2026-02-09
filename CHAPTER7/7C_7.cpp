// 오버로딩
// 이미 정의된 함수와 같은 이름을 사용, 매개변수 구성을 변경하며 새롭게 정의
#include <iostream>
using namespace std;

class character {
public:
	character() : location{ 0,0 } {
	};

	// 매개변수로 x, y 좌표를 전달받음
	void move(int x, int y) {
		location[0] = x;
		location[1] = y;
		cout << location[0] << ", " << location[1] << "로 이동" << endl;
	}

	// 매개변수로 x, y 배열과 배열 크기 전달받기
	void move(int x[], int y[], int spot_count) {
		for (int i = 0; i < spot_count; ++i) {
			location[0] = x[i];
			location[1] = y[i];
			cout << i + 1 << "번째 : " << location[0] << ", " << location[1] << "로  이동" << endl;
		}
	}

protected:
	int location[2];
};

int main() {
	character character_obj;
	int x_list[3] = { 10,15,20 };
	int y_list[3] = { 10,15,20 };

	character_obj.move(10, 10);
	cout << endl;
	character_obj.move(x_list, y_list, 3);

	return 0;
}