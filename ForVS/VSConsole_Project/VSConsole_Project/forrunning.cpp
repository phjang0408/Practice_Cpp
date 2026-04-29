#include <iostream>
#include <iomanip>
using namespace std;

class Student {
private:
    string Name;
    int grades[3];
    double avg_grade;
public:
    void SetName(string& name) { this->Name = name; }
    void SetGrade(int g1, int g2, int g3) {
        grades[0] = g1;
        grades[1] = g2;
        grades[2] = g3;
    }
    void SetAvg() {
        int tmp = 0;
        for (int i = 0; i < 3; i++) tmp += grades[i];
        avg_grade = (double)tmp / 3.0;
    }
    const string GetName() { return Name; }
    const int* GetGrades() { return grades; }
    const double Get_avg_grade() { return avg_grade; }
};

int main() {
    Student myStudents[3];

    for (int i = 0; i < 3; i++) {
        cout << "[학생 " << i + 1 << " 정보 입력]" << endl;

        cout << "이름: ";
        string name;
        cin >> name;
        myStudents[i].SetName(name);

        int g[3];
        for (int j = 0; j < 3; j++) {
            cout << "과목 " << j + 1 << " 점수: ";
            cin >> g[j];
            if (g[j] < 0 || g[j] > 100) {
                cout << "유효하지 않은 점수입니다." << endl;
                j--;
            }
        }
        myStudents[i].SetGrade(g[0], g[1], g[2]);
        myStudents[i].SetAvg();
    }

    cout << "\n======= 성적 결과 =======\n";

    int topIdx = 0;
    for (int i = 0; i < 3; i++) {
        const int* g = myStudents[i].GetGrades();
        cout << fixed << setprecision(2);
        cout << "이름: " << myStudents[i].GetName()
            << " | 점수: " << g[0] << ", " << g[1] << ", " << g[2]
            << " | 평균: " << myStudents[i].Get_avg_grade() << "\n";

        if (myStudents[i].Get_avg_grade() > myStudents[topIdx].Get_avg_grade())
            topIdx = i;
    }

    cout << "최고 평균 학생: " << myStudents[topIdx].GetName()
        << " (" << myStudents[topIdx].Get_avg_grade() << ")\n";
}