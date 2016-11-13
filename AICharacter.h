#pragma once
#include"State.h"
#include<string>

struct Point
{
	int x, y;
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(int _x, int _y)
	{
		x = _x; y = _y;
	}
};

class AICharacter
{
	// ���� ����
	CState* m_pCurState;
	// ���� ��ġ
	Point m_curXY;
	// ���� ��ǥ��
	Point* m_patrolPoints;
	// ���� ��ǥ��
	Point* m_escapePoints;
	// ���� ��ǥ�� �ϴ� ��ǥ �ε���
	int m_curObjPoint; // 0 = PointA, 1 = PointB ...
	int m_curState; // 0 = Patrol , 1 = Trace
	double curTime = 0.0;
	double oldTime = 0.0;
	bool isLife = true;
	bool isFinish = false;
public:
	AICharacter(CState* state, Point startPoint, Point* patrolPoints);
	AICharacter() {}
	~AICharacter();
	// ���� ��ǥ ��ǥ ������
	int getCurObjPoint() { return m_curObjPoint; }
	// ���� ��ǥ�� �ٲ�
	void nextPoint();
	int getCurState() { return m_curState; }
	void changeState(int state) { m_curState = state; }
	void move(Point ObjPoint);
	void patrol();
	bool isTraceRange(Point playerPoint);
	void update();
	void draw();
	void trace();
	void changeState(CState* pNewState);
	void delay();
	void left();
	void right();
	void up();
	void down();
	Point getCurXY() { return m_curXY; }
	void suicide() 
	{ 
		isLife = false; 

		m_curXY.x = 0;
		m_curXY.y = 0;
	}
	void escape();
	void derderder();
	bool isLive() { return isLife; }
};

