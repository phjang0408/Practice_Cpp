#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout << "첫 번째 정수 입력: ";
    cin >> a;
    cout << "두 번째 정수 입력: ";
    cin >> b;

    cout << "합: " << a + b << endl;
    cout << "차: " << a - b << endl;
    cout << "곱: " << a * b << endl;
    if(b!=0){
        cout << "몫: " << a / b << endl;
        cout << "나머지: " << a % b;
    }
    else{
        cout << "0으로 나눌 수 없습니다.";
    }
}