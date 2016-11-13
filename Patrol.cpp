#include"H.h"

CPatrol::CPatrol()
{
}


CPatrol::~CPatrol()
{
}

CPatrol * CPatrol::getInstance()
{
	static CPatrol* instance = new CPatrol();
	if (instance)
		return instance;
	return nullptr;
}

void CPatrol::Enter(AICharacter * ch)
{
	if (ch->getCurState() != Patrol)
	{
		//cout << "순찰 시작..." << endl;
		ch->changeState(Patrol);
	}
}

void CPatrol::Execute(AICharacter * ch)
{
	if (ch->isTraceRange(CMyCursor::getInstance()->getPlayerXY()) 
		&& !CMyCursor::getInstance()->isPowerFull())
	{
		//ch->trace();
		//cout << "추적 시작" << endl;
		ch->changeState(CTrace::getInstance());
	}
	else if (CMyCursor::getInstance()->isPowerFull())
	{
		ch->changeState(CEscape::getInstance());
	}	else 
	{
		ch->patrol();
	}
}

void CPatrol::Exit(AICharacter * ch)
{
	//cout << "순찰 종료..." << endl;
}
