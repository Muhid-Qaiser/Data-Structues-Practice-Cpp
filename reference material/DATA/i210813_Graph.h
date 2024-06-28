
#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Map.h"
using namespace std;

SingleLinkedList S;

/************************************************************************************************************************
-------------------------------------------------------------------------------------------------------------------------
														  Graph Class
-------------------------------------------------------------------------------------------------------------------------
*************************************************************************************************************************/

class Graph {
public:
	int** arr;
	int V;

	Graph() {
		string file_name = "GraphData.csv";
		V = 0;

		ifstream in;
		in.open(file_name);

		string line;
		getline(in, line);


		// Getting the cities name and making a linked list.
		string name = "";
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == ',') {
				S.InsertAtEnd(name);
				// Finding the number of vertices.
				V++;
				name = "";
				continue;
			}
			name += line[i];
		}
		in.close();

		S.InsertAtEnd(name);

		S.DeleteAtStart();
		
		// Initializing the array.
		arr = new int* [V];

		for (int i = 0; i < V; i++)
			arr[i] = new int[V] {};
	}

	bool Add_Edges(int src, int des, int weight) {
		if (src > V || des > V)
			return false;

		arr[src][des] = weight;
		return true;
	}

	int Remove_Edges(int src, int des) {
		if (src > V || des > V)
			return false;

		int n = arr[src][des];
		arr[src][des] = false;
		return n;
	}

	bool is_Edges(int src, int des) {
		if (src > V || des > V)
			return false;

		if (arr[src][des] > 0)
			return true;
		else
			return false;
	}

	string printsingleLink(string city) {
		string s = "";
		s += city;
		s += ":";

		bool single = true;
		int index = S.Search(city);

		if (index == -1) {
			cout << "City doesn't Exist!\n\n";
			return "";
		}

		for (int i = 0; i < V; i++) {
			if (arr[index][i] > 0) {
				if (single)
					s += " ";
				s += "-> ";
				s += S.City(i);
				single = false;
			}
		}
		cout << s;
		return s;
	}

	void printGraph() {
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				cout << setw(6) << arr[i][j];
			}
			cout << endl;
		}
	}

	~Graph() {
		for (int i = 0; i < V; i++)
			delete[] arr[i];
		delete[] arr;
	}
}g;


Graph* getGraph() {
	return &g;
}

// For adding a vertex in the graph and then returning the updated graph.
Graph* addNode(string name) {
	// Adding the city into our map.
	S.InsertAtEnd(name);

	// increasing the number of vertices
	int old_Vertices = g.V;
	g.V++;

	// Copying the data in a dummy array.
	int** dummy = new int* [g.V];
	for (int i = 0; i < g.V; i++)
		dummy[i] = new int[g.V] {};

	for (int i = 0; i < old_Vertices; i++) {
		for (int j = 0; j < old_Vertices; j++) {
			dummy[i][j] = g.arr[i][j];
		}
	}

	// Deleting the original data.
	for (int i = 0; i < old_Vertices; i++)
		delete[] g.arr[i];
	delete[] g.arr;
	g.arr = NULL;

	// Re-initializing the arr with a vertex increased.
	g.arr = new int* [g.V];
	for (int i = 0; i < g.V; i++)
		g.arr[i] = new int[g.V] {};

	// Copying the data to original arr.
	for (int i = 0; i < g.V; i++) {
		for (int j = 0; j < g.V; j++) {
			g.arr[i][j] = dummy[i][j];
		}
	}

	// Deleting the dummy data.
	for (int i = 0; i < g.V; i++)
		delete[] dummy[i];
	delete[] dummy;
	dummy = NULL;

	return &g;
}

// For deleting a vertex in the graph and then returning the updated graph.
Graph* deleteNode(string city) {
	int index = S.Search(city);
	if (index == -1) {
		cout << "City not Found!\n\n";
		return &g;
	}

	S.Update("", index);

	// Breaking all the conections Row wise.
	for (int i = 0; i < g.V; i++) {
		g.arr[i][index] = 0;
	}

	// Breaking all the connection Column wise.
	for (int i = 0; i < g.V; i++) {
		g.arr[index][i] = 0;
	}
	return &g;
}

// For adding a edge in the graph and then returning the updated graph.
Graph* addEdge(string src, string des, int weight) {
	int sr = S.Search(src);
	int ds = S.Search(des);

	if (sr == -1 || ds == -1) {
		cout << "Source or Destination not Found!";
		return &g;
	}

	g.Add_Edges(sr, ds, weight);
	return &g;
}

// For deleting a edge in the graph and then returning the updated graph.
Graph* deleteEdge(string src, string des) {
	int sr = S.Search(src);
	int ds = S.Search(des);

	if (sr == -1 || ds == -1) {
		cout << "Source or Destination not Found!";
		return &g;
	}

	g.Remove_Edges(sr, ds);
	return &g;
}

