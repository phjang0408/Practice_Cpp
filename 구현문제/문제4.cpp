#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// [요구사항] Student 클래스 정의 (멤버 변수 private, 멤버 함수 public)
class Student {
private:
	string name;				// 학생 이름
	int scores[3];				// 과목 점수 3개
	double average;				// 평균
public:
	// 이름 설정
	void set_name(string n) {
		name = n;
	}

	// 과목 점수 입력 (3과목 반복 입력)
	void input_scores() {
		for (int i = 0; i < 3; i++) {
			while (true) {
				cout << "과목 " << (i + 1) << " 점수: ";
				cin >> scores[i];

				// [요구사항] 0~100 범위 벗어나면 오류 메시지, 재입력
				if (scores[i] < 0 || scores[i] > 100) {
					cout << "유효하지 않은 점수입니다." << endl;
					continue;
				}
				break;
			}
		}
		// 입력 완료 후 평균 계산 [요구사항] 명시적 형 변환으로 double로 계산
		average = (double)(scores[0] + scores[1] + scores[2]) / 3.0;
	}

	// 학생 정보 출력
	void print_info() const{
		cout << "이름: " << name << " | 점수: " << scores[0] << ", "
			 << scores[1] << ", " << scores[2] << " | 평균: "
			 << fixed << setprecision(2) << average << endl;
	}

	// 평균 반환 (최고 평균 학생 찾기용)
	double get_average() const {
		return average;
	}

	// 이름 반환
	string get_name() const {
		return name;
	}
};

int main() {
	// [요구사항] 3명 학생 객체 생성, 데이터 입력
	Student students[3];

	for (int i = 0; i < 3; i++) {
		cout << "[학생 " << (i + 1) << " 정보 입력]" << endl;
		string name;
		cout << "이름: ";
		cin >> name;
		students[i].set_name(name);
		students[i].input_scores();
		cout << endl;
	}

	// [요구사항] 전체 학생 정보 출력
	cout << "======= 성적 결과 =======" << endl;
	for (int i = 0; i < 3; i++) {
		students[i].print_info();
	}

	// [요구사항] 평균이 가장 높은 학생 찾기
	double max_average = students[0].get_average();
	int max_index = 0;

	for (int i = 1; i < 3; i++) {
		if (students[i].get_average() > max_average) {
			max_average = students[i].get_average();
			max_index = i;
		}
	}

	cout << endl <<  "최고 평균 학생: " << students[max_index].get_name()
		 << " (" << fixed << setprecision(2) << max_average << ")" << endl;

	return 0;
}
