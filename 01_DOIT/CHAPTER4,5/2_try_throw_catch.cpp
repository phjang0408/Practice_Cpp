// try throw catch 문 기본
#include <iostream>
using namespace std;

int main() {
	try // 예외가 발생할 수 있는 코드를 try블록으로 감싼다
	{
		int input;
		cout << "정수 중 하나를 입력(음수 가능) : ";
		cin >> input;

		if (input > 0) {
			cout << "throw 1 실행" << endl;
			throw 1;
			cout << "throw 1 결과" << endl; // throw 이후의 코드는 무시!
		}

		if (input < 0) {
			cout << "throw -1.0f 실행" << endl;
			throw - 1.0f;
			cout << "throw -1.0f 결과" << endl;
		}

		if (input == 0) {
			cout << "throw 'Z' 실행" << endl;
			throw 'Z';
			cout << "throw 'Z' 결과" << endl;
		}
	}

	catch (int a)	// 정수 형식 예외처리
	{
		cout << "catch " << a << endl;
	}

	catch (float b)	// 실수 형식 예외처리
	{
		cout << "catch " << b << endl;
	}

	catch (char c)  // 문자 형식 예외처리
	{
		cout << "catch " << c << endl;
	}

    catch (...)		// 처리되지 않는 나머지 예외(문자열 등 throw에 없는) 모두 받기!
    {
	cout << "Catch All!!" << endl;
    }
	return 0;
}