#pragma once

struct LinkNode {
	int val;
	LinkNode* next;
	LinkNode() : val(0), next(nullptr) {}
	LinkNode(int x) : val(x), next(nullptr) {}
};

class LinkList {
private:
	int length;
	LinkNode* dummyNode;
public:
	LinkList();
	
	int size();

	void create();

	int get(int index);

	void update(int index, int val);

	void insert(bool mark, int val);

	void deleteNodeByIndex(int index);

	int deleteNodeByValue(int val);
};