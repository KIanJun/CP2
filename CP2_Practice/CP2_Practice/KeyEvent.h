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
	int getKey() { // ����ڰ� Ű���� ��ư ������ �ش� ��ư �� ��ȯ
		ReadConsoleInput(hln, &InRec, 1, &NumRead);
		if (InRec.EventType == KEY_EVENT) { // ��ư�� ���� ��������
			if (InRec.Event.KeyEvent.bKeyDown) { // ������ ��ư�� ���� ���̸�
				downKey = InRec.Event.KeyEvent.wVirtualKeyCode; // ���� ��ư �� ����
				return downKey; // �ش� ���� ��ȯ
			}
			else return -1;
		}
		return -1;
	}
};
