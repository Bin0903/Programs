#include "iostream"
#include "LinkList.h"

using namespace std;

int main() {
	LinkList linkList = LinkList();
	
	// create
	linkList.create();

	// get
	cout << linkList.get(0) << endl;

	// update
	linkList.update(1, 2);

	// insert(true:head£¬false:tail)
	linkList.insert(true, 100);
	linkList.insert(false, 101);

	// delete
	linkList.deleteNodeByIndex(0);
	cout << linkList.deleteNodeByValue(20) << endl;

	int i = 0;
	for (i = 0; i < linkList.size()-1; i++) {
		cout << linkList.get(i) << " ";
	}
	cout << linkList.get(i) << endl;
	return 0;
}