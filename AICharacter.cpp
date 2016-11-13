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
	// ���°� �������̸�
	if (m_pCurState->getCurState() == Patrol)
	{
		// ���� ��ǥ��ǥ �ε����� �ִ� �ε������� ������
		if (m_curObjPoint < kMaxPointIndex && !isFinish)
		{
			// ���� ����Ʈ �ε����� ������Ŵ
			m_curObjPoint++;
			if(m_curObjPoint == kMaxPointIndex)
				isFinish = true;
		}
		else if(isFinish){
			// �ٽ� 0����
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
		//cout << "������" << endl;
		// ���� ������
		//Point point(m_patrolPoints[getCurObjPoint()].x, m_patrolPoints[getCurObjPoint()].y);
		// ���� ����
		move(m_patrolPoints[m_curObjPoint]);
		//cout << "������ ��ǥ = " << point.x << " , " << point.y << endl;
		//cout << "���� ��ġ = " << m_curXY.x << " , " << m_curXY.y << endl;
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
		// �»�(2��и�)
			//m_curXY.x++;
			//m_curXY.y++;
			right();
			down();
		}
		else if (m_curXY.x > ObjPoint.x && m_curXY.y < ObjPoint.y)
		{
			// ���(1��и�)
			//m_curXY.x--;
			//m_curXY.y++;
			left();
			down();
		}
		else if (m_curXY.x < ObjPoint.x && m_curXY.y > ObjPoint.y)
		{
		// ����(3��и�)
			//m_curXY.x++;
			//m_curXY.y--;
			right();
			up();
		}
		else
		{
		// ����(4��и�)
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

		// ������ ����
		// ���� ����Ʈ�� �̵�
		//cout << "������ ����" << endl;
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
			ScreenPrint(m_curXY.x * 2, m_curXY.y, "��"); // ���ۿ� �׸���
		}
		else
		{
			SetColor(14);
			ScreenPrint(m_curXY.x * 2, m_curXY.y, "��"); // ���ۿ� �׸���
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
		//cout << "������" << endl;
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
		// ���� ����(���� ��ε�)
		move(m_escapePoints[m_curObjPoint]);
		//cout << "������ ��ǥ = " << point.x << " , " << point.y << endl;
		//cout << "���� ��ġ = " << m_curXY.x << " , " << m_curXY.y << endl;
	}
}
// ������... �����ֱ�
void AICharacter::derderder()
{
	if (getCurState() == Escape_)
	{
		left();
		right();
	}
}