// Reading the connections from the file.
int** ReadFromFile() {
	string file_name = "GraphData.csv";

	ifstream in;
	in.open(file_name);

	string name = "";
	getline(in, name);

	int m = 0;
	while (!in.eof()) {
		int n = 0;
		getline(in, name, ',');

		int val = 0;
		char ch;

		for (int k = 0; k < g.V; k++, n++) {
			in >> val;
			in >> ch;
			g.Add_Edges(m, n, val);
		}
		m++;
	}

	in.close();

	return g.arr;
}



// To Print the Shortest Path of all Nodes.
string* printShortestPath(int* distance, string* path, string src, string des, string which) {
	cout << endl << endl; 
	for (int i = 0; i < g.V; i++) {
		// For single source single destination.
		if (which == "OTO") {
			i = S.Search(des);
			cout << src << path[i];
			if (path[i] == "") {
				cout << "->" << S.City(i);
			}
			cout << endl;
			cout << "Distance  = " << distance[i] << endl;
			cout << endl;
			return path;
		}
		else if (which == "OTA") {
			cout << src << path[i];
			if (path[i] == "") {
				cout << "->" << S.City(i);
			}
			cout << endl;
			cout << "Distance  = " << distance[i] << endl;
			cout << endl;
		}
	}
	cout << endl << endl;
	return path;
}

// Finding the vertex with minimum distance.
int min(int* distance, bool* visited) {
	int minimum = INT_MAX;
	int index = 0;

	for (int i = 0; i < g.V; i++) {
		if (distance[i] <= minimum && visited[i] == false) {
			minimum = distance[i];
			index = i;
		}
	}
	return index;
}

/************************************************************************************************************************
-------------------------------------------------------------------------------------------------------------------------
													   Dijkstra Algo
-------------------------------------------------------------------------------------------------------------------------
*************************************************************************************************************************/


string* Dijkstra(string src, string which = "", string des = "") {

	int start = S.Search(src);
	//int end = S.Search(des);
	if (start == -1) {
		cout << "City not Found!\n\n";
		return NULL;
	}
	string* path = new string[g.V];
	int* distance = new int[g.V];
	bool* visited = new bool[g.V]{};

	for (int i = 0; i < g.V; i++)
		distance[i] = INT_MAX;

	distance[start] = 0;

	for (int i = 0; i < g.V; i++) {
		int m = min(distance, visited);
		visited[m] = true;

		for (int j = 0; j < g.V; j++) {
			if (visited[j] == false && g.arr[m][j] > 0 && distance[m] != INT_MAX && distance[m] + g.arr[m][j] < distance[j]) {
				distance[j] = distance[m] + g.arr[m][j];
				path[j] = path[m] + "->" + S.City(j);
			}
		}
	}
	return (printShortestPath(distance, path, src, des, which));
}

// For Printing all the shortest paths from all cities to a single city.
void ALL(string des) {
	Node* trav = S.GetHead();
	while (trav != NULL) {
		if (trav->data == "") {
			trav = trav->next;
			continue;
		}
		Dijkstra(trav->data, "OTO", des);
		trav = trav->next;
	}
}

/************************************************************************************************************************
-------------------------------------------------------------------------------------------------------------------------
													   Second Shortest Path
-------------------------------------------------------------------------------------------------------------------------
*************************************************************************************************************************/


// To find the Second Shortest.
void SecondShortestPath(string* path, string src, string which, string des = "") {
	SingleLinkedList R;
	string line;
	int sr = S.Search(src), nsr = 0, ds = 0;
	int i = 0;
	if(which == "OTO")
		i = S.Search(des);

	string sourceCity = src;
	string city = "";
	line = path[i];
	for (int j = 0; line[j] != '\0'; j++) {				// ->Mansehra->Karachi
		if (line[j] == '-') {
			j++;
			if (city != "") {
				nsr = S.Search(sourceCity);
				ds = S.Search(city);
				R.InsertAtEnd(to_string(ds));
				int weight = g.Remove_Edges(nsr, ds);
				R.InsertAtEnd(to_string(weight));
				sourceCity = city;
			}
			city = "";
			continue;
		}
		city += line[j];
	}

	nsr = S.Search(sourceCity);
	ds = S.Search(city);
	R.InsertAtEnd(to_string(ds));
	int weight = g.Remove_Edges(nsr, ds);
	R.InsertAtEnd(to_string(weight));

	Dijkstra(src, which, des);

	// Reconnecting the edges.
	nsr = sr;
	Node* temp = R.GetHead();
	while (temp != NULL) {
		ds = stoi(R.DeleteAtStart());
		int weight = stoi(R.DeleteAtStart());
		g.Add_Edges(nsr, ds, weight);
		if (R.isEmpty())
			return;
		temp = R.GetHead();
		nsr = ds;
	}
}