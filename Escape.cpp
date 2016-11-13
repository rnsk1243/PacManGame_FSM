#include"H.h"


CEscape::CEscape()
{
}


CEscape::~CEscape()
{
}

CEscape * CEscape::getInstance()
{
	static CEscape* instance = new CEscape();
	if (instance)
		return instance;
	return nullptr;
}

void CEscape::Enter(AICharacter * ch)
{
	if (ch->getCurState() != Escape_)
	{
		//cout << "도주 시작..." << endl;
		ch->changeState(Escape_);
	}
}

CMyCursor* player = CMyCursor::getInstance();

void CEscape::Execute(AICharacter * ch)
{
	// 플레이어가 파워풀 상태가 아니면
	if (!player->isPowerFull())
	{
		// 다시 순찰 상태로
		ch->changeState(CPatrol::getInstance());
	}
	else // 플레이어가 파워풀 상태이면
	{
		// 플레이어가 범위안에 들어오지 않으면
		if (!ch->isTraceRange(CMyCursor::getInstance()->getPlayerXY()))
		{
			// 덜덜덜 떨기
			ch->derderder();
		}
		else
		{
			// 플레이어가 범위안에 들어왔다.
			// 도주
			ch->escape();
		}
	}
}

void CEscape::Exit(AICharacter * ch)
{

}
