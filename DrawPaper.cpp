#include <iostream>
#include <string>

using namespace std;
class A{
public:
    int a, b;
    A() : a(10), b(20){  }
    A(int a) : a(a), b(20){}
    A(int a, int b) : a(a),b(b){}

    void CallSumi(){
        cout << sumi(a,b) << endl;
    }
private:
    virtual int sumi(int a, int b){
        return a + b;
    }
};

class B : public A{
    int sumi (int a, int b) override{
        return a*a + b*b;
    }
};

int main(){
    A myA;
    cout << myA.a << myA.b<<endl;
    myA.CallSumi();

    B myB;
    cout << myB.a << myB.b << endl;
    myB.CallSumi();

    A secA(3,5);
    secA.CallSumi();
    
    return 0;
}