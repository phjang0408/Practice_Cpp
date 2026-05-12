#include <iostream>
#include <string>

int main()
{
	// 문자열 표현 방식
	std::string string_value("Hello");
	std::cout << string_value << std::endl;

	string_value = "World!";
	std::cout << string_value << std::endl;

	// 문자 리터럴
	std::cout << "I'm not using endl \n";
	std::cout << "like this" << '\n';

	// 문자열 비교
	std::string s = "Hello";

	if (s.length() > 3)
		std::cout << "longer then 3";
	else if (s.length() == 5)
		std::cout << "equal 5";

	// 길이 비교
	std::string t = "hi";
	if (s.size() == t.size())
		std::cout << "s == t";

	// 추가, 삽입, 삭제
	s += "abc";
	s.append("abc");
	s.insert(2, "XX"); // 위치, 문자열
	s.erase(2, 3);	   // 위치, 길이
	s.clear();		   // 전체 삭제
}
