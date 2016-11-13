#pragma once
#include"Item.h"

class CItemList
{
	CItem* m_list;
	int m_maxItem; // ����Ʈ�� �ִ� �迭 ũ��
	int m_numItem; // ����Ʈ�� ����� item�� ����
	CItemList(int max) :m_maxItem(max), m_numItem(0)
	{
		m_list = new CItem[max];
	}
public:
	CItemList();
	~CItemList();
	static CItemList* getInstance();
	void insertItem(int pos, CItem item);
	void removeItem(int pos);
	CItem* getItem(int pos);

	bool isEmpty(){ return m_numItem == 0; }
	bool isFull(){ return m_numItem == m_maxItem; }
	void draw();

	int getMaxItem(){ return m_maxItem; }
};

