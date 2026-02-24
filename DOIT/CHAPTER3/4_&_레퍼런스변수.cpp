// 레퍼런스 변수
#include <iostream>

using namespace std;

//non-const 참조형
void swap(int &ref_a, int &ref_b)	// 매개변수를 '레퍼런스 변수'로 선언
{
	// 함수 내부에서, 일반 변수처럼 사용한다.
	int temp = ref_a;
	ref_a = ref_b;
	ref_b = temp;
}

//const 값 참조형
void Print(const string& sentence){
	cout << sentence;
}

// r-value 참조형

int main() {
    int a = 10;
    // int& ref_a; => 1. 선언 시에 초기화 하지 않으면 오류가 난다.
    int& ref_a = a;
    cout << "ref_a : " << ref_a << endl;

    int b = 20;
    ref_a = b; // 2. b로 바뀌는 게 아닌, a에 b값이 대입된다.

    cout << "ref_a : " << ref_a << endl;

    //int& ref = nullptr; // 3. 불가능! 반드시 실체가 있어야 한다.
    // 4. 일반 변수와 동일하게 사용한다.
    
    a = 5, b = 10;
    swap(a, b); // 호출시에도 일반 변수와 동일하게 사용한다.
	cout << "a : " << a << " b : " << b << endl;

    string s = "hello";
    Print(s);
    
	return 0;
}