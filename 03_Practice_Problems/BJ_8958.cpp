#include <iostream>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n;
	string s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int score = 0, tmp_score = 0;
		cin >> s;
		for (char c : s) {
			if (c == 'X') {
				tmp_score = 0;
			}
			else {
				score += ++tmp_score;
			}
		}
		cout << score << '\n';
	}
}