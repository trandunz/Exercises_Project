#pragma once
class CNode
{
private:
	int data;
	CNode* nextNode;
public:
	CNode();
	void setData(int iData);
	int getData() const;
	void setNextNode(CNode* nextNode);
	CNode* getNextNode() const;
};

