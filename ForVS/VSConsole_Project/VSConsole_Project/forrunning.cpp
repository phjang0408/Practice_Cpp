#include <iostream>
using namespace std;

// 공통 부모
class Animal {
public:
    int age;
    Animal() : age(0) {
        cout << "Animal 생성자\n";
    }
};

// 가상 상속
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