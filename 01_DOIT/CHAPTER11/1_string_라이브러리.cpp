// string 라이브러리 - 기본
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {			
						/* 
						1. 객체 생성
						*/

	string str1("hello");	// 생성자 호출로 초기화
	string str2 = "Hello";	// 대입 연산자로 초기화

	char strc[] = "Hello";	// 저수준의 char형(기본형) 배열, 끝에 '\0'인 Null 문자가 붙음
	
	string str3;			// [입력 받아 생성하기]
	cin >> str3;			// cin : 공백을 기준으로 str받기
	getline(cin, str3);		// \n을 기준으로 입력받기
	getline(cin, str3, 'a');// \n을 기준으로 입력받기 + 'a'문자 까지만 입력받기

	cout << str1 << endl;
	cout << str2[0] << endl;

						/* 
						2. 크기
						*/

	cout << str1.length() << endl;	// str.length() : str의 문자열 길이 반환
	cout << str1.size() << endl;	// str.size()   : 컨테이너 공용 함수, 요소 당 크기 * 요소 개수 반환
	cout << str1.capacity() << endl; // str.capacity() : 이진수로 미리 할당한 메모리 크기 반환

	str2.resize(4);					// str.resize(n) : n으로 크기 조정, 크기가 작아지면 뒤에서부터 삭제. 커지면 뒤에 빈공간
	str2.resize(20, 'a');			// str.resize(n, 'c') : n으로 크기 조정, n이 기존보다 크면 'a'로 뒤를 채움.
	str2.shrink_to_fit();			// str.shrinnk_to_fit() : 남는 공간을 줄여, 용량을 맞춰줌.
	str2.empty();					// str.empty() : 빈 문자열인지 bool 반환

						/* 
						3. 접근, <algorithm> 라이브러리 활용
						*/

	cout << str1.at(3) << endl;		// at(index) : index의 char반환, 유효성 검사 포함
	cout << str1[3] << endl;		// str[index] : index의 char반환, 유혀성 검사 미포함
	cout << str1.front() << endl;	// str.front() : 문자열 맨 앞 char 반환
	cout << str1.back() << endl;	// str.back() : 문자열 맨 뒤 char 반환
	
	cout << *str1.begin() << endl;	// str.begin() : 맨 앞 index의 반복자 반환
	cout << *str1.end() << endl;	// str.end() : 맨 뒤 index의 반복자 반환
	for(char c : str2){cout << c;}	// 범위 기반 for문 가능(char로 각 요소)

	sort(str1.begin(), str1.end());					// sort 사용 가능
	reverse(str1.begin(), str1.end());				// reverse 사용 가능 (reverse는 마지막이 반 열린 구간인거 기억)
	cout << count(str1.begin(), str1.end(), 'b');	// count 사용 가능

						/* 
						4. 삽입, 추가, 삭제
						*/

	str1.append(str2);				// str.append(str2) : str뒤에 str2를 이어 붙여줌 ('+'도 같은 역할)
	str1.append(str2, 3, 4);		// str.append(str2, n, m) : str2의 n부터 m까지를, str에 붙여줌
	str1.append(4, 'a');			// str.append(n, 'c') : str뒤에 n개의 'c'를 붙여줌.
	str1.insert(3, str2);			// str.insert(n, str2) : str의 n번째 index에, str2를 끼워줌.
	str1.push_back('o');			// str.push_back('c') : char문자를 뒤에 추가
	str1.pop_back();				// str.pop_back() : str 맨 뒤의 한 문자를 제거


	str1.replace(2,5,str2);			// str.replace(n, m, str2) : str의 n부터 m개를, str2로 교체해줌.
	str3.clear();					// str.clear() : str을 모두 지움
	str3.erase();					// clear와 동일
	str1.erase(1, 5);				// str.erase(n, m) : n부터 m까지의 index를 제거해줌.
	str1.erase(str1.front(), str1.back()); // str.erase(시작반복자, 끝 반복자) 

						/* 
						5. 다양한 함수
						*/

	str1.find(str2);				// str1.find(str2) : str1에 str2 포함 여부, 찾으면 시작 index(size_t)반환,
									// 못 찾으면, size_t pos = string::npos를 반환.
	str1.find(str2, 3);				// str1.find(str2, n) : index n부터 탐색
	str1.rfind(str2, 2);			// 뒤에서부터 

	string subs = str1.substr();	// str1.substr() : 전체 반환
	subs = str1.substr(3);			// str1.substr(n) : n부터 끝까지 반환
	subs = str1.substr(3, 5);		// str1.substr(n, k) : n부터 k개 반환

	str1.compare(str2);				// 같다면 0 반환, str1 > str2 -> 음수, str1 > str2 -> 양수
	str1.swap(str2);				// str1을 str2로 교체(reference만 교환)

						/* 
						6. 숫자 <-> string
						*/

	string exs = "1234";

	int x = stoi(exs);				// string => 숫자 : stoi, stof, stol ...
	exs = to_string(x);				// 숫자 => string : to_string(숫자)
}