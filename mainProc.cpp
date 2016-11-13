#include"GameMap.h"
#include"Item.h"
#include"ItemList.h"
#include"util.h"
#include<iostream>
#include"MyCursor.h"
#include<time.h>
#include<conio.h>
#include"H.h"
using namespace std;

// �����������(CHeroineState Ŭ������ update�޼ҵ� ȣ��) �ʿ��� �Ķ����
struct ARGS
{
	// update�� �Ķ���ͷ� �� ������ ��ü
	// &�� �ٿ��ֿ��� ������ ���� ã�� �ʰ� ���� ������ ��ü�� �� ã�ư���.(����)
	// ���� &�� �ٿ����� ������ ���α׷��� ������ ������ ���� ���ϴ� update�޼ҵ尡 ȣ����� ����
	AICharacter& AI;
	// �پ��� ���µ��� �θ� Ŭ������ �����Ͽ� �� Ŭ������ ��ӹ��� ��� Ŭ������ update�޼ҵ带 ȣ�� �� �� ����
	//CHeroineState* state; // state�� ���������� �ٲٸ鼭 ���̻� �ʿ䰡 ��������.
};

DWORD WINAPI AI_1(LPVOID arg)
{
	
	while (true)
	{
		// ����ü �ּҸ� ���� pArgs������ �����ϰ� �Ķ���ͷ� ���� arg�� ARGS����ü �ּ������� �ٲپ���
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // �ּ� ��
		// ����ü�� ���� �Ķ���͸� �̿��Ͽ� update�޼ҵ� ȣ�� 
		// �̶� ����ü�� CHeroineState��ü�� �÷��̾� ���°� �ٲ𶧸��� �׿� �´� ���·� �ٲ��־ �� ���¿� �´� update�޼ҵ带 ȣ���ϰ� ����.
		// ��) ���� ���¿����� �������� ��ü�� state�� �־ �������� Ŭ������ update�޼ҵ带 ȣ����.
		if (pArgs->AI.isLive())
		{
			pArgs->AI.update();
		}
		else 
		{
			return 0;
		}
		//cout << "�����忡���� state�ּҰ� : " << CHeroine::m_state << endl;
		Sleep(500);
	}
}

DWORD WINAPI AI_2(LPVOID arg)
{

	while (true)
	{
		// ����ü �ּҸ� ���� pArgs������ �����ϰ� �Ķ���ͷ� ���� arg�� ARGS����ü �ּ������� �ٲپ���
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // �ּ� ��
		// ����ü�� ���� �Ķ���͸� �̿��Ͽ� update�޼ҵ� ȣ�� 
		// �̶� ����ü�� CHeroineState��ü�� �÷��̾� ���°� �ٲ𶧸��� �׿� �´� ���·� �ٲ��־ �� ���¿� �´� update�޼ҵ带 ȣ���ϰ� ����.
		// ��) ���� ���¿����� �������� ��ü�� state�� �־ �������� Ŭ������ update�޼ҵ带 ȣ����.
		if (pArgs->AI.isLive())
		{
			pArgs->AI.update();
		}
		else
		{
			return 0;
		}
		//cout << "�����忡���� state�ּҰ� : " << CHeroine::m_state << endl;
		Sleep(500);
	}
}

DWORD WINAPI AI_3(LPVOID arg)
{

	while (true)
	{
		// ����ü �ּҸ� ���� pArgs������ �����ϰ� �Ķ���ͷ� ���� arg�� ARGS����ü �ּ������� �ٲپ���
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // �ּ� ��
		// ����ü�� ���� �Ķ���͸� �̿��Ͽ� update�޼ҵ� ȣ�� 
		// �̶� ����ü�� CHeroineState��ü�� �÷��̾� ���°� �ٲ𶧸��� �׿� �´� ���·� �ٲ��־ �� ���¿� �´� update�޼ҵ带 ȣ���ϰ� ����.
		// ��) ���� ���¿����� �������� ��ü�� state�� �־ �������� Ŭ������ update�޼ҵ带 ȣ����.
		if (pArgs->AI.isLive())
		{
			pArgs->AI.update();
		}
		else
		{
			return 0;
		}
		//cout << "�����忡���� state�ּҰ� : " << CHeroine::m_state << endl;
		Sleep(500);
	}
}

DWORD WINAPI AI_4(LPVOID arg)
{

	while (true)
	{
		// ����ü �ּҸ� ���� pArgs������ �����ϰ� �Ķ���ͷ� ���� arg�� ARGS����ü �ּ������� �ٲپ���
		ARGS* pArgs = (ARGS*)arg;
		//cout << &pArgs->state << endl; // �ּ� ��
		// ����ü�� ���� �Ķ���͸� �̿��Ͽ� update�޼ҵ� ȣ�� 
		// �̶� ����ü�� CHeroineState��ü�� �÷��̾� ���°� �ٲ𶧸��� �׿� �´� ���·� �ٲ��־ �� ���¿� �´� update�޼ҵ带 ȣ���ϰ� ����.
		// ��) ���� ���¿����� �������� ��ü�� state�� �־ �������� Ŭ������ update�޼ҵ带 ȣ����.
		if (pArgs->AI.isLive())
		{
			pArgs->AI.update();
		}
		else
		{
			return 0;
		}
		//cout << "�����忡���� state�ּҰ� : " << CHeroine::m_state << endl;
		Sleep(500);
	}
}

