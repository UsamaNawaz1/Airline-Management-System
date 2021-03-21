#pragma once
#include<iostream>
#include"Linked_List.h"
using namespace std;
const int maxPassengers = 25;
const int maxBussinessclass = 10;
struct name {
	string firstname;
	string lastname;
	int sortlastname;
};
struct Reservation {
	string Flightno;
	name n1;
	string source;
	string destination;
	int seatnumber;
	string seattype;
};
struct node2 {
	Reservation* reserve;
	node2() {
		reserve = new Reservation;
	}
	node2* link;
	int passengers;
};
class reservation {
private:
	node2* first, * last, * newnode;
public:
	reservation() :first(NULL), last(NULL), newnode(NULL) {}
	void getinitialdata(string, string, string, string, string, int, string, int);
	void getdata(string, string);
	void Displaylistofpassengers() ;
	void Display_Passenger(string, string,int*,int,bool,string*,int,int*,int*,int,int) const;
	void DeletePassenger(string, string);
	int Duplicatesremove(int*, int);
	bool searchseat(int,node2*);
	node2* front();
};
void reservation::getinitialdata(string sourcecity, string destinationcity, string firstname, string lastname, string flightnumber, int seatnumber, string seattype, int sortname) {
	newnode = new node2;
	if (first != NULL) {
		last->link = newnode;
		if (last->passengers == maxPassengers) {
			cout << "\t No more Booking can be taken for this particular Flight ! " << endl;
			delete newnode;
			last->link = NULL;
			return;
		}
		newnode->passengers = last->passengers + 1;
		last = newnode;
	}
	else {
		first = newnode;
		last = newnode;
		newnode->passengers = 1;
	}
	newnode->reserve->source = sourcecity;
	newnode->reserve->destination = destinationcity;
	newnode->reserve->n1.firstname = firstname;
	newnode->reserve->n1.lastname = lastname;
	newnode->reserve->Flightno = flightnumber;
	newnode->reserve->seatnumber = seatnumber;
	newnode->reserve->seattype = seattype;
	newnode->reserve->n1.sortlastname = sortname;
	newnode->link = NULL;
}
node2* reservation::front() {
	return first;
}
int reservation::Duplicatesremove(int* sorted, int Size) {
	if (Size == 0 || Size == 1)
		return Size;
	int* temp = new int[Size];
	int m = 0;
	for (int i = 0; i < Size - 1; i++) {
		if (sorted[i] != sorted[i + 1])
			temp[m++] = sorted[i];
	}
	temp[m++] = sorted[Size - 1];
	for (int i = 0; i < m; i++) {
		sorted[i] = temp[i];
	}
	return m;
}
void reservation::DeletePassenger(string name1, string name2) {
	bool check = false;
	List l1;
	if (first == NULL) {
		cout << "\t No Reservation to Delete ! " << endl;
		return;
	}
	if ((check = l1.compare(name1, first->reserve->n1.firstname))==true && (check = l1.compare(name2, first->reserve->n1.lastname))==true){
		node2* current = first;
		first = first->link;
		if (first == NULL)
			last = NULL;
		else
		last->passengers = last->passengers - 1;
		delete current;
		return;
		}
	else {
		node2* prev = first;
		for (node2* temp = prev->link; temp != NULL; ) {
			if ((check = l1.compare(name1, temp->reserve->n1.firstname))==true && (check = l1.compare(name2, temp->reserve->n1.lastname))==true)
				 {
					node2* current = temp;
					prev->link = temp->link;
					last->passengers = last->passengers - 1;
					if (temp == last)
						last = prev;
					delete current;
					return;
				}
			else {
				temp = temp->link;
				prev = prev->link;
			}
		}
		if (!check) {
			cout << "No Passenger Exists with this name ! " << endl;
			return;
		}
	}
}
void reservation::Display_Passenger(string name1, string name2,int* vertices,int index,bool direct,string* Listofcities,int currentvertices,int* sorted,int* sorted1,int direc,int direct1) const {
	bool check = false;
	List l1;
	List* graph = new List[currentvertices];
	for (node2* temp = first; temp != NULL; ) {
		if (check = l1.compare(name1, temp->reserve->n1.firstname)) {
			check = false;
			if (check = l1.compare(name2, temp->reserve->n1.lastname)) {
				system("cls");
				cout << endl << endl;
				cout << "=======================================================================================" << endl;
				cout << "|                                   OSPREY AIRWAYS                                    |" << endl;
				cout << "=======================================================================================" << endl << endl;
				cout << endl << endl;
				cout << "\t Name of the Passenger is: " << temp->reserve->n1.firstname << " " << temp->reserve->n1.lastname << endl;
				cout << "\t Outbound Flight" << endl;
				cout << "\t " << temp->reserve->source << "    ->    " << temp->reserve->destination << endl;
				cout << "\t Flight No#: " << temp->reserve->Flightno << endl;
				if (direct) {
					cout << ".....................................ROUTE.............................................\n\n";
					for (int i = 0; i < index; i++) {
						cout << "......................................................................................." << endl;
						cout << "\t " << Listofcities[vertices[i]] << "\t -> " << Listofcities[vertices[i + 1]] << endl;
						cout << "......................................................................................." << endl;
						cout << "\t Departure Time: " << sorted[i] << "\t Arrival Time: " << sorted1[i] << endl;
					}
				}
				else {
					cout << "......................................................................................." << endl;
					cout << "\t Departure Time: " << direc << "\t Arrival Time: " << direct1 << endl;
				}
				cout << "......................................................................................." << endl;
				cout << "\t Seat Number : " << temp->reserve->seatnumber << " (" << temp->reserve->seattype << ")" << endl;
				return;
			}
			else 
				{
				temp = temp->link;
				//cout << "\t hahahello No Passenger Exists with this name ! " << endl;
				//return;
			}
		}
		else
			temp = temp->link;
	}
	if (!check) {
		cout << "\tmeeo No Passenger Exists with this name ! " << endl;
		return;
	}
}
void reservation::Displaylistofpassengers() {
	cout << "\t The List of Details for this Particular Flight (" << first->reserve->source << " -> " << first->reserve->destination << ")" << endl;
	if (first==NULL) {
		cout << "No Passenger to Show ! " << endl;
		return;
	}
	int Size = last->passengers;
	int* sorted = new int[Size];
	int index = -1;
	for (node2* temp = first; temp != NULL; temp = temp->link) {
		//cout << "Name of the Passenger is: " << temp->reserve->n1.firstname << " " << temp->reserve->n1.lastname << endl;
		sorted[++index] = temp->reserve->n1.sortlastname;
	}
	for (int i = 0; i < Size; i++) {
		bool check = false;
		for (int j = 1; j < Size; j++) {
			if (sorted[j] < sorted[j - 1]) {
				int temp = sorted[j - 1];
				sorted[j - 1] = sorted[j];
				sorted[j] = temp;
				check = true;
			}
		}
		if (!check)
			break;
	}
	cout << endl;
	int n = Duplicatesremove(sorted, Size);
	for (int k = 0; k < n; k++) {
		for (node2* temp = first; temp != NULL; temp = temp->link) {
			if (sorted[k] == temp->reserve->n1.sortlastname) {
				cout << "\t -> " << temp->reserve->n1.firstname << " " << temp->reserve->n1.lastname << endl;
			}
		}
	}
}
void reservation::getdata(string city1, string city2) {
	newnode = new node2;
	if (first != NULL) {
		last->link = newnode;
		if (last->passengers == maxPassengers) {
			cout << "\t No more Booking can be taken for this particular Flight ! " << endl;
			delete newnode;
			last->link = NULL;
			return;
		}
		newnode->passengers = last->passengers + 1;
		last = newnode;
	}
	else {
		first = newnode;
		last = newnode;
		newnode->passengers = 1;
	}
	newnode->reserve->source = city1;
	newnode->reserve->destination = city2;
	cout << "\t Enter the first name of the Passenger: " << endl;
	cout << "\t ";
	cin >> newnode->reserve->n1.firstname;
	cout << "\t Enter the last name of the Passenger:" << endl;
	cout << "\t ";
	cin >> newnode->reserve->n1.lastname;
	cin.ignore();
	cout << "\t Enter the flight No# : " << endl;
	cout << "\t ";
	getline(cin, newnode->reserve->Flightno);
	char s = newnode->reserve->n1.lastname[0];
	newnode->reserve->n1.sortlastname = int(s);
	bool check = false;
	bool outer = false;
		int choice = -1;
		cout << "\t Enter your Fair Type:" << endl;
		cout << "\t 01- BUSSINESS CLASS" << endl;
		cout << "\t 02- ECONOMY CLASS" << endl;
		cout << "\t -> "; cin >> choice;
		switch (choice) {
		case 1: {
			do {
				newnode->reserve->seattype = "BUSSINESS CLASS";
				cout << "\t Enter the seat number (1-10) " << endl;
				cout << "\t ->"; cin >> newnode->reserve->seatnumber;
				if (newnode->reserve->seatnumber > 10 || newnode->reserve->seatnumber <=0) {
					cout << "Invalide Seatnumber ! " << endl;
					continue;
				}
					check = searchseat(newnode->reserve->seatnumber, newnode);
					if (check) {
						cout << "Seatnumber Already Reserve! " << endl;
						cout << "Press 'y' to reserve another seat or anyother key to exit the reservation: " << endl;
						char p;
						cout << "\t ->"; cin >> p;
						if (p == 'y') {
							system("cls");
							continue;
						}
						else
							return;
					}
			} while (check);
			break;
		}
		case 2: {
			do {
				newnode->reserve->seattype = "ECONOMY CLASS";
				cout << "\t Enter the seat number (11-25): " << endl;
				cout << "\t ->"; cin >> newnode->reserve->seatnumber;
				if (newnode->reserve->seatnumber > maxPassengers || newnode->reserve->seatnumber < 11) {
					cout << "Invalide Seat number";
					continue;
				}
				check = searchseat(newnode->reserve->seatnumber, newnode);
				if (check) {
					cout << "Seatnumber Already Reserve! " << endl;
					cout << "Press 'y' to reserve another seat or anyother key to exit the reservation: " << endl;
					char p;
					cout << "\t ->"; cin >> p;
					if (p == 'y') {
						system("cls");
						continue;
					}
					else
						return;
				}
			} while (check);
			break;
		}
		}
	newnode->link = NULL;
}
bool reservation::searchseat(int seat,node2* temp) {
	bool found = false;
	if (first == NULL) {
		return false;
	}
	else {
		node2* current = first;
		while (current != temp && !found) {
			if (current->reserve->seatnumber == seat)
				found = true;
			current = current->link;
		}
		if (found)
			return true;
		else
			return false;
	}
}