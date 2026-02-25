// 11660번
#include <iostream>
using namespace std;
/*	부분합 배열 생성하면 => 특정 영역의 부분합을 1,1부터 시작하는 부분합들의 연산으로 계산 가능
*	1	2	3	4		1	3	6	10
*	2	3	4	5		3	8	15	24
*	3	4	5	6	=>	6	15	27	42
*	4	5	6	7		10	24	42	64
*	
*/
int Sum_Array[1025][1025];		// 1. 부분합 배열 선언 (전역으로 선언 -> 스택오버플로우 X)
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, temp;
	cin >> n >> m;

	// 2. 부분합 배열 채우기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> temp;
			Sum_Array[i][j] = Sum_Array[i - 1][j] + Sum_Array[i][j - 1] - Sum_Array[i - 1][j - 1] + temp;
		}
	}
	// 3. 부분합 배열을 통해 특정 영역의 합을 구하기
	for (int cnt = 0; cnt < m; cnt++) {
		int x1, x2, y1, y2, sum = 0;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << Sum_Array[x2][y2] - Sum_Array[x1-1][y2] -Sum_Array[x2][y1-1] + Sum_Array[x1-1][y1-1] << '\n';
	}
	return 0;
}