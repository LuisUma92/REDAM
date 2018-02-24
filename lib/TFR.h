/*
versión 0.1.0
*/
#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

class Pastilla{
private:
	string pastillaPath;
	vector<vector<string>> table;
	vector<string> headers;
	vector<string> elements;
	int rows, cols;
public:
	Pastilla() {};
    Pastilla(string tfr_name){
		setPastilla(tfr_name);
	};
	~Pastilla() {};
	//
	// ----------------> Definition of the seting functions <----------------
	//
	void setPastilla(string tfr_name) {
		// Function variable declaration
		pastillaPath = ".\\tfr\\" + tfr_name;
		// cout << "\n Initializing pastilla on path" << pastillaPath;
		ifstream myPastilla(pastillaPath);
		vector<string> lineasTemp;
		vector<string> tempVec;
		int length;
		string  Linea;
		string tmp;
		// Error check
		if (myPastilla.fail()) {
			cerr << "\n * File no opened!";
			//exit(EXIT_FAILURE);
		}
		// Extract lines from file
		if (myPastilla) {
			while (myPastilla.good()) {
				getline(myPastilla, Linea);
				lineasTemp.push_back(Linea);
			};
			//cout << "\n lineasTemp have a size of" << lineasTemp.size();
		}
		myPastilla.close();
		// Complete the table matrix
		length = stoi(lineasTemp[26].c_str()) + 28;
		// cout << "\n 'length' have a size of " +  to_string(length) ;
		for (int i = 28; i < length; i++)
		{
			tempVec.clear();
			stringstream line(lineasTemp[i]);
			while (getline(line, tmp, ','))
			{
				tmp.erase (remove(tmp.begin(), tmp.end(), '"'), tmp.end());
				tempVec.push_back(tmp);
			}
			table.push_back(tempVec);
			// cout << "\n " + to_string(i);
		}
		rows = table.size();
		// cout << "\n You expect to have " << to_string(rows) << " rows";
		cols = table[0].size();
		// cout << "\n You expect to have " << to_string(cols) << " cols";
		// Write the headers list
		stringstream line(lineasTemp[27]);
		//cout << "\n Creating headers with \n" << line.str();
		while (getline(line, tmp, ','))
		{
			tmp.erase (remove(tmp.begin(), tmp.end(), '"'), tmp.end());
			headers.push_back(tmp);
		}
		// Write the elemnts list
		// cout << "\n Creating elemts \n";
		length = stoi(lineasTemp[26].c_str());
		for (int i = 0; i < length; i++)
		{
			elements.push_back(table[i][0]);
			// cout << "\n " + to_string(i);
			// cout << "\n " + elements[i];
		}
		//  cout << "\n End of the initiation \n --------------------><-------------------- \n\n";
		//  cout << getFull();
	}
	//
	// ----------------> Definition of get function <----------------
	//
	// Get Header
	vector<string> getHeader() { return headers; }
	// Get Elements
	vector<string> getElements() { return elements; }
	// Get tfr path
	string getPath() { return pastillaPath; }
	// Get rows number
	int getRows() { return rows; }
	// Get columns number
	int getCols() { return cols; }
	// Return the full table on a single string
	string getFull() {
		//cout << "\n Returning full table";
		string myTable = "";
		for (int i = 0; i < cols; i++)
		{
			myTable += headers[i];
		}
		myTable += "\n";
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				myTable += table[i][j]+",";
			}
			myTable += "\n";

		}
		return myTable;
	}
	//
	// ----------------> Misc <----------------
	//
	/* 
	TFR.h::Pastilla::getValue(element, header)
		This function extract an specific value from tha table

	Parameters:
		string element:
		string header:

	Returns:
		string
	*/
	string getValue(string element, string header){
		int headerPos;
		int elementPos;
		string tableElement = "";
		// cout << "\n Searching for " << header << "\n";
		headerPos = getPos(header, headers);
		// cout << "\n Searching for " << element << "\n";
		elementPos = getPos(element, elements);
		tableElement += table[elementPos][headerPos];
		// cout << "\n Requested value es " + tableElement + "\n --------------------><-------------------- \n\n";
		return tableElement; 
	}
	/*
	TFR.h::Pastilla::getPos(find, searchHere)

	Parameters:
		string find:
		vector<string> searchHere:

	Returns:
	*/
	int getPos(string find, vector<string> searchHere) {
		int length = searchHere.size();
		for (int i = 0; i < length; i++) {
			// cout << searchHere[i] << " is in the position " << i << "\n";
			if (find.compare(searchHere[i]) == 0)
			{
				// cout << find << " is in the position " << i << "\n --------------------><-------------------- \n\n";
				return i;
			}
			else
			{
				// cout << find << " is not fount in the vector \n";
			}
		}
	}
	
};