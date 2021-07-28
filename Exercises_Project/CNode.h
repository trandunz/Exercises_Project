#ifndef _NODE_H__
#define _NODE_H__

class CNode
{
protected:
	int m_nData;
	CNode* m_CNextNode;
public:
	CNode();
	/*CNode(CNode* _firstNode);*/
	~CNode();
	void setData(int iData);
	int getData() const;
	void setNextNode(CNode* nextNode);
	CNode* getNextNode() const;
};

#endif