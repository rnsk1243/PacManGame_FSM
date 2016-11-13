#include"H.h"



CTrace::CTrace()
{
}


CTrace::~CTrace()
{
}

CTrace * CTrace::getInstance()
{
	static CTrace* instance = new CTrace();
	if (instance)
		return instance;
	return nullptr;
}

void CTrace::Enter(AICharacter * ch)
{
	if (ch->getCurState() != Trace)
	{
		//cout << "���� ����..." << endl;
		ch->changeState(Trace);
	}
}

void CTrace::Execute(AICharacter * ch)
{
	if (!ch->isTraceRange(CMyCursor::getInstance()->getPlayerXY()) && !CMyCursor::getInstance()->isPowerFull())
	{
		//ch->patrol();
		//cout << "���� ����" << endl;
		ch->changeState(CPatrol::getInstance());
	}
	else if (CMyCursor::getInstance()->isPowerFull())
	{
		ch->changeState(CEscape::getInstance());
	}
	else
	{
		ch->trace();
	}
}

void CTrace::Exit(AICharacter * ch)
{
}
