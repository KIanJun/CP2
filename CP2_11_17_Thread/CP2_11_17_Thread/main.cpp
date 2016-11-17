#include <process.h>
#include "Game.h"
#include "KeyEvent.h"

Game* game = new Game();
unsigned int __stdcall mythread(void*) { // �̵� thread
	int i = 0;
	
	while (1) {
		game->move();
		Sleep(500);
	}

	return 0;
}
unsigned int __stdcall keyEvent(void*) { // ���� �Է� thread
	KeyEvent k;
	int i;

	while (1) {
		i = k.getKey();
		if (i != -1) game->setDirection(i);
	}

	return 0;
}

int main() {
	// thread ���� �þ�� �ڵ� �� ���� ����
	HANDLE handleA, handleB;

	// ����
	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	// ���, �۵�
	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	// ����
	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}
