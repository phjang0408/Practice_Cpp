// SOLID-4-ISP (Interface Segregation Principle)
// 클라이언트는 사용하지 않는 인터페이스에 의존하면 안 된다.
// 즉, 인터페이스를 구현할 때, 구체적인 역할, 작은 사이즈로 분리해야 한다.
#include <iostream>
using namespace std;

// 잘못된 설계, 인터페이스가 너무 많은 기능을 구현한다.
class IMachine {
public:
	virtual void Print() = 0;
	virtual void Scan() = 0;
	virtual void Fax() = 0;
	virtual ~IMachine() = default;
};

// 올바른 설계, 기능을 최소화하여, 불필요한 의존을 제거한다.
class IPrinter {
public:
	virtual void Print() = 0;
	virtual ~IPrinter() = default;
};

class IScanner {
public:
	virtual void Scan() = 0;
	virtual ~IScanner() = default;
};

class IFaxmachine {
public:
	virtual void Fax() = 0;
	virtual ~IFaxmachine() = default;
};