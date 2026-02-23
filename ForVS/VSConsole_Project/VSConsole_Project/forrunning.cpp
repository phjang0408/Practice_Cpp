#include <iostream>
#include <utility>
using namespace std;

class myClass {
public:
    int* data;

    // 기본 생성자
    myClass() : data(new int(0)) {
        cout << "기본 생성자\n";
    }

    // 값 지정 생성자
    myClass(int value) : data(new int(value)) {
        cout << "값 생성자\n";
    }

    // 복사 생성자 (깊은 복사)
    myClass(const myClass& other) {
        data = new int(*other.data);
        cout << "복사 생성자\n";
    }

    // 이동 생성자
    myClass(myClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
        cout << "이동 생성자\n";
    }

    // 복사 대입 연산자
    myClass& operator=(const myClass& other) {
        cout << "복사 대입\n";
        if (this != &other) {
            delete data;
            data = new int(*other.data);
        }
        return *this;
    }

    // 이동 대입 연산자
    myClass& operator=(myClass&& other) noexcept {
        cout << "이동 대입\n";
        if (this != &other) {
            delete data;
            data = other.data;
            other.data = nullptr;
        }
        return *this;
    }

    // 소멸자
    ~myClass() {
        delete data;
        cout << "소멸자\n";
    }
};

int main() {
    cout << "---- a 생성 ----\n";
    myClass a(10);

    cout << "\n---- b 생성 ----\n";
    myClass b(20);

    cout << "\n---- a = b ----\n";
    a = b;                // 복사 대입

    cout << "\n---- a = std::move(b) ----\n";
    a = std::move(b);     // 이동 대입

    cout << "\n---- c 생성 (이동 생성자) ----\n";
    myClass c = myClass(30); // 이동 생성자 (또는 최적화)

    cout << "\n---- 프로그램 종료 ----\n";
    return 0;
}