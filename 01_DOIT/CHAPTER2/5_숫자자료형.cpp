#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	// 맨 뒤에 float는 f, long double은 l, 없으면 double형태
	float float_value = 9.87654321f;
	double double_value = 9.87654321987654321;
	long double long_double_value = 9.87654321987654321l;

	//std::setprecision(std::numeric_limits<데이터 형식>::digits10 + 1
	//setprecision은 cout에서 출력되는 정밀도를 조절하는 함수

	// 1. float
	cout << "float : " << sizeof(float) << " bytes" << endl;
	cout << "float_value : " <<
		setprecision(numeric_limits<float>::digits10 + 1) <<
		float_value << endl << endl;

	// 2. double
	cout << "double : " << sizeof(double) << " bytes" << endl;
	cout << "double_value : " <<
		setprecision(numeric_limits<double>::digits10 + 1) <<
		double_value << endl << endl;

	// 3. long double
	cout << "long double : " << sizeof(long double) << " bytes" << endl;
	cout << "long_double_value : " <<
		setprecision(numeric_limits<long double>::digits10 + 1) <<
		long_double_value << endl << endl;

	return 0;

	/*출력
	float : 4 bytes
	float_value : 9.876543

	double : 8 bytes
	double_value : 9.876543219876543

	long double : 8 bytes
	long_double_value : 9.876543219876543

	=> 형식이 다르면, 크기도 다르고, 출력 자리수도 다르다
	*/
}
