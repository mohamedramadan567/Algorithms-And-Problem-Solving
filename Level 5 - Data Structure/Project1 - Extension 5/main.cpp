#include <iostream>
#include"clsDblLinkedList.h"

using namespace std;


int main()
{
	//Can't solution
	clsDblLinkedList<int> MydblLinkedList;

	MydblLinkedList.InsertAtBeginning(5);
	MydblLinkedList.InsertAtBeginning(4);
	MydblLinkedList.InsertAtBeginning(3);
	MydblLinkedList.InsertAtBeginning(2);
	MydblLinkedList.InsertAtBeginning(1);

	cout << "\nLinked List Content:\n";
	MydblLinkedList.PrintList();

	clsDblLinkedList<int>::Node* N;

	N = MydblLinkedList.GetNode(4);

	cout << "\nNode value is: " << N->value;

	return 0;
}