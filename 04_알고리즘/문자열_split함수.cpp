#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 아래 설명도 있음
// 문자열(input)을, 구분자(delimiter) 기준으로 나누어, 벡터로 반환하는 함수
vector<string> split(string input, string delimiter){
    vector<string> ret; //return
    size_t pos = 0;
    string token = "";

    // 구분자를 찾지 못할 때(string::npos)까지 반복
    while((pos = input.find(delimiter)) != string::npos){
        // 0번 인덱스부터 구분자 위치(pos) 전까지 문자열 추출
        token = input.substr(0, pos);
        ret.push_back(token);
        
        // 추출한 토큰과 구분자 길이만큼 원본 문자열에서 삭제
        input.erase(0, pos + delimiter.length());
        
        // 중간 과정을 확인하기 위한 출력
        cout << "input = " << input  << " token = "<< token << '\n';
    }
    
    // 마지막 구분자 이후에 남은 문자열을 추가
    ret.push_back(input);
    return ret;
}

int main()
{
    string a = "abcdLabcdLabcdL", b = "d";
    vector<string> c = split(a, b);
    
    cout << "결과 출력: ";
    for(string d : c){
        cout << d << " "; // 가독성을 위해 공백 추가
    }
    cout << '\n';
    
    return 0;
}
/*
input.find(delimiter): 문자열 내에서 구분자가 처음 나타나는 위치의 인덱스를 반환합니다.

input.substr(0, pos): 0번부터 구분자 직전까지의 부분 문자열을 잘라내어 저장합니다.

input.erase(0, pos + delimiter.length()): 처리 완료된 토큰과 구분자 자체를 원본에서 제거하여 다음 탐색을 준비합니다.

반복문 종료 후 push_back: 마지막 구분자 뒤에 남은 문자열(혹은 구분자가 없을 때의 전체 문자열)을 결과 리스트에 포함시킵니다.
*/