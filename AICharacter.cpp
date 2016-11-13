#include"H.h"
#include"MyCursor.h"

AICharacter::AICharacter(CState * state, Point startPoint, Point* patrolPoints):
	m_pCurState(state), m_curXY(startPoint), m_patrolPoints(patrolPoints), m_curObjPoint(0), m_curState(0)
{
	m_escapePoints = new Point[4];
	m_escapePoints[0] = Point(4, 4);
	m_escapePoints[1] = Point(4, 14);
	m_escapePoints[2] = Point(18, 14);
	m_escapePoints[3] = Point(18, 4);
}

AICharacter::~AICharacter()
{
}

void AICharacter::nextPoint()
{
	// 상태가 순찰중이면
	if (m_pCurState->getCurState() == Patrol)
	{
		// 현재 목표좌표 인덱스가 최대 인덱스보다 작으면
		if (m_curObjPoint < kMaxPointIndex && !isFinish)
		{
			// 다음 포인트 인덱스로 증가시킴
			m_curObjPoint++;
			if(m_curObjPoint == kMaxPointIndex)
				isFinish = true;
		}
		else if(isFinish){
			// 다시 0부터
			m_curObjPoint--;
			if (m_curObjPoint == 0)
				isFinish = false;
		}
	}
}

void AICharacter::patrol()
{
	if (getCurState() == Patrol)
	{
		//cout << "순찰중" << endl;
		// 순찰 목적지
		//Point point(m_patrolPoints[getCurObjPoint()].x, m_patrolPoints[getCurObjPoint()].y);
		// 순찰 시작
		move(m_patrolPoints[m_curObjPoint]);
		//cout << "목적지 좌표 = " << point.x << " , " << point.y << endl;
		//cout << "현재 위치 = " << m_curXY.x << " , " << m_curXY.y << endl;
	}
}

CGameMap* gameMap = CGameMap::getInstance();

void AICharacter::move(Point ObjPoint)
{
	
	if (m_curXY.x != ObjPoint.x
		&& m_curXY.y != ObjPoint.y)
	{
		if (m_curXY.x < ObjPoint.x && m_curXY.y < ObjPoint.y)
		{
		// 좌상(2사분면)
			//m_curXY.x++;
			//m_curXY.y++;
			right();
			down();
		}
		else if (m_curXY.x > ObjPoint.x && m_curXY.y < ObjPoint.y)
		{
			// 우상(1사분면)
			//m_curXY.x--;
			//m_curXY.y++;
			left();
			down();
		}
		else if (m_curXY.x < ObjPoint.x && m_curXY.y > ObjPoint.y)
		{
		// 좌하(3사분면)
			//m_curXY.x++;
			//m_curXY.y--;
			right();
			up();
		}
		else
		{
		// 우하(4사분면)
			//m_curXY.x--;
			//m_curXY.y--;
			left();
			up();
		}
	}
	else if (m_curXY.x == ObjPoint.x && m_curXY.y != ObjPoint.y)
	{
		if (m_curXY.y < ObjPoint.y)
		{
			//m_curXY.y++;
			down();
		}
		else
		{
			//m_curXY.y--;
			up();
		}
	}
	else if (m_curXY.x != ObjPoint.x && m_curXY.y == ObjPoint.y)
	{
		if (m_curXY.x < ObjPoint.x)
		{
			//m_curXY.x++;
			right();
		}
		else
		{
			//m_curXY.x--;
			left();
		}
	}
	else
	{
		//cout << m_curXY.x << " / " << m_curXY.y << endl;

		// 목적지 도착
		// 다음 포인트로 이동
		//cout << "목적지 도착" << endl;
		nextPoint();
	}
	//cout << m_curXY.x << " / " << m_curXY.y << endl;
	//cout << "=" << ObjPoint.x << " / " << ObjPoint.y << endl;
}

bool AICharacter::isTraceRange(Point playerPoint)
{
	int tempX = playerPoint.x - m_curXY.x;
	int tempY = playerPoint.y - m_curXY.y;
	if (tempX < 0)
	{
		tempX = (tempX * -1);
	}
	if (tempY < 0)
	{
		tempY = (tempY * -1);
	}

	//int sumTemp = (tempX * 2) + tempY;

	if (tempX <= kTraceRangeX && tempY <= kTraceRangeY)
	{
		//cout << "true" << endl;
		return true;
	}	else 
	{
		//cout << "false" << endl;
		return false;
	}
}

void AICharacter::update()
{
	if (m_pCurState && isLife)
	{
		delay();
		m_pCurState->Execute(this);
	}
	else 
	{
		//gameMap->setElement(m_curXY.x, m_curXY.y, BLANK);
		return;
	}
}

void AICharacter::draw()
{
	if (isLife)
	{
		if (CMyCursor::getInstance()->isPowerFull())
		{
			SetColor(9);
			ScreenPrint(m_curXY.x * 2, m_curXY.y, "♨"); // 버퍼에 그리기
		}
		else
		{
			SetColor(14);
			ScreenPrint(m_curXY.x * 2, m_curXY.y, "♨"); // 버퍼에 그리기
		}
		
	}
	else
	{
		return;
	}
	
}

void AICharacter::trace()
{
	if (getCurState() == Trace)
	{
		//cout << "추적중" << endl;
		CMyCursor* player = CMyCursor::getInstance();

		move(player->getPlayerXY());

	}
}

void AICharacter::changeState(CState * pNewState)
{
	m_pCurState->Exit(this);
	m_pCurState = pNewState;
	m_pCurState->Enter(this);
}

void AICharacter::delay()
{
	while (true) {
		curTime = clock();
		if (curTime - oldTime > 33) {
			oldTime = curTime;
			break;
		}
	}
}

void AICharacter::left()
{
	int temp = m_curXY.x;
	temp--;

	if (gameMap->getElement(temp, m_curXY.y) == OBJECT)
	{
		up();
		return;
	}
	m_curXY.x--;
}
void AICharacter::right()
{
	int temp = m_curXY.x;
	temp++;
	if (gameMap->getElement(temp, m_curXY.y) == OBJECT)
	{
		down();
		return;
	}
	m_curXY.x++;
}
void AICharacter::up()
{
	int temp = m_curXY.y;
	temp--;
	if (gameMap->getElement(m_curXY.x, temp) == OBJECT)
	{
		right();
		return;
	}
	m_curXY.y--;
}
void AICharacter::down()
{
	int temp = m_curXY.y;
	temp++;
	if (gameMap->getElement(m_curXY.x, temp) == OBJECT)
	{
		left();
		return;
	}
	m_curXY.y++;
}

void AICharacter::escape()
{
	if (getCurState() == Escape_)
	{
		// 도주 시작(도주 경로들)
		move(m_escapePoints[m_curObjPoint]);
		//cout << "목적지 좌표 = " << point.x << " , " << point.y << endl;
		//cout << "현재 위치 = " << m_curXY.x << " , " << m_curXY.y << endl;
	}
}
// 덜덜덜... 떨고있기
void AICharacter::derderder()
{
	if (getCurState() == Escape_)
	{
		left();
		right();
	}
}
