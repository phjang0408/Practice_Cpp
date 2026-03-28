#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cout << "정수 5개 입력: ";
    for(int i=0;i<n;i++){
        cin >> n;
        sum += n;
    }
    cout << "총합: " << sum << endl;
    
    float avg = float(sum) / 5;
    cout << "평균: "  << avg << endl;
    return 0;
}