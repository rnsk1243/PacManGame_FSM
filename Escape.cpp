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
		//cout << "���� ����..." << endl;
		ch->changeState(Escape_);
	}
}

CMyCursor* player = CMyCursor::getInstance();

void CEscape::Execute(AICharacter * ch)
{
	// �÷��̾ �Ŀ�Ǯ ���°� �ƴϸ�
	if (!player->isPowerFull())
	{
		// �ٽ� ���� ���·�
		ch->changeState(CPatrol::getInstance());
	}
	else // �÷��̾ �Ŀ�Ǯ �����̸�
	{
		// �÷��̾ �����ȿ� ������ ������
		if (!ch->isTraceRange(CMyCursor::getInstance()->getPlayerXY()))
		{
			// ������ ����
			ch->derderder();
		}
		else
		{
			// �÷��̾ �����ȿ� ���Դ�.
			// ����
			ch->escape();
		}
	}
}

void CEscape::Exit(AICharacter * ch)
{

}
