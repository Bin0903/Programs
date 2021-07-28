// LinkList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "LinkList.h"

using namespace std;

LinkList::LinkList() {
	this->dummyNode = new LinkNode(0);
	this->length = 0;
}

int LinkList::size() {
	return this->length;
}

void LinkList::create() {
	int value;
	while (cin >> value) {
		LinkNode* cur = new LinkNode(value);
		cur->next = dummyNode->next;
		this->dummyNode->next = cur;
		this->length += 1;
	}
}

int LinkList::get(int index) {
	if (index < 0 || index >= this->length) {
		cerr << "The index is invalid" << endl;
		return -1;
	}
	LinkNode* cur = dummyNode;
	while (index--) {
		cur = cur->next;
	}
	return cur->next->val;
}

void LinkList::insert(bool mark, int val) {
	if (mark) {
		LinkNode* cur = this->dummyNode;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = new LinkNode(val);
	} else {
		LinkNode* newNode = new LinkNode(val);
		newNode->next = dummyNode->next;
		dummyNode->next = newNode;
	}

	this->length += 1;
}

void LinkList::update(int index, int val) {
	if (index < 0 || index >= this->length) {
		cerr << "The index is invalid" << endl;
	}
	LinkNode* cur = this->dummyNode;
	while (index--) {
		cur = cur->next;
	}
	cur->next->val = val;
}

void LinkList::deleteNodeByIndex(int index) {
	if (index < 0 || index >= this->length) {
		cerr << "The index is invalid" << endl;
	}
	LinkNode* cur = dummyNode;
	while (index--) {
		cur = cur->next;
	}
	
	LinkNode* temp = cur->next;
	cur->next = temp->next;
	delete temp;
	this->length -= 1;
}

int LinkList::deleteNodeByValue(int val) {
	int count = 0;
	LinkNode* cur = dummyNode;
	while(cur!=nullptr && cur->next!=nullptr){
		if (cur->next->val == val) {
			LinkNode* temp = cur->next;
			cur->next = temp->next;
			delete temp;
			this->length -= 1;
			count++;
		}
		cur = cur->next;
	}
	return count;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
