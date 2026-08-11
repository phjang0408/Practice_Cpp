#include <iostream>
#include <memory>
using namespace std;

class MyClass
{
public:
    MyClass(int val) : va(val) { cout << "객체 생성 (va: " << va << ")\n"; }
    ~MyClass() { cout << "객체 소멸 (va: " << va << ")\n"; }

    void SetTarget(const weak_ptr<MyClass>& target) { wpt = target; }

    void PrintTargetValue() const
    {
        // lock()은 weak_ptr이 가리키는 대상이 살아있으면 shared_ptr을 반환하고
        // 죽었으면 빈(nullptr) shared_ptr을 반환한다.
        shared_ptr<MyClass> locked = wpt.lock();
        if (locked != nullptr)
        {
            cout << "Target의 va 값: " << locked->va << "\n";
        }
        else
        {
            cout << "Target이 이미 소멸됨\n";
        }
    }

public:
    int va;
    weak_ptr<MyClass> wpt;
};

void UniquePtrExample()
{
    cout << "\n=== unique_ptr 예시 ===\n";

    // unique_ptr은 소유권을 단 하나만 가질 수 있다.
    // 복사가 불가능하고, move로만 소유권을 넘길 수 있다.
    unique_ptr<MyClass> up1 = make_unique<MyClass>(100);

    // up2 = up1; // 컴파일 에러, 복사 금지
    unique_ptr<MyClass> up2 = move(up1); // 소유권 이전

    if (up1 == nullptr)
    {
        cout << "up1은 이제 아무것도 가리키지 않는다\n";
    }
    cout << "up2의 va 값: " << up2->va << "\n";

    // 함수 종료 시 up2가 소멸되면서 MyClass 객체도 같이 소멸
}

void SharedPtrExample()
{
    cout << "\n=== shared_ptr 예시 ===\n";

    shared_ptr<MyClass> sp1 = make_shared<MyClass>(200);
    cout << "sp1 use_count: " << sp1.use_count() << "\n"; // 1

    {
        shared_ptr<MyClass> sp2 = sp1; // 복사하면 참조 카운트 증가
        cout << "복사 후 sp1 use_count: " << sp1.use_count() << "\n"; // 2
    } // sp2가 스코프를 벗어나면서 참조 카운트 감소

    cout << "스코프 종료 후 sp1 use_count: " << sp1.use_count() << "\n"; // 1
}

int main()
{
    UniquePtrExample();
    SharedPtrExample();

    cout << "\n=== weak_ptr 예시 ===\n";

    shared_ptr<MyClass> p1 = make_shared<MyClass>(10);
    auto p2 = make_shared<MyClass>(20);

    // 참조 설정 (shared_ptr을 전달하지만 내부에서는 weak_ptr로 저장)
    // 함수 매개변수가 weak_ptr이므로 _Uses는 그대로, _Weak만 증가
    p1->SetTarget(p2);
    p2->SetTarget(p1);

    cout << "p1 use_count: " << p1.use_count() << "\n"; // 1
    cout << "p2 use_count: " << p2.use_count() << "\n"; // 1

    p1->PrintTargetValue();
    p2->PrintTargetValue();

    return 0; // main 종료 시 p1, p2 모두 정상 소멸
}