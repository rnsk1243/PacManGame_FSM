#pragma once
#define kMaxPointIndex 3
#define kTraceRangeX 6
#define kTraceRangeY 3

enum Location{PointA, PointB, PointC, PointD};
enum State{Patrol, Trace, Escape_};

class AICharacter;
class CState
{
public:
	CState(){}
	~CState(){}
	virtual void Enter(AICharacter* ch) = 0;
	virtual void Execute(AICharacter* ch) = 0;
	virtual void Exit(AICharacter* ch) = 0;
	virtual State getCurState() = 0;
};

