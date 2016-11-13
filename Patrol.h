#pragma once
#include "State.h"
class CPatrol :
	public CState
{
	CPatrol();
public:
	~CPatrol();
	 static CPatrol* getInstance();
	 void Enter(AICharacter* ch);
	 void Execute(AICharacter* ch);
	 void Exit(AICharacter* ch);
	 State getCurState() { return Patrol; }
};

