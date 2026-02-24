// 문제 1 
#include <iostream>

using namespace std;

int main() {
	int divisor = 0;
    //
	try {
		if (divisor == 0) {
			throw 2;
		}
	}
	catch (int exec) {
		divisor = exec;
	}
    //
    
	int result = 10 / divisor;
	cout << "결과 : " << result << endl;
	return 0;
}