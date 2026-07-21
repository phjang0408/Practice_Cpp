// 출력형식 키워드
#include <iostream>
#include <iomanip> // setw(), setfill(), setprecision(), ...

int main()
{
	int Number = 123;

	std::cout << std::showpos << Number << std::endl; // pos는 positive. 양수를 뜻하는 + 기호를 생략말고 보여달라 할 때 showpos.
	std::cout << std::noshowpos << Number << std::endl;
	std::cout << std::dec << Number << std::endl;
	std::cout << std::hex << Number << std::endl;
	std::cout << std::oct << Number << std::endl;
	std::cout << std::uppercase << std::hex << Number << std::endl;
	std::cout << std::nouppercase << std::hex << Number << std::endl;
	std::cout << std::showbase << std::oct << Number << std::endl;
	std::cout << std::noshowbase << std::oct << Number << std::endl;
	std::cout << std::dec;

	int MinusNumber = -123;

	// setw()는 iomanip에 정의되어 있습니다.
	std::cout << '[' << std::setw(6) << MinusNumber << ']' << std::endl;
	std::cout << '[' << std::setw(6) << std::left << MinusNumber << ']' << std::endl;
	std::cout << '[' << std::setw(6) << std::internal << MinusNumber << ']' << std::endl;
	std::cout << '[' << std::setw(6) << std::right << MinusNumber << ']' << std::endl;
	std::cout << '[' << std::setw(6) << std::setfill('0') << MinusNumber << ']' << std::endl;

	float Number01 = 123.0;
	float Number02 = 123.456;

	std::cout << std::showpoint << Number01 << ' ' << Number02 << std::endl; // point는 부동소수점. 기본값으로 소수점 아래 3자리까지 표기.
	std::cout << std::noshowpoint << Number01 << ' ' << Number02 << std::endl;
	std::cout << std::fixed << Number02 << std::endl;
	std::cout << std::scientific << Number02 << std::endl;
	std::cout << std::fixed << std::setprecision(2) << Number02 << std::endl;

	bool IsReady = true;

	std::cout << std::boolalpha << IsReady << std::endl;
	std::cout << std::noboolalpha << IsReady << std::endl;

	return 0;
}
