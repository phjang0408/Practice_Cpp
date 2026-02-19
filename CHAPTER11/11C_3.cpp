// string 라이브러리 - 비교 compare()
#include <iostream>
#include <string>
using namespace std;

void compare_result(int result) {
	if (result == 0) {
		cout << result << " = 두 문자열이 같음" << endl;
	}
	else if(result > 0) {
		cout << result << " = 대상 문자열이 더 길거나, 첫 번째 문자가 더 큼" << endl;
	}
	else if (result < 0) {
		cout << result << " = 대상 문자열이 더 짧거나, 첫 번째 문자가 더 작음" << endl;
	}
}

int main() {
	// 같을 때,
	string s1 = "Hello";
	string s2 = "Hello";
	int result = s1.compare(s2);	// 비교_대상_문자열.compare(비교할_문자열)
	compare_result(result);

	// s1이 더 짧을 때
	s2 = "Hello World!";
	result = s1.compare(s2);
	compare_result(result);

	// 길이 동일, s1 문자열의 첫 문자가, 알파벳 순서 상 먼저 나올 때
	s1 = "cat";
	s2 = "dog";
	result = s1.compare(s2);
	compare_result(result);	// c가 d보다 작음

	// s1이 더 짧지만, 일치하지 않는 첫 문자가 순서상 늦게 나올 때
	s1 = "cat";		// cat 대신 aat로 하면, -1이 나옴. 앞 문자 같으면, 길이 비교
	s2 = "apple";
	result = s1.compare(s2);
	compare_result(result);	// 길이는 대상이 짧으므로 -1일거 같지만, c가 a보다 크다는 이유로 '1'
	
	return 0;
}