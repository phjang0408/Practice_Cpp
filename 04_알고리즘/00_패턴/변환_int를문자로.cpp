#include <iostream>
#include <string>
using namespace std;

int main()
{
    int num = 5;

    // 1. 숫자 자체를 문자로 변환 (0부터 9까지의 한 자리 수)
    char num_to_char = num + '0';
    cout << "1 : " << num_to_char << endl;

    // 2. 아스키 기반 변환
    num = 65;
    char num_to_ascii = static_cast<char>(num);
    cout << "2 : " << num_to_ascii << endl;

    // 3. string과 int 변환
    string s = "12345";
    num = std::stoi(s);     // string -> int : stoi(x);
    cout << "3 : " << num << endl;

    s = to_string(num);     // int -> string : to_string(x);
    cout << "4 : " << s << endl;

    return 0;
}