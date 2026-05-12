// 프렌드 키워드 - 클래스와 함수
#include <iostream>
using namespace std;

// 프랜드 클래스는 'friend'키워드로 지정되기 전에, 먼저 선언과 정의가 되어있어야 함.
template<typename U>
class caller {
public:
	caller() : object(nullptr) {}
	void set_object(U* obj_pointer) { object = obj_pointer; }
	void printout_friend_object() {
		cout << "(friend 클래스 템플릿 호출) 템플릿 매개변수 값 : "
			<< object->first << endl;	// friend 클래스의 private 볌위 참조
	}
private:
	U* object;
};

template<typename T = int>
class data_package {
public:
	data_package(T first) : first(first) {}
	friend caller<data_package>;	// caller 클래스를 프렌드로 지정(caller에게는 공개하겠다)

	// 클래스 템플릿에 'friend 함수' 정의 - 내부
	friend void printout_friend_element_inside(data_package<T>& data_object) {
		cout << "(friend 함수로 호출 - 내부) 템플릿 매개변수 값 : "
			<< data_object.first << endl;
	}

	// friend 함수 정의 - 외부
	template<typename C>
	friend void printout_friend_element_outside(C& data_object);	// 선언만 내부
private:
	T first;
};

// 프렌드 함수 정의 - 외부
template <typename C>
void printout_friend_element_outside(C& data_object) {
	cout << "(friend 함수로 호출 - 외부) 템플릿 매개변수 값 : "
		<< data_object.first << endl;
}

int main() {
	// 프랜드 클래스 생성
	caller<data_package<>> caller_int_obj;
	caller<data_package<string>> caller_string_obj;

	data_package<>	data_package_int_obj(5);
	data_package<string> data_package_string_obj("기본값이 아닌, string 형");

	// 프랜드 클래스의 private 변수 참조
	caller_int_obj.set_object(&data_package_int_obj);
	caller_string_obj.set_object(&data_package_string_obj);
	// 성공 여부 확인
	caller_int_obj.printout_friend_object();
	caller_string_obj.printout_friend_object();

	// friend 함수는 '전역 함수'라서, 객체 없이 호출이 가능하다.
	// 내부에서 정의된 함수 호출
	printout_friend_element_inside(data_package_int_obj);
	printout_friend_element_inside(data_package_string_obj);
	// 외부에서 정의된 함수 호출
	printout_friend_element_outside(data_package_int_obj);
	printout_friend_element_outside(data_package_string_obj);

	return 0;
}