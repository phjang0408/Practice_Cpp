#include <iostream>
/* [매개 변수의 디폴트 값]
인자를 전달하지 않으면, 인자를 디폴트 값으로 간주한다.

디폴트 값의 선언은 함수의 선언부에 위치한다.
그 이유는 컴파일러의 특성 때문이다.
*/
int MyFuncOne(int num = 7){ // 디폴트 값은 7
    return num + 1;
}

/* 부분적 디폴트 값 설정에서
디폴트 값은 항상 오른쪽부터 채운다.

전달되는 인자가 매개변수보다 적을 경우
인자는 왼쪽부터 채워지기 때문이다. */
int MyFuncTwo(int num1, int num2, int num3 = 30){
    return num1+num2+num3;
}
//int MyFuncTwo(int num1 = 10, int num2, int num3) => 컴파일 에러

int main(){
    std::cout<<MyFuncOne()<<std::endl;
    std::cout<<MyFuncOne(7)<<std::endl;
    //디폴트값과 다른 값이면 어떻게 될까
    std::cout<<MyFuncOne(5)<<std::endl;

    //부분적 디폴트 값 설정
    std::cout<<MyFuncTwo(10,20)<<std::endl;
}