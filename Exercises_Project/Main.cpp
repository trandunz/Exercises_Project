#include "CSingleLinkList.h"

int main()
{
	CSingleLinkList* newLinkList = new CSingleLinkList;
	
	newLinkList->insertAtTheFront(2);
	newLinkList->insertAtTheFront(1);
	
	newLinkList->insertAtTheEnd(3);
	newLinkList->insertAtTheEnd(4);


	newLinkList->display();
	newLinkList->deleteFromTheEnd();
	newLinkList->display();
	newLinkList->deleteFromTheFront();
	newLinkList->display();
	newLinkList->search(2);
	newLinkList->display();

	return 0;
}