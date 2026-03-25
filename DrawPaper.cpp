#include <iostream>
using namespace std;
bool IsSix(int x){
    int cnt = 0;
    while(x>0){
        if(x%10 == 6){
            cnt++;
        }
        else{
            cnt = 0;
        }

        if(cnt == 3){
            return true;
        }
        x/=10;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int idx = 0;
    for(int i = 666;;i++){
        if(IsSix(i)){
            idx++;
        }
        if(idx == n){
            cout << i << '\n';
            break;
        }
    }
}