//1. ���Ӹ� �����
//2. ����Ʈ �����
/*
  3. ������ ��ü�� �����Ͽ� ����Ʈ�� �߰��Ѵ�.
  4. ����Ѵ�.
*/
void main()
{
	////////////////////////
	Point* points = new Point[4];
	points[0] = Point(1, 1);
	points[1] = Point(8, 1);
	points[2] = Point(8, 4);
	points[3] = Point(1, 4);

	Point start(1, 1);
	////////////////////////
	////////////////////////
	Point* points1 = new Point[4];
	points1[0] = Point(17, 1);
	points1[1] = Point(10, 1);
	points1[2] = Point(10, 4);
	points1[3] = Point(17, 4);

	Point start1(17, 1);
	////////////////////////
	////////////////////////
	Point* points2 = new Point[4];
	points2[0] = Point(4, 20);
	points2[1] = Point(1, 20);
	points2[2] = Point(1, 22);
	points2[3] = Point(8, 22);

	Point start2(4, 20);
	////////////////////////
	////////////////////////
	Point* points3 = new Point[4];
	points3[0] = Point(17, 22);
	points3[1] = Point(17, 20);
	points3[2] = Point(16, 20);
	points3[3] = Point(16, 18);

	Point start3(17, 22);
	////////////////////////
	AICharacter AI(CPatrol::getInstance(), start, points);
	AICharacter AI1(CPatrol::getInstance(), start1, points1);
	AICharacter AI2(CPatrol::getInstance(), start2, points2);
	AICharacter AI3(CPatrol::getInstance(), start3, points3);

	HANDLE hThreadUpdate = NULL;
	HANDLE hThreadUpdate1 = NULL;
	HANDLE hThreadUpdate2 = NULL;
	HANDLE hThreadUpdate3 = NULL;
	
	// ����ü �ʱ�ȭ �Ѵ�.
	ARGS args = { AI };
	ARGS args1 = { AI1 };
	ARGS args2 = { AI2 };
	ARGS args3 = { AI3 };

	if (hThreadUpdate == NULL)
	{
		hThreadUpdate = CreateThread(NULL, 0, AI_1, &args, 0, NULL);
		if (hThreadUpdate == NULL)
			return;
		CloseHandle(hThreadUpdate);
	}

	if (hThreadUpdate1 == NULL)
	{
		hThreadUpdate1 = CreateThread(NULL, 0, AI_2, &args1, 0, NULL);
		if (hThreadUpdate1 == NULL)
			return;
		CloseHandle(hThreadUpdate1);
	}

	if (hThreadUpdate2 == NULL)
	{
		hThreadUpdate2 = CreateThread(NULL, 0, AI_3, &args2, 0, NULL);
		if (hThreadUpdate2 == NULL)
			return;
		CloseHandle(hThreadUpdate2);
	}

	if (hThreadUpdate3 == NULL)
	{
		hThreadUpdate3 = CreateThread(NULL, 0, AI_4, &args3, 0, NULL);
		if (hThreadUpdate3 == NULL)
			return;
		CloseHandle(hThreadUpdate3);
	}

	AICharacter** AIs = new AICharacter*[1];
	for (int i = 0; i < 4; i++)
	{
		AIs[i] = new AICharacter[1];
	}
	AIs[0] = &AI;
	AIs[1] = &AI1;
	AIs[2] = &AI2;
	AIs[3] = &AI3;
	////////////////////////
	double curTime = 0.0;
	double oldTime = 0.0;

	CGameMap* gameMap = CGameMap::getInstance();

	/*for (int i = 0; i < 5; i++)
	{
		int x = 2 + rand() % (gameMap->getWidth() - 4);
		int y = 2 + rand() % (gameMap->getHeight() - 4);
		gameMap->getItem()->insertItem(i, CItem(x, y));
	}
	srand((unsigned int)time(NULL));*/
	ScreenInit();
	///////////////

	bool bStop = false;
	int mapWidth = gameMap->getWidth();
	int mapHeight = gameMap->getHeight();

	while (!bStop)
	{
		
		if (_kbhit())
		{
			int nKey = _getch();
			int cursorX = gameMap->getCursor()->getX();
			int cursorY = gameMap->getCursor()->getY();
			int tileNum = gameMap->getElement(cursorX, cursorY);
			bool isContinue = true;
			switch (nKey)
			{
			case LEFT:
				if (cursorX - 1 >= 1)
				{
					gameMap->getCursor()->goLeft();
					int curX = gameMap->getCursor()->getX();
					int curY = gameMap->getCursor()->getY();
					
				}
				break;
			case RIGHT:
				if (cursorX + 1 <= mapWidth - 2)
				{
					gameMap->getCursor()->goRight();
					int curX = gameMap->getCursor()->getX();
					int curY = gameMap->getCursor()->getY();
					
				}
				break;
			case UP:
				if (cursorY - 1 >= 1)
				{
					gameMap->getCursor()->goUp();
					int curX = gameMap->getCursor()->getX();
					int curY = gameMap->getCursor()->getY();
					
				}
				break;
			case DOWN:
				if (cursorY + 1 <= mapHeight - 2)
				{
					gameMap->getCursor()->goDown();
					int curX = gameMap->getCursor()->getX();
					int curY = gameMap->getCursor()->getY();
					
				}
				break;
			case SPACE:
				TerminateThread(hThreadUpdate, 0);
				TerminateThread(hThreadUpdate1, 0);
				TerminateThread(hThreadUpdate2, 0);
				TerminateThread(hThreadUpdate3, 0);
				exit(0);
				break;
			}
		}
		
		///////////////
		ScreenClear();

		gameMap->draw();
		gameMap->getCursor()->draw();
		gameMap->getItem()->draw();
		AI.draw();
		AI1.draw();
		AI2.draw();
		AI3.draw();
		gameMap->crash(AIs, 4);
	//	system("pause");
	
		ScreenFlipping();
		while (true){
			curTime = clock();
			if (curTime - oldTime > 33){
				oldTime = curTime;
				break;
			}
		}
	}

	ScreenRelease();
//	system("pause");
}