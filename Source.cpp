#include<iostream>
#include<string>
#include<fstream>
#include"Graphs.h"
using namespace std;
bool security(char*,char*);
void update(char*&, char*);
int main() {
	fstream fin;
	char filename[50] = "shortestpath_timevertex.txt";
	fin.open(filename);
	if (!fin) {
		cout << "Can't Open the file right now ! " << endl;
		return 0;
	}
	int maxSize = 0;
	fin >> maxSize;
	fin.close();
	char orignalusername[50] = "usamanawaz786";
	char orignalpassword[50] = "freedomfighters";
	char* ptr = orignalpassword;
	char* username=new char[50];
	char* password=new char[50];
	int choice = -1;
	bool check = true;
	Graphs g1(maxSize);
	g1.creategraph();
	do {
		system("cls");
		int index = -1;
		cout << "\n\n\n\n";
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << " \t\t\t  -> Press 1 to Enter the Username and Password: " << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << " \t\t\t  -> Press 2 to Updata the Username/Password: " << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << " \t\t\t  -> Press 0 to exit the Program: " << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;
		cout << "\t\t\t  >> "; cin >> index;
		switch (index) {
		case 1: {
			system("cls");
			cout << endl << endl;
			cout << "\n\n\n\n \t\t\t  -> Please Enter the Admin username: " << endl;
			cin.ignore();
			cout << "\t\t\t  -> "; cin.get(username, 50);
			if (security(username, orignalusername)) {}
			else {
				cout << "\n\n \t\t\t  Username INCORRECT ! ";
				cin.ignore();
				cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t ";
				system("PAUSE");
				continue;
			}
			system("cls");
			cout << "\n\n\n\n \t\t\t  -> Please Enter the Admin Password: " << endl;
			cin.ignore();
			cout << "\t\t\t  -> "; cin.get(password, 50);
			if (security(password, orignalpassword)) { check = false; break; }
			else {
				cout << "\n\n \t\t\t  Password Incorret ! ";
				cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t ";
				system("PAUSE");
				continue;
			}
		}
		case 2: {
			system("cls");
			cout << endl << endl;
			cout << "\n\n\n\n \t\t\t  -> Please Enter the current Admin username: " << endl;
			cin.ignore();
			cout << "\t\t\t  -> "; cin.get(username, 50);
			if (security(username, orignalusername)) {}
			else {
				cout << "\n\n \t\t\t  Username INCORRECT ! ";
				cin.ignore();
				cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t ";
				system("PAUSE");
				continue;
			}
			system("cls");
			cout << "\n\n\n\n \t\t\t  -> Please Enter the current Admin Password: " << endl;
			cin.ignore();
			cout << "\t\t\t  -> "; cin.get(password, 50);
			if (security(password, orignalpassword)) {
				char updatepassword[50];
				system("cls");
				cout << "\n\n\n\n \t\t\t  -> Please Enter the new Admin Password: " << endl;
				cin.ignore();
				cout << "\t\t\t  -> "; cin.get(updatepassword, 50);
				update(ptr, updatepassword);
				continue;
			}
			else {
				cout << "\n\n \t\t\t  Password Incorret ! ";
				cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t ";
				system("PAUSE");
				continue;
			}

		}
		case 0:system("cls"); cout << "\n\n\n\n \t\t\t SEE U S00N :) "; exit(1);
		default: {
			cout << "Invalide Input!! ";
			cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t ";
			system("PAUSE");
			continue;
		}
		}
	} while (check);
	do {
		system("cls");
		cout << endl << endl;
		cout << "=======================================================================================" << endl;
		cout << "|                                   OSPREY AIRWAYS                                    |" << endl;
		cout << "=======================================================================================" << endl << endl;
		//cout << "\n\n \t\t\t Welcome To Flight Reservation System" << endl << endl;
		cout << "\t\t     <><><><><><><><><><><><><><><><><><><><><><><>\n";
		cout << "\t\t           Welcome To Flight Reservation System             \n"; 
		cout << "\t\t     <><><><><><><><><><><><><><><><><><><><><><><>\n";
		cout << ".....................................MENU OPTIONS......................................\n\n";
		//cout << ".......................................................................................\n";
		cout << "\t\t     ...............................................         " << endl;
		cout << "\t\t                FLIGHT SCHEDULE DATABASE ....... '1'" << endl;
		cout << "\t\t     ...............................................         " << endl;
		cout << "\t\t              PASSENGER SCHEDULE DATABASE ....... '2'" << endl;
		cout << "\t\t     ...............................................         " << endl;
		cout << "\t\t              EXIT THE PROGRAM .................. '0'" << endl;
		int a = -1;
		cout << "\t\t\t  -> "; cin >> a;
		switch (a) {
		case 1: {
			system("cls");
			int b = -1;
			do {
				system("cls");
				cout << "\n\n.......................................................................................";
				cout << "\t\t                   LIST OF ALL CITIES SERVICED BY AIRLINE .......... '1'\n";
				cout << ".......................................................................................";
				cout << "\t\t              LIST OF FLIGHTS DEPARTURE FOR A PARTICULAR CITY ...... '2'\n";
				cout << ".......................................................................................";
				cout << "\t\t               LIST OF FLIGHTS ARRIVAL FOR A PARTICULAR CITY ....... '3'\n";
				cout << ".......................................................................................";
				cout << "\t\t             LIST OF ALL CITIES REACHED FROM A PARTICULAR CITY ..... '4'\n";
				cout << ".......................................................................................";
				cout << "\t\t          LIST OF CITIES IN THE SHORTEST PATH B/W ANY TOW CITIES...  '5'\n";
				cout << ".......................................................................................";
				cout << "\t\t                    SHORTEST ROUTE B/2 ANY TWO CITIES..............  '6'\n";
				cout << ".......................................................................................";
				cout << "\t\t                            EXIT THIS MODULE ......................  '0'\n";
				cout << "\t\t\t  -> "; cin >> b;
				switch (b) {
				case 1: {
					system("cls");
					cout << "\n\n \tList of all Cities that are serviced by 'OSPREY AIRWAYS' are as follows:" << endl;
					g1.Displayservedcities();
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				case 2: {
					system("cls");
					string cityname;
					cout << "\n\n \t Enter the name of the city from which you want to check Departure Flights : " << endl;
					cin.ignore();
					cout << "\t\t\t "; getline(cin, cityname);
					cout << " \t List of Flight departures for "<<cityname<< endl;
					g1.Display_Departure(cityname);
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				case 3: {
					system("cls");
					string cityname;
					cout << "\n\n \t Enter the name of the city for which you want to chek Arrival Flights: " << endl;
					cin.ignore();
					cout << "\t\t\t "; getline(cin, cityname);
					cout << " \t List of Flight departures for " << cityname << endl;
					g1.Display_Arrival(cityname);
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				case 4: {
					system("cls");
					string cityname;
					cout << "\n\n \t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "\t\t\t "; getline(cin, cityname);
					cout << " \t List of all cities that can be reached from " << cityname << " are :" << endl;
					g1.toallcities(cityname);
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				case 5: {
					system("cls");
					string sourcecity,citydestination;
					cout << "\n\n \t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "\t\t\t "; getline(cin, sourcecity);
					cout << "\t Enter the name of the destination city: " << endl;
					cout << "\t\t\t "; getline(cin, citydestination);
					cout << " \t List of cities b/w shortest route from " << sourcecity << " to " << citydestination << " are: " << endl;
					g1.shortestpath_Destination(sourcecity, citydestination);
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				case 6: {
					system("cls");
					string sourcecity, citydestination;
					cout << "\n\n \t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "\t\t\t "; getline(cin, sourcecity);
					cout << "\t Enter the name of the destination city: " << endl;
					cout << "\t\t\t "; getline(cin, citydestination);
					g1.Display_shortestpath(sourcecity, citydestination);
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue; 
				}
				case 0:
					system("pause"); break;
				default: {
					cout << "Invalide Input!! ";
					cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				}
			} while (b != 0);
			continue;
		}
		case 2: {
			system("cls");
			int b = -1;
			do {
				system("cls");
				cout << "\n\n.......................................................................................";
				cout << "\t\t                          MAKE RESERVATION ............... '1'\n";
				cout << ".......................................................................................";
				cout << "\t\t                      PRINT RESERVATION SCHEDULE ......... '2'\n";
				cout << ".......................................................................................";
				cout << "\t\t                         DELETE RESERVATION  ............. '3'\n";
				cout << ".......................................................................................";
				cout << "\t\t               LIST OF PASSENGERS FOR A PARTICULAR FLIGHT  '4'\n";
				cout << ".......................................................................................";
				cout << "\t\t                          EXIT THIS MODULE  .............. '0'\n";
				cout << "\t\t\t  -> "; cin >> b;
				switch (b) {
				case 1: {
					system("cls");
					string sourcecity, citydestination;
					cout << "\n\n \t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "\t\t\t "; getline(cin, sourcecity);
					cout << "\t Enter the name of the destination city: " << endl;
					cout << "\t\t\t "; getline(cin, citydestination);
					g1.getreservation(sourcecity, citydestination);
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				case 2: {
					system("cls");
					string sourcecity, citydestination,firstname,lastname;
					cout << "\n\n \t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "\t\t\t "; getline(cin, sourcecity);
					cout << "\t Enter the name of the destination city: " << endl;
					cout << "\t\t\t "; getline(cin, citydestination);
					cout << "\t Enter the first name of the Passenger: " << endl;
					cout << "\t\t\t "; getline(cin, firstname);
					cout << "\t Enter the last name of the Passenger : " << endl;
					cout << "\t\t\t "; getline(cin, lastname);
					g1.DisplayPassengerDetail(sourcecity, citydestination, firstname, lastname);
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				case 3: {
					system("cls");
					string sourcecity, citydestination, firstname, lastname;
					cout << "\n\n \t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "\t\t\t "; getline(cin, sourcecity);
					cout << "\t Enter the name of the destination city: " << endl;
					cout << "\t\t\t "; getline(cin, citydestination);
					cout << "\t Enter the first name of the Passenger: " << endl;
					cout << "\t\t\t "; getline(cin, firstname);
					cout << "\t Enter the last name of the Passenger : " << endl;
					cout << "\t\t\t "; getline(cin, lastname);
					g1.DeletePassenger(sourcecity, citydestination, firstname, lastname);
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				case 4: {
					system("cls");
					string sourcecity, citydestination;
					cout << "\n\n \t Enter the name of the Source City : " << endl;
					cin.ignore();
					cout << "\t\t\t "; getline(cin, sourcecity);
					cout << "\t Enter the name of the destination city: " << endl;
					cout << "\t\t\t "; getline(cin, citydestination);
					g1.Displaylistofpassenger(sourcecity, citydestination);
					cout << endl << "\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				case 0:
					break;
				default: {
					cout << "Invalide Input!! ";
					cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t ";
					system("PAUSE");
					continue;
				}
				}
			} while (b != 0);
			continue;
		}
		case 0:system("cls"); cout << "\t\t SEE U S00N :)" << endl; exit(1);
			system("pause"); break;
		default: {
			cout << "Invalide Input!! ";
			cout << endl << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n \t\t\t ";
			system("PAUSE");
			continue;
		}
		}
		system("PAUSE");
	} while (choice != 0);
}
bool security(char* username,char* orignal) {
	int i = 0, flag = 0;
	while (username[i] != '\0' && orignal[i] != '\0')
	{

		if (username[i] != orignal[i])
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0 && username[i] == '\0' && orignal[i] == '\0')
		return true;
	else
		return false;
}
void update(char*& password1, char* update) {
	strcpy_s(password1, 50, update);
}