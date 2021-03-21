#include<iostream>
#include"Graphs.h"
#include"Linked_List.h"
using namespace std;
struct node1 {
	int info;
	node1* link;
};
class ShortList {
private:
	node1* first, * last, * newnode;
public:
	ShortList() :first(NULL), last(NULL), newnode(NULL) {}
	//ShortList(const ShortList&);
	void replace(const ShortList&);
	void insertdata(int);
	int* Display(int,int&) ;
	const ShortList& operator = (const ShortList&);
	void Clear();
};
void ShortList::Clear() {
	while (first) {
		node1* temp = first;
		first = temp->link;
		delete temp;
	}
}
const ShortList& ShortList:: operator = (const ShortList& l1) {
	if (this != &l1) {
		if (first != NULL)
			this->Clear();
		if (l1.first == NULL) {
			exit(1);
		}
		else {
			node1* temp = l1.first;
			while (temp != NULL) {
				newnode = new node1;
				newnode->info = temp->info;
				if (first == NULL) {
					first = newnode;
					last = newnode;
					last->link = NULL;
				}
				else {
					last->link = newnode;
					last = newnode;
					last->link = NULL;
				}
				temp = temp->link;
			}
			return *this;
		}
	}
}
void ShortList::replace(const ShortList& l1) {
	*this = l1;
}
void ShortList::insertdata(int var) {
	newnode = new node1;
	newnode->info = var;
	newnode->link = NULL;
	if (first == NULL) {
		first = newnode;
		last = newnode;
		last->link = NULL;
	}
	else {
		last->link = newnode;
		last = newnode;
		last->link = NULL;
	}
}
int* ShortList::Display(int currentvertices,int& i)  {
	List l1;
	int* vertices;
	bool check = false;
	vertices = new int[currentvertices];
	for (node1* temp = first; temp != NULL; temp = temp->link) {
		vertices[++i] = temp->info;
		check = true;
	}
	if (check == false) {
		return NULL;
	}
	return vertices;
}
