// 사용자 정의 자료형 - enum - C++에서 정의되지 않은, 자신만의 자료형을 만드는 기능
#include <iostream>
using namespace std;

// 1. Color라는 새로운 자료형을 정의한다, 메모리 할당은 X
enum Color {
	// 열거자(enumerator)
	// 각 열거자는 쉼표(,)로 구분된다

	COLOR_BLACK,			// 3. 각 열거자는 열거 목록의 위치에 따라 '정수 값'이 할당, 여기는 0
	COLOR_WHITE,			// '직접 할당'은 이전값 
	COLOR_BLUE,				
	COLOR_GREEN,
	COLOR_CYAN,
	COLOR_YELLOW,
	COLOR_RED = 6,			// 4. 명시적 할당도 가능하다
};	// 끝은 항상 세미콜론

// 2. 열거형 Color의 변수를 정의, 여기서 메모리 할당
Color paint = COLOR_WHITE;
Color sky(COLOR_WHITE);

int main() {
	//5. 열거형 값은 정수로 평가되어, 출력 및 할당도 가능하다.
	std::cout << "COLOR_BLACK : " << COLOR_BLACK << endl;
	int a = COLOR_RED;
	std::cout << "COLOR_RED : " << COLOR_RED << endl;


	// 6. 열거형으로 입력받기 - int형으로 입력받은 뒤, 열거 타입으로 '강제 형 변환'하는 방식
	int Color_Num;
	Color InputColor;
	std::cout << "색상 번호를 입력하세요." << endl;
	std::cin >> Color_Num;	// int로 입력받고

	if(Color_Num>=COLOR_BLACK && Color_Num <= COLOR_RED){
		InputColor = static_cast<Color>(Color_Num); // 강제 형변환
		cout << "입력된 색상 번호는 : " << InputColor << endl;
		// 열거자의 이름으로 출력하고 싶다면, switch문이나, 문자열 배열을 index로 출력하면 된다.
	}
	else {
		cout << "잘못된 색상 번호 입니다." << endl;
	}
}