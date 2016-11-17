#include <process.h>
#include "Game.h"
#include "KeyEvent.h"

Game* game = new Game();
unsigned int __stdcall mythread(void*) { // 이동 thread
	int i = 0;
	
	while (1) {
		game->move();
		Sleep(500);
	}

	return 0;
}
unsigned int __stdcall keyEvent(void*) { // 방향 입력 thread
	KeyEvent k;
	int i;

	while (1) {
		i = k.getKey();
		if (i != -1) game->setDirection(i);
	}

	return 0;
}

int main() {
	// thread 개수 늘어나면 핸들 수 따라서 증가
	HANDLE handleA, handleB;

	// 생성
	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	// 대기, 작동
	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	// 해제
	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}
