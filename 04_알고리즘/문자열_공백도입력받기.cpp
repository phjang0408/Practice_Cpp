// 공백이 포함된 문자열을, 입력받는 2가지 방법
// 예제문제 : BJ_4458번 참고
#include <iostream>
using namespace std;
int main()
{
    // 1. cin.getline()
    // char배열만 가능(string은 오류)
    // 마지막은 '\n'이 들어가서, n개 배열이면, n-1개의 문자가 들어감.
    char test1[10];
    cin.getline(test1, 10);
    cout << test1 << endl;

    // 2. getline(string)
    // string 객체를 공백을 포함해 입력받는다.
    string test2;
    getline(cin, test2);
    cout << test2 << endl;

    // 3. cin의 주의사항
    // cin은 엔터('\n')를 입력받으면, 그 앞까지 저장한다.
    // 이후 개행문자('\n')는 버퍼에 남겨두기에,
    // [cin 이후의 입력은 버퍼가 들어가버린다.]
    // 이를 해결하기위해, ignore함수를 사용한다.
    // cin.ignore(읽어들일 문자의 개수, 종결 문자), 디폴트는 개행문자
    int a;
    string b;
    cin >> a;
    cin.ignore();    // 버퍼의 개행문자를 지워버린다.
    getline(cin, b); // ignore가 없으면, a를 입력받을 때의 개행문자가 들어가버린다.
    cout << a << endl;
    cout << b << endl;
}