#pragma once
#include<iostream>
#include<fstream>
#include "Linked_List.h"
#include"ShortestDestination.h"
#include"Reservation_Passengers.h"
using namespace std;
class Graphs {
private:
	ShortList* Shortest_Destination(int, int);
	int* shortestpath(int);
protected:
	int maxSize;
	int currentvertices;
	List* graph;
	reservation** graph1;
	int** weights;
	int* smallweight;
public:
	Graphs(int Size) :maxSize(Size), currentvertices(0){//maxsize=size; 
		graph = new List[Size];
		graph1 =new reservation *[Size];
		for (int index = 0; index < Size; index++)
			graph1[index] = new reservation[Size];
		weights = new int* [Size];
		for (int index = 0; index < Size; index++)
			weights[index] = new int[Size];
		smallweight = new int[Size];
	}
	Graphs() {}
	void creategraph();
	void Displayservedcities() const;
	void Display_Departure(string);
	void Display_Arrival(string);
	void toallcities(string);
//	void shortedpath(string);
	void Display_shortestpath(string,string);
	int* citiestovertex(string, string);
	void shortestpath_Destination(string,string);
	void getreservation(string, string);
	void Displaylistofpassenger(string, string);
	void DisplayPassengerDetail(string,string,string, string);
	void DeletePassenger(string, string, string, string);
};
void Graphs::toallcities(string city) {
	int vertex = -1;
	bool check = false;
	for (int index = 0; index < currentvertices;) {
		int s = graph[index].return_vertex(city);
		if (s != -1) {
			check = true;
			vertex = s;
			break;
		}
		else
			index++;
	}
	if (!check) {
		cout << "\t There is no flight for this City : " << endl;
		return;
	}
	int* ptr = shortestpath(vertex);
	string cityname;
	cout << "List of all cities that can be reached from -> "<<city << " are as follow: " << endl;
	for (int index = 0; index < currentvertices; index++) {
		if (ptr[index] != INT_MAX) {
			cityname = graph[index].returncity(index);
			cout << "\t -> " << cityname << endl;
		}
	}

}
void Graphs::Display_Departure(string city) {
	bool check = false;
	int* sorted;
	int inc = -1;
	int k = -1;
	for (int index = 0; index < currentvertices;) {
		int vertex = graph[index].return_vertex(city);
		if (vertex != -1) {
			check = true;
			sorted = graph[vertex].Display_specific_departure(city,currentvertices,inc);
			if (sorted == NULL) {
				cout << "\t There is no departure flight for this City ! " << endl;
				return;
			}
			else {
				for (int i = 0; i <= inc; i++) {
					bool check = false;
					for (int j = 1; j <= inc; j++) {
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
				graph[vertex].returncitydeparture(sorted,inc);
				break;
			}
		}
		else
			index++;
	}
	if (!check) {
		cout << "\t No Such City Exist! " << endl;
		return;
	}
}
void Graphs::Display_Arrival(string city1) {
	bool check = false;
	int* sorted=new int[currentvertices];
	int inc = -1;
	int k = -1;
	int* city=new int[currentvertices];
	for (int index = 0; index < currentvertices; index++) {
		int u=graph[index].Display_specific_arrival(city1);
		if (u != -1) {
			check = true;
			sorted[++inc] = u;
			city[++k]=index;
		}
	}
	if (!check) {
		cout << "\t We have no Flight to this City! " << endl;
		return;
	}
	for (int i = 0; i <= inc; i++) {
		bool check = false;
		for (int j = 1; j <= inc; j++) {
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
	string cityprint;
	int counter = -786;
	for (int index = 0; index <= inc; index++) {
		for (int m = 0; m <= k; m++) {
			cityprint = graph[city[m]].returncityarrival(sorted[index],counter);
			if (counter == 555) {
				cout << " \tCity Name: " << cityprint << endl;
				cout << " \tArrival Time: " << sorted[index] << "\n\n";
			}
			counter = -786;
		}
	}
}
void Graphs::DeletePassenger(string source, string destination, string name1, string name2) {
	int* ptr = citiestovertex(source, destination);
	if (ptr[0] == -1) {
		cout << "No Such City Exist !";
		return;
	}
	int* temp = shortestpath(ptr[0]);
	if (smallweight[ptr[1]] != INT_MAX) {
		graph1[ptr[0]][ptr[1]].DeletePassenger(name1, name2);
	}
	else {
		cout << "\t There is no flight for this destination : " << endl;
		return;
	}
}
void Graphs:: DisplayPassengerDetail(string source,string destination,string name1, string name2) {
	int* ptr = citiestovertex(source, destination);
	if (ptr[0] == -1) {
		cout << "No Such City Exist !";
		return;
	}
	bool check = false;
	if (weights[ptr[0]][ptr[1]] == INT_MAX)
		check = true;
	int* temp = shortestpath(ptr[0]);
	if (smallweight[ptr[1]] != INT_MAX) {
		/*int* sorted;
		int inc = -1;
		sorted = graph[ptr[0]].Display_specific_departure(source, currentvertices, inc);*/
		ShortList* Short;
		Short = Shortest_Destination(ptr[0], ptr[1]);
		int* vertices;
		string* Listofcities;
		Listofcities = new string[currentvertices];
		for (int i = 0; i < currentvertices; i++) {
			Listofcities[i] = graph[i].returncity(i);
		}
		int index = -1;
		vertices = Short[ptr[1]].Display(currentvertices,index);
		if (vertices == NULL) {
			cout << "There is no direct path to this city ! " << endl;
			return;
		}
		cout << " \t ";
		int* sorted = new int[currentvertices];
		int* sorted1 = new int[currentvertices];
		int inc=-1,direct=-1;
		int inc1 = -1,direct1=-1;
		if (check) {
			for (int i = 0; i < index; i++) {
				sorted[++inc] = graph[vertices[i]].returnsingledeparture(vertices[i + 1]);
				sorted1[++inc1] = graph[vertices[i]].returnsinglearrival(vertices[i + 1]);
			}
		}
		else {
			direct = graph[ptr[0]].returnsingledeparture(ptr[1]);
			direct1 = graph[ptr[0]].returnsinglearrival(ptr[1]);
		}
		system("pause");
		graph1[ptr[0]][ptr[1]].Display_Passenger(name1,name2,vertices,index,check,Listofcities,currentvertices,sorted,sorted1,direct,direct1);
	}
	else {
		cout << "\t There is no flight for this destination : " << endl;
		return;
	}
}
void Graphs::Displaylistofpassenger(string source, string destination) {
	int* ptr = citiestovertex(source, destination);
	if (ptr[0] == -1) {
		cout << "No such city exist ! " << endl;
		return;
	}
	int* temp = shortestpath(ptr[0]);
	if (smallweight[ptr[1]] != INT_MAX) {
		if (graph1[ptr[0]][ptr[1]].front() == NULL) {
			cout << "\t No passenger to Show !" << endl;
			return;
		}
		graph1[ptr[0]][ptr[1]].Displaylistofpassengers();
	}
	else {
		cout << "\t There is no flight for this destination : " << endl;
		return;
	}
}
void Graphs:: getreservation(string source, string destination) {
	int* ptr = citiestovertex(source, destination);
	if (ptr[0] == -1) {
		cout << "\t No such city exist ! ";
		return;
	}
		int* temp = shortestpath(ptr[0]);
		if (weights[ptr[0]][ptr[1]] == INT_MAX) {
			cout << "\t There is no direct Flight to this Destination, You may encounter a Stay :" << endl;
			cout << "\t Press 'y' to proceed reservation or 'n' to return " << endl;
			char s;
			cout << "\t -> "; cin >> s;
			if (s == 'y') {}
			else
				return;
		}
		if (smallweight[ptr[1]] != INT_MAX) {
			graph1[ptr[0]][ptr[1]].getdata(source, destination);
		}
		else {
			cout << "\t There is no flight for this destination : " << endl;
			return;
		}
}
void Graphs::shortestpath_Destination(string source,string Destination) {
	int* ptr = citiestovertex(source, Destination);
	if (ptr[0] == -1) {
		cout << "No such cities Exist ! " << endl;
		return;
	}
	int vertex, destination;
	vertex=ptr[0];
	destination = ptr[1];
	ShortList* Short;
	Short=Shortest_Destination(vertex, destination);
	int* vertices;
	int index = -1;
	vertices = Short[destination].Display(currentvertices,index);
	string* Listofcities;
	Listofcities = new string[currentvertices];
	for (int i = 0; i < currentvertices; i++) {
		Listofcities[i] = graph[i].returncity(i);
	}
	if (vertices == NULL) {
		cout << "There is no direct path to this city ! " << endl;
		return;
	}
	cout << " \t ";
	for (int i = 0; i <= index; i++) {
		cout << Listofcities[vertices[i]] << " -> ";
	}
}
int* Graphs::citiestovertex(string source, string Destination) {
	int* ptr = new int[1];
	bool check = false;
	for (int index = 0; index < currentvertices;) {
		int s = graph[index].return_vertex(source);
		if (s != -1) {
			check = true;
			ptr[0] = s;
			break;
		}
		else
			index++;
	}
	if (!check) {
		ptr[0] = -1;
	}
	for (int index = 0; index < currentvertices;) {
		int s = graph[index].return_vertex(Destination);
		if (s != -1) {
			ptr[1] = s;
			check = true;
			break;
		}
		else
			index++;
	}
	if (!check) {
		ptr[1] = -1;
	}
	return ptr;
//	Shortest_Destination(vertex, destination);
}
ShortList* Graphs::Shortest_Destination(int vertex, int destination) {
	ShortList* Short;
	Short = new ShortList[currentvertices];
	for (int n = 0; n < currentvertices; n++)
		smallweight[n] = weights[vertex][n];
	bool* visited;
	visited = new bool[currentvertices];
	for (int k = 0; k < currentvertices; k++)
		visited[k] = false;
	while (!visited[destination]) {
		visited[vertex] = true;
		if (visited[destination])
			break;
		smallweight[vertex] = 0;
		for (int index = 0; index < currentvertices; index++) {
			if (smallweight[index] != INT_MAX && smallweight[index] != 0) {
				Short[index].insertdata(vertex);
				Short[index].insertdata(index);
			}
			else if (smallweight[index] == 0)
				Short[index].insertdata(vertex);
		}
		for (int index = 0; index < currentvertices - 1; index++) {
			double minvalue = DBL_MAX;
			int minnode;
			for (int i = 0; i < currentvertices; i++)
				if (!visited[i]) {
					if (smallweight[i] < minvalue) {
						minnode = i;
						minvalue = smallweight[minnode];
					}
				}
			visited[minnode] = true;
			if (visited[destination])
				break;
			for (int x = 0; x < currentvertices; x++)
				if (!visited[x])
					if (minvalue + weights[minnode][x] < smallweight[x]) {
						smallweight[x] = minvalue + weights[minnode][x];
						Short[x].replace(Short[minnode]);
						Short[x].insertdata(x);
					}
		}
	}
	return Short;
}

void Graphs::Display_shortestpath(string source,string destination) {
	int* temp = citiestovertex(source, destination);
	if (temp[0] == -1) {
		cout << "No such city exist ! " << endl;
		return;
	}
	int vertex = temp[0];
	int destinationvertex = temp[1];
	int* ptr = shortestpath(vertex);
	if (smallweight[destinationvertex] != INT_MAX)
		cout << "Shortest Route between " << source << "\t -> " << destination << " is: " << smallweight[destinationvertex];
	else
		cout << "\t There is no route to reach the desired destination ! " << endl;
}/*
void Graphs::shortedpath(string name) {
	for (int index = 0; index < currentvertices;) {
		int s = graph[index].return_vertex(name);
		if (s != -1) {
			shortestpath(s);
			break;
		}
		else
			index++;
	}
}*/
int* Graphs::shortestpath(int vertex) {
	for (int n = 0; n < currentvertices; n++)
		smallweight[n] = weights[vertex][n];
	bool* visited=new bool[currentvertices];
	for (int k = 0; k < currentvertices; k++)
		visited[k] = false;
	visited[vertex] = true;
	smallweight[vertex] = 0;
	for (int i = 0; i < currentvertices - 1; i++) {
		double minvalue = DBL_MAX;
		int minnode;
		for (int index = 0; index < currentvertices; index++)
			if (!visited[index])
				if (smallweight[index] < minvalue) {
					minnode = index;
					minvalue = smallweight[minnode];
				}
		visited[minnode] = true;
		for (int x = 0; x < currentvertices; x++)
			if (!visited[x])
				if (minvalue + weights[minnode][x] < smallweight[x])
					smallweight[x] = minvalue + weights[minnode][x];

	}
	return smallweight;
}
void Graphs::Displayservedcities() const {
	for (int index = 0; index < currentvertices; index++) {
		graph[index].Display_cityhead();
		cout << endl;
	}
}
void Graphs::creategraph() {
	int vertex,inc=0;
	string cityname;
	int departuretime;
	int arrivaltime;
	int weight;
	int adjacentvertex;
	string adjacent;
	fstream fin;
	char filename[50]="shortestpath_timevertex.txt";
	//cout << "Enter the name of file you want to open :" << endl;
	//cin.get(filename,50);
	fin.open(filename);
	if (!fin) {
		cout << "Can't Open the file right now ! " << endl;
		return;
	}
	fin >> currentvertices;
	for (int index = 0; index < maxSize; index++) {
		for (int j = 0; j < maxSize; j++) {
			weights[index][j] = INT_MAX;
		}
	}
	for (int index = 0; index < currentvertices; index++) {
		int returnedvertex;
		fin >> vertex;
		fin >> cityname;
		fin >> adjacent;
		fin >> weight;
		fin >> departuretime;
		fin >> arrivaltime;
		fin >> adjacentvertex;
		graph[vertex].insertlast(cityname,vertex);
		while (adjacent != "nomore" && weight!=-999 && departuretime!=-1111 && arrivaltime!=-5555 && adjacentvertex!=-3333) {
			//returnedvertex = graph[vertex].return_vertex(adjacent);
			//cout << returnedvertex << endl;
			graph[vertex].insertedge(adjacentvertex,adjacent,weight,departuretime,arrivaltime);
			weights[vertex][adjacentvertex] = weight;
			fin >> adjacent;
			fin >> weight;
			fin >> departuretime;
			fin >> arrivaltime;
			fin >> adjacentvertex;
		}
	}
	fin.close();
	char filename1[50] = "passenger_reservations.txt";
	fin.open(filename1);
	if (!fin) {
		cout << "Can't Open the file right now ! " << endl;
		return;
	}
	string firstname, lastname, sourcecity, destinationcity, flightno, seattype;
	int seatnumber, sortname,sourcevertex,destinationvertex,totalinitials;
	fin >> totalinitials;
	for (int index = 0; index < totalinitials; index++) {
		fin >> sourcevertex;
		fin >> sourcecity;
		fin >> destinationvertex;
		fin >> destinationcity;
		fin >> firstname;
		fin >> lastname;
		fin >> flightno;
		fin >> seatnumber;
		fin >> seattype;
		fin >> sortname;
		graph1[sourcevertex][destinationvertex].getinitialdata(sourcecity, destinationcity, firstname, lastname, flightno, seatnumber, seattype, sortname);
	}
	fin.close();
}
