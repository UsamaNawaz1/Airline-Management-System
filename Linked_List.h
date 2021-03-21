#pragma once
#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
struct edge {
	int adjacentvertex;
	string nextnode;
	int cost;
	int departuretime;
	int arrivaltime;
	edge* link;
};
struct node {
	string cityname;
	int vertex;
	node* link;
	edge* head;
	edge* tail;
};
class List {
public:
	node* first, * last, * newnode;
	edge* newedge,*edgelast=NULL;
	List() :first(NULL), last(NULL), newnode(NULL) {}
	void insertlast(string,int);
	void insertedge(int,string,int,int,int);
	void Display_cityhead() const;
	void Display_all() const;
	int* Display_specific_departure(string,int,int&);
	void returncitydeparture(int*,int);
	int Display_specific_arrival(string);
	bool Search(string);
	bool compare(string, string);
	int return_vertex(string);
	string returncity(int);
	string returncityarrival(int,int&);
	int returnsingledeparture(int);
	int returnsinglearrival(int);
};
int List::returnsinglearrival(int destination) {
	bool check = false;
	for (edge* ptr = first->head->link; ptr != NULL;) {
		if (ptr->adjacentvertex == destination) {
			check = true;
			return ptr->arrivaltime;
		}
		else
			ptr = ptr->link;
	}
	if (!check)
		return -1;
}
int List::returnsingledeparture(int destination) {
	bool check = false;
	for (edge* ptr = first->head->link; ptr != NULL;) {
		if (ptr->adjacentvertex == destination) {
			check = true;
			return ptr->departuretime;
		}
		else
			ptr = ptr->link;
	}
	if (!check)
		return -1;
}
void List::returncitydeparture(int* sorted,int index) {
	//for (node* temp = first; temp != NULL; temp = temp->link) {
	for (int m = 0; m <= index; m++) {
		for (edge* ptr = first->head->link; ptr != NULL; ptr = ptr->link) {
			if (sorted[m] == ptr->departuretime) {
				cout << " \tCity Name: " << ptr->nextnode << endl;
				cout << " \tDeparture Time: " << ptr->departuretime << "\n\n";
				break;
			}
		}
	}
}
string List::returncityarrival(int arrival,int& number) {
		for (edge* ptr = first->head->link; ptr != NULL; ptr = ptr->link) {
			if (ptr->arrivaltime == arrival) {
				number = 555;
				return first->cityname;
				break;
			}
		}
	return "kan";
}
string List::returncity(int vertex) {
	for (node* ptr = first; ptr != NULL; ptr = ptr->link) {
		if (ptr->vertex == vertex) {
			 return ptr->cityname;
		}
	}
}
int List::return_vertex(string city) {
	bool check = false;
	for (node* temp = first; temp != NULL; temp = temp->link) {
		if (compare(city, temp->cityname)==true) {
			check = true;
			return temp->vertex;
		}
	}
	if(check==false)
	return -1;
}
bool List:: compare(string mj1, string mj2) {
	int i = 0, flag = 0;
	while (mj1[i] != '\0' && mj2[i] != '\0') 
	{
		
		if (mj1[i] != mj2[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0 && mj1[i] == '\0' && mj2[i] == '\0')
		return true;
	else
		return false;
}
int List::Display_specific_arrival(string city) {
	for (node* temp = first; temp != NULL; temp = temp->link) {
		for (edge* ptr = temp->head->link; ptr != NULL; ptr = ptr->link) {
			if (compare(city, ptr->nextnode) == true) {
				return ptr->arrivaltime;
				//cout << temp->cityname << "  " << "Arrival_Time: " << ptr->arrivaltime << endl;
			}
		}
	}
	return -1;
}
int* List::Display_specific_departure(string city,int currentvertices,int& index) {
	bool check = false;
	int* sorted = new int[currentvertices];
	if (compare(city, first->cityname) == true) {
	//	cout << "City_Name: " << first->cityname << ":";
		for (edge* ptr = first->head->link; ptr != NULL; ptr = ptr->link) {
			//	cout << ptr->nextnode << "   " << "Departure_Time: " << ptr->departuretime << "  ";
			sorted[++index] = ptr->departuretime;
			check = true;
		}
	}
	if (check)
		return sorted;
	else
		return NULL;
}
void List::Display_all() const {
	//for (node* temp = first; temp != NULL; temp = temp->link) {
	cout << "-> " << first->cityname << ":";
	for (edge* ptr = first->head->link; ptr != NULL; ptr = ptr->link) {
		cout << "  " << ptr->nextnode << " " << ptr->cost << " " << ptr->departuretime << " " << ptr->arrivaltime << " ";
	}
	cout << endl;
}
void List::insertedge(int adjacentver,string name,int weight,int departure,int arrival) {
	newedge = new edge;
	newedge->cost = weight;
	newedge->nextnode = name;
	newedge->adjacentvertex = adjacentver;
	newedge->departuretime = departure;
	newedge->arrivaltime = arrival;
	newedge->link = NULL;
	if (newnode->head->link == NULL) {
		newnode->head->link = newedge;
		edgelast = newedge;
	}
	else {
		edgelast->link = newedge;
		edgelast = newedge;
	}
}
void List::insertlast(string var,int ver) {
	newnode = new node;
	newnode->vertex = ver;
	newnode->cityname = var;
	newnode->link = NULL;
	newnode->head = new edge;
	newnode->head->link = NULL;
	newnode->tail = newnode->head;
	if (first == NULL) {
		first = newnode;
		last = newnode;
	}
	else {
		last->link = newnode;
		last = newnode;
	}
}

void List::Display_cityhead() const {
	//	for (node* temp = first; temp != NULL; temp = temp->link) {
	cout << "\t -> " << first->cityname;
}

#pragma once
