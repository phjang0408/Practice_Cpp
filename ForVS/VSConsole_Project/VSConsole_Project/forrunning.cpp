// 자세한건 노션에 정리
#include <iostream>
#include <string>
using namespace std;

int main() {
    int num;
    char ch;
    char arr[100];
    string str;

    // 입력 : 10 Hello World
    //        C++ Programming

    // 1. 공백 전까지 입력
    cin >> num;
    cout << "num = " << num << '\n';

    // 버퍼 확인
    cout << "peek = '" << (char)cin.peek() << "'\n";

    // 2. 공백 1개 제거
    cin.ignore();
    cout << "peek = '" << (char)cin.peek() << "'\n";

    // 3. 문자 1개 읽기
    ch = cin.get();
    cout << "ch = '" << ch << "'\n";

    // 4. 개행 전까지(char[])
    cin.getline(arr, 100);
    cout << "arr = \"" << arr << "\"\n";

    // 5. 개행 전까지(string)
    getline(cin, str);
    cout << "str = \"" << str << "\"\n";
}