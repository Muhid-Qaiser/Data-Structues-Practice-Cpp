
#include "Header.h"

int main() {
	system("Color FD");
	ReadFromFile();
	int option;

	Graph* g = getGraph();

	while (true) {
		system("CLS");

		cout << "Press 1 to Insert a City in the Graph!\n\n";
		cout << "Press 2 to Delete a City from the Graph!\n\n";
		cout << "Press 3 to update a existing link in the Graph!\n\n";
		cout << "Press 4 to Insert a Edge between two Cities!\n\n";
		cout << "Press 5 to Delete a Edge between two Cities!\n\n\n";

		cout << "Press 6 to Print Single Link!\n\n";
		cout << "Press 7 to print the Graph!\n\n\n";

		cout << "Press 8 to Compute Shortest Path from One City to All!\n\n";
		cout << "Press 9 to Compute Second Shortest Path from One City to All!\n\n\n";

		cout << "Press 10 to Compute Shortest Path from All Cities to One!\n\n";
		cout << "Press 11 to Compute Second Shortest Path from All Cities to One!\n\n\n";

		cout << "Press 12 to Compute Shortest Path from One City to Another!\n\n";
		cout << "Press 13 to Compute Second Shortest Path from One City to Another!\n\n\n";

		cout << "Press 14 to Exit!\n\n";
		cout << "Select: ";

		cin >> option;

		switch (option) {
		case 1: {
			system("CLS");
			string city;
			cout << "Enter the name of the city to Insert in the Graph: ";
			cin >> city;
			g = addNode(city);
			cout << endl << endl;
			S.Traverse();
			system("Pause");
			break;
		}
		case 2: {
			system("CLS");
			string city;
			cout << "Enter the name of the city to Delete in the Graph: ";
			cin >> city;
			g = deleteNode(city);
			cout << endl << endl;
			S.Traverse();
			system("Pause");
			break;
		}
		case 3: {
			system("CLS");
			string src;
			string des;
			int weight = 0;
			cout << "Enter the Source: ";
			cin >> src;
			cout << "\n\n";
			cout << "Enter the Destination: ";
			cin >> des;
			cout << "\n\n";
			cout << "Enter the Weight: ";
			cin >> weight;
			g = addEdge(src, des, weight);
			cout << endl << endl;
			system("Pause");
			break;
		}
		case 4: {
			system("CLS");
			string src;
			string des;
			int weight = 0;
			cout << "Enter the Source: ";
			cin >> src;
			cout << "\n\n";
			cout << "Enter the Destination: ";
			cin >> des;
			cout << "\n\n";
			cout << "Enter the Weight: ";
			cin >> weight;
			g = addEdge(src, des, weight);
			cout << endl << endl;
			system("Pause");
			break;
		}
		case 5: {
			system("CLS");
			string src;
			string des;
			cout << "Enter the Source: ";
			cin >> src;
			cout << "\n\n";
			cout << "Enter the Destination: ";
			cin >> des;
			g = deleteEdge(src, des);
			cout << endl << endl;
			system("Pause");
			break;
		}
		case 6: {
			system("CLS");
			string city;
			cout << "Enter the name of the City: ";
			cin >> city;
			g->printsingleLink(city);
			cout << endl << endl;
			system("Pause");
			break;
		}
		case 7: {
			system("CLS");
			cout << endl << endl;
			g->printGraph();
			cout << endl << endl;
			system("Pause");
			break;
		}
		case 8: {
			system("CLS");
			string city;
			cout << "Enter the name of the City: ";
			cin >> city;
			Dijkstra(city, "OTA");
			system("Pause");
			break;
		}
		case 9: {
			system("CLS");
			system("CLS");
			string src;
			cout << "Enter the name of the Souce City: ";
			cin >> src;

			Node* trav = S.GetHead();

			while (trav != NULL) {
				if (trav->data == "") {
					trav = trav->next;
					continue;
				}
				string* str = Dijkstra(src, "OTO", trav->data);
				SecondShortestPath(str, src, "OTO", trav->data);
				trav = trav->next;
			}
			system("Pause");
			break;
		}
		case 10: {
			system("CLS");
			string city;
			cout << "Enter the name of the Destination City: ";
			cin >> city;
			ALL(city);
			system("Pause");
			break;
		}
		case 11: {
			system("CLS");
			string des;
			cout << "Enter the name of the Destination City: ";
			cin >> des;
			Node* trav = S.GetHead();
			while (trav != NULL) {
				if (trav->data == "") {
					trav = trav->next;
					continue;
				}
				string* str = Dijkstra(trav->data, "OTO", des);
				SecondShortestPath(str, trav->data, "OTO", des);
				trav = trav->next;
			}
			system("Pause");
			break;
		}
		case 12: {
			system("CLS");
			string src, des;
			cout << "Enter the name of the Souce City: ";
			cin >> src;
			cout << "Enter the name of the Destination City: ";
			cin >> des;
			Dijkstra(src, "OTO", des);
			system("Pause");
			break;
		}
		case 13: {
			system("CLS");
			string src, des;
			cout << "Enter the name of the Souce City: ";
			cin >> src;
			cout << "Enter the name of the Destination City: ";
			cin >> des;
			string* str = Dijkstra(src, "OTO", des);
			SecondShortestPath(str, src, "OTO", des);
			system("Pause");
			break;
		}
		case 14: {
			exit(1);
		}
			  break;
		}
	}
}