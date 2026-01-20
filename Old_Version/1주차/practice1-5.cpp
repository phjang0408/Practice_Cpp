#include <iostream>
/* [이름공간에 대한 소개]
이름공간이 다르면, 동일한 함수 및 변수가 선언 가능해진다.

프로젝트 진행에서, 이름의 충돌을 막을 목적이다.
*/

// 1.아래는 서로 다른 '이름공간'에서 정의된, 같은 이름의 함수
namespace BestComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "BestCom이 정의한 함수" << std::endl;
    }
}

namespace ProgComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "ProgCom이 정의한 함수" << std::endl;
    }
}

// 3. 동일한 이름공간 내의 함수 호출
namespace BestComImpl
{
    void PrettyFunc(void)
    {
        std::cout << "BestCom과 동일한 이름공간" << std::endl;
        SimpleFunc(); // 동일한 이름 공간에서의 호출
        // 이름 공간을 명시하지 않으면, 동일한 이름공간 안에서 호출할 함수를 찾는다.
    }
}

// 2. 함수 선언과 정의의 분리
namespace MyComImpl
{
    void SimpleFunc(void);
}

// 4. 이름공간의 중첩
namespace Parent
{
    int num = 2; // Parend::num

    namespace child1
    {
        int num = 3; // Parent::child1::num
    }

    namespace child2
    {
        int num = 4; // Parent::child2::num
    }
    // 이름공간의 중첩을 통해, 계층적 구조를 설계할 수 있다.
}

int main()
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    MyComImpl::SimpleFunc();

    // 이름공간 중첩 예시
    std::cout << Parent::num << std::endl;
    std::cout << Parent::child1::num << std::endl;
    std::cout << Parent::child2::num << std::endl;

    return 0;
}

// 이름공간 'MyComImpl'에 위치하는 함수 정의
void MyComImpl::SimpleFunc(void)
{
    std::cout << "MyComImpl에서 정의한 함수" << std::endl;
}