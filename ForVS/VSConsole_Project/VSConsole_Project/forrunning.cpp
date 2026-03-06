#include <iostream>
#include <string>
using namespace std;
int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int count = 0;
	string s;
	getline(cin, s);
	if (s == " ") {		// 문자열이 공백으로만 이루어진 경우
		cout << 0;
	}
	else {
		for (int i = 1; i < s.size() - 1; i++) {
			if (s[i] == ' ') {
				count++;
			}
		}
		cout << count + 1;
	}
	return 0;
}