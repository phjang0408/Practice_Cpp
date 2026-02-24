// 사용자 정의 리터럴
// [리터럴 연산자 형식] -> 반환_타입 operator"" 리터럴_접미사(매개변수_구성)

#include <iostream>

using namespace std;

const long double km_per_mile = 1.609344L;

//_km 사용자 리터럴 정의
long double operator"" _km(long double val) {
	// long double 타입, 리터럴_접미사 : _km, 매개변수 : long double val 하나
	return val; // 아무 작업 없이 그냥 반환
}

//_mi 사용자 리터럴 정의
long double operator"" _mi(long double val) {
	return val * km_per_mile; // 마일 -> 킬로미터로 변환
}

int main()
{
	long double distance_1 = 1.0_km; //_km 리터럴 (그대로 저장)
	long double distance_2 = 1.0_mi; //_mi 리터럴 (마일->킬로미터로 변환 후 저장)

	cout << distance_1 + distance_2 << " km" << endl;

	return 0;
}
