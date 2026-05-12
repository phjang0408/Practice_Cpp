#include <iostream>

int main(){
    //기본 출력
    std::cout<<"Hello World!";
    std::cout<<"with"<<"\\n"<<std::endl;
    std::cout<<"like this"<<std::endl;

    //Cpp의 서식지정자
    int num = 20;
    std::cout<<num<<" Cpp는 서식지정이 불필요합니다"<<std::endl;

    //데이터의 입력
    int val1;
    std::cout<<"첫 번째 숫자입력 : ";
    std::cin>>val1;
    int val2;
    std::cout<<"두 번째 숫자입력 : ";
    std::cin>>val2;
    int result = val1+val2;
    std::cout<<"덧셈 결과 : "<<result<<std::endl;

    //지역변수 선언
    result = 0;
    std::cout<<"두 개의 숫자 입력 : ";
    std::cin>>val1>>val2; // 연이은 데이터 입력도 가능하다.
    // [std::cin을 통해 입력되는 데이터는]
    // 스페이스 바, 엔터, 탭과 같은 공백을 기준으로한다.
    if(val1<val2){
        for(int i = val1+1;i<val2;i++){ //for문 내에서 변수 선언
            result+=i;
        }
    }
    else{
        for(int i = val2+1; i<val1;i++){
            result +=i;
        }
    }
    std::cout<<"두 수 사이의 정수의 합 : "<<result<<std::endl;

    //배열 기반의 문자열 입출력
    char name[100];
    char lang[200];
    std::cout<<"이름을 말해주세요 : ";
    std::cin>>name;     //문자열의 입력 방식도 다른 데이터와 큰 차이가 없다.
    std::cout<<"좋아하는 언어도 말해주세요 : ";
    std::cin>>lang;
    std::cout<<"내 이름은"<<name<<"입니다.\n";
    std::cout<<"제일 좋아하는 언어는 "<<lang<<"입니다."<<std::endl;
    return 0;
}