// 템플릿 범용 클래스
#include <iostream>
using namespace std;

// 템플릿 선언
template <typename Type1, typename Type2>	
class data_package { // 클래스 정의 (템플릿 매개변수를 사용하는 것 외에는, 일반 클래스와 차이X)
public:
	data_package(Type1 first, Type2 second) : first(first), second(second){}
	void print_out_element() {
		cout << "첫 번째 요소 : " << first << ", 두 번째 요소 : " << second << endl;
	}
private:
	Type1 first;
	Type2 second;
};

// 부분 특수화 템플릿 - 특정 형식을 다르게 처리
template <typename T>
class data_package<string, T> {	// 부분 특수화 <string, T>로
public:
	data_package(string first, T second) : first(first), second(second){}
	void print_out_element() {
		cout << "부분 특수화는 " << first << "와 두 번째 요소는 : " << second << endl;
	}
private:
	string first;
	T second;
};

int main(){
	// 클래스 템플릿 객체 생성 -> 함수 템플릿과 다르게, 컴파일러가 데이터 형식 추론 X -> <>로 형식을 지정해야함
	data_package<int, double> template_inst1(5, 10.5);		// 형식 지정 <int, double>
	data_package<string, int> template_inst2("문자열", 10);	// 부분 특수화 적용

	// 확인
	template_inst1.print_out_element();
	template_inst2.print_out_element();

	return 0;
}