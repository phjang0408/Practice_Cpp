// 가상상속과 다이아몬드 문제
#include <iostream>
using namespace std;

/* 다이아몬드 상속 형태
    Animal
     /   \
 Mammal  Bird
     \   /
       Bat
*/

// 공통 부모
class Animal {
public:
    int age;
    Animal() : age(0) {
        cout << "Animal 생성자\n";
    }
};

// 가상 상속 -> 부모를 상속 하지만, 
// 이유 : Bat가 Mammal과 Bird를 상속받을거니 너는 형태와 접근만 물려받아라.
// 이때, 가상 상속이 아니면, Animal이 2개 생겨, Bat가 헷갈림
class Mammal : virtual public Animal {
public:
    Mammal() {
        cout << "Mammal 생성자\n";
    }
};

class Bird : virtual public Animal {
public:
    Bird() {
        cout << "Bird 생성자\n";
    }
};

// 다이아몬드 상속
// 실제 객체 생성은 Bat가 한다.
class Bat : public Mammal, public Bird {
public:
    Bat() {
        cout << "Bat 생성자\n";
    }
};

int main() {
    Bat bat;
    bat.age = 5;   // Animal 하나 존재
    cout << bat.age << endl;
}