#include <iostream>
using namespace std;

class Person
{
public:
	Person();
	~Person();
	virtual void Print() = 0;
	void setHeight(int height) {
		this->height = height;
	}
	void YourHeight() {
		cout << height << endl;
	}
	static int YourAge() {
		return age;
	}
private:
	int height;
	static int age;
};

int Person::age = 20;

Person::Person()
{
}

Person::~Person()
{
}

class JIUK : public Person {
public:
	void Print() override {
		cout << "Im Jiuk" << endl;
	}
};

int main() {
	JIUK j;
	j.Print();
	j.setHeight(100);
	j.YourHeight();
	cout << j.YourAge() << endl;
}