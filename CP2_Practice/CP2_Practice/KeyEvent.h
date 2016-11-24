#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class KeyEvent {
private:
	HANDLE hln;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downKey;

public:
	KeyEvent() {
		hln = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}
	int getKey() { // 사용자가 키보드 버튼 누르면 해당 버튼 값 반환
		ReadConsoleInput(hln, &InRec, 1, &NumRead);
		if (InRec.EventType == KEY_EVENT) { // 버튼에 조작 가해지면
			if (InRec.Event.KeyEvent.bKeyDown) { // 조작이 버튼을 누른 것이면
				downKey = InRec.Event.KeyEvent.wVirtualKeyCode; // 눌린 버튼 값 저장
				return downKey; // 해당 값을 반환
			}
			else return -1;
		}
		return -1;
	}
};
