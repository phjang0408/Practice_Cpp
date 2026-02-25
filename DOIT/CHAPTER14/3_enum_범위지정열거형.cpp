// enum 추가
#include <iostream>
using namespace std;

// 1. 범위 지정 열거형 - enum 다음 'class'나 'struct'를 사용하면 '범위 지정 열거형'
enum class Color : char {	// 열거형 데이터 형식 지정 : 'char'
	COLOR_BLACK = 'B',
	COLOR_WHITE = 'W',
	COLOR_RED = 'R',
	COLOR_BLUE				// '값 없음'으로 초기화
};

// struct와 class의 차이 없음
enum struct Paint {
	COLOR_BLACK,
	COLOR_WHITE,
	COLOR_RED,
	COLOR_BLUE
};

int main() {
	// 2. 열거형 변수에 열거형 값 대입
	Color myColor = Color::COLOR_BLACK;
	cout << "myColor : " << static_cast<char>(myColor) << endl;

	// 3. 명시적 형 변환
	int val = static_cast<int>(myColor);
	cout << "static_cast 후 myColor : " << static_cast<int>(myColor) << endl;

	// enum class는 타입 안정성을 위해 자동 변환을 막아두었음
	// 따라서, cout로 출력하려면, '명시적 형 변환'을 해주어야 함.
}