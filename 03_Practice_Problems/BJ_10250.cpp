// 10250번
#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int h, w, n;
		cin >> h >> w >> n;

		int floor = (n - 1) / h + 1;
		int room = (n - 1) % w + 1;

		printf("%d%02d\n",floor,room);
	}
}