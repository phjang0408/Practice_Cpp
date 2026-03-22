#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<string> vec;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		vec.push_back(s);
	}

	sort(vec.begin(), vec.end(), [](const string& a, const string& b) {
		if (a.length() != b.length()) {
			return a.length() < b.length();	// 길이 우선 비교
		}
		return a < b;	// 길이가 같다면 사전순
		});

	vec.erase(std::unique(vec.begin(), vec.end()), vec.end());

	for (auto x : vec) {
		cout << x << '\n';
	}
}