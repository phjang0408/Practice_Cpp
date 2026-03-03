// constexpr 생성자 -> 컴파일 타임에, [상수인 객체]를 만드는 함수
// class에서는, constexpr [생성자]로 만든 객체의, constexpr [멤버 함수]만이 constexpr이다.
#include <iostream>
using namespace std;

class Vector {
public:
	constexpr Vector(int x, int y) : x_(x),y_(y){}

	constexpr int x() const { return x_; }
	constexpr int y() const { return y_; }
private:
	int x_;
	int y_;
};

constexpr Vector AddVec(const Vector& v1, const Vector& v2) {
	return { v1.x() + v2.x(), v1.y() + v2.y() };
}

template <int N>
struct A {
	int operator()() { return N; }
};

int main() {
	constexpr Vector v1{ 1,2 };
	constexpr Vector v2{ 2,3 };

	// constexpr 객체의 constexpr 멤버 함수도 constexpr
	A<v1.x()> a;	
	cout << a() << endl;

	// AddVec가 반환하는 Vec도, constexpr를 반환한다.
	A<AddVec(v1, v2).x()> b;
	cout << b() << endl;
}