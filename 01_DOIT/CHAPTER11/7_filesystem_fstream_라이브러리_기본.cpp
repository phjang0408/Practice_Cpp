// 파일 시스템
#include <iostream>
#include <string>
#include <filesystem>	// 파일 '시스템' 헤더 파일, 파일에 관한 정보(이름, 위치) 제공
#include <fstream>		// 파일 '입출력' 헤더 파일, 읽고쓰는 기능 제공
// fstream의 
// ifstream : 파일 읽기(input), ostream : 파일 쓰기(output)

using namespace std;

namespace fs = std::filesystem;

int main() {
	// 1. 디렉터리 생성(filesystem)
	fs::create_directories("MyDirectory");

	// 2. 파일 생성과 쓰기(fstream)
	ofstream outFile("MyDirectory/myFile.txt");			// ofstream은 입출력 전용
	outFile << "Hello, FileSystem Library!" << endl;
	outFile.close();				// [반드시] 열었으면, 꼭! 닫아야 함.

	// 3. 디렉터리 내의 파일 확인
	cout << "Files in MyDirectory:\n";

	// 디렉터리 탐색
	for (const fs::directory_entry& entry : fs::directory_iterator("MyDirectory")) {
		if (entry.is_regular_file()) {	// 일반 파일인지 확인
			cout << entry.path().filename() << endl;	// 파일 이름만 출력
		}
	}

	// 4. 파일 읽기
	ifstream inFile("MyDirectory/myFile.txt");
	string line;
	while (getline(inFile, line)) {	// 파일 끝까지 한 줄씩 읽기
		cout << line << endl;
	}
	inFile.close();					// [반드시] 열었으면, 꼭! 닫아야 함.

	// 5. 파일과 디렉터리 삭제
	fs::remove_all("MyDirectory");

	return 0;
}