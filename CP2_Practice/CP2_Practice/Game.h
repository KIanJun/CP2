#include <Windows.h>
#include <iostream>

using namespace std;

class Game {
private:
	int x;
	int y;
	int direction;

	void gotoXY(int x, int y) {
		COORD pos = { x,y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}

public:
	Game() { // Constructor : 클래스 초기화( 5,5 정지 상태 )
		x = 5;
		y = 5;
		direction = 0;
	}

	void setDirection(int i) { this->direction = i; }
	void move() { // 0,0 ~ 50,25 까지 입력 방향으로 이동
		if (this->direction == 37 && x > 0) x--;
		else if (this->direction == 38 && y > 0) y--;
		else if (this->direction == 39 && x < 50) x++;
		else if (this->direction == 40 && y < 25) y++;
		system("cls");
		this->gotoXY(x, y);
		// 좌표 표현 때문에 출력 순서 바꿨음
		cout << "■";
		cout << x << " " << y;
	}
};
