#include <iostream>
#include <io.h>
#include <fcntl.h>

using namespace std;

// 와이드 문자 wchar_t

int main(){
    wchar_t message_korean[] = L"반가워";
    wchar_t message_english[] = L"Hello!";

    // _setmode(_fileno(stdout), _0_U16TEXT); // 윈도우 콘솔 창 유니코드 출력 모드 설정
    wcout<<message_korean<<endl;
    wcout<<message_english<<endl;
}