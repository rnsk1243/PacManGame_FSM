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
	// 현재 상태
	CState* m_pCurState;
	// 현재 위치
	Point m_curXY;
	// 순찰 좌표들
	Point* m_patrolPoints;
	// 도주 좌표들
	Point* m_escapePoints;
	// 현재 목표로 하는 좌표 인덱스
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
	// 현재 목표 좌표 가져옴
	int getCurObjPoint() { return m_curObjPoint; }
	// 다음 목표로 바꿈
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

