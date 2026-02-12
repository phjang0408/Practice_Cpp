// 템플릿 기본
#include <iostream>
#include <string>
using namespace std;

// 함수 템플릿 선언과 정의
template <typename T>					// 템플릿 선언, T는 '템플릿 매개변수'
T data_sum(T operand1, T operand2) {	// 템플릿 정의
	return operand1 + operand2;
}
// 컴파일러는 '실제로 사용되는 타입'만 생성한다. 이걸 '템플릿의 인스턴스화'라고 한다

// 함수 템플릿의 특수화
template<>
double data_sum(double operand1, double operand2) {
	return (int)operand1 + (int)operand2;
}

int main() {
	int data1 = 3, data2 = 5;
	double data3 = 4.5, data4 = 8.9;
	string data5 = "Hello, ", data6 = "World!";

	cout << "정수형 데이터 합 : " << data_sum(data1, data2) << endl;
	cout << "실수형 데이터 합 : " << data_sum(data3, data4) << endl;	// 특수화 적용
	cout << "문자열 데이터 합 : " << data_sum(data5, data6) << endl;

	// 함수 템플릿의 명시적 호출
	char data7[] = "Hello, ", data8[] = "Char!";
	cout << "char배열 -> string으로 명시적 형 변환 : " << data_sum<string>(data7, data8) << endl;
}