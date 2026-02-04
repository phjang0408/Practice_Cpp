// 정적 멤버와 정적 함수

/* 클래스는 정적 멤버 변수와 함수를 가질 수 있다.
* '정적 멤버 변수'는 클래스의 모든 객체가 공유하고, 객체를 생성하지 않아도 사용할 수 있다.
* 프로그램 실행 시작 시 메모리 할당, 종료 시 해제
* 
* '정적 멤버 함수'는 객체를 통하지 않고 호출할 수 있으며, 일반 멤버 변수에는 접근할 수 없다.
* 이는 정적 멤버 함수가 객체의 특정 인스턴스에 속하지 않기 때문이다.
* 그래서 주로 '정적 멤버 변수'의 값을 변경(setter)하거나 조회(getter)하는 것이 주 된 목적이다.
*/
#include <iostream>

class Player {
private:
    int score;   // 개별 플레이어 점수
    static int totalScore; // 전체 점수인 '정적 멤버 변수'

public:
    Player() : score(0) {}

    void addScore(int achieved_score) {
        score += achieved_score;
        totalScore += achieved_score;
    }

    int getScore() const { return score; }
    static int getTotalScore() { return totalScore; } // '정적 멤버 변수'에 접근하는,'정적 멤버 함수'
};

// [Static 변수는 클래스 외부에서 초기화]해야 합니다.
int Player::totalScore = 0;

int main() {
	Player Minsu, Dongwoo;
	
	Minsu.addScore(10);
	Dongwoo.addScore(20);

	//객체를 통하지 않고, '정적 멤버 함수' 호출
	std::cout << "Score : " << Player::getTotalScore() << std::endl;
	return 0;
}