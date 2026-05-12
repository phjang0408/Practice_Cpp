// 템플릿 매개변수 기본값
#include <iostream>
using namespace std;

template <typename T = int>	// 기본 형식을 int로 설정
class data_package {
public:
	data_package(T first):first(first){}
	void print_out_element() {
		cout << "템플릿 매개변수 값 : " << first << endl;
	}
private:
	T first;
};

int main(){
	data_package<> template_inst1(5);	// 기본 형식으로 객체 생성
	data_package<string> template_inst2("기본형이 아닌, 다른 형태도 가능!");

	template_inst1.print_out_element();
	template_inst2.print_out_element();

	return 0;
}