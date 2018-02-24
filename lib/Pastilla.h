/*
versión 0.2.0
*/
#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>

class Pastilla{
protected:
	string pastillaPath = "";
	string pName;
	vector<string> info;
public:
	Pastilla() {};
	virtual ~Pastilla() {};
	//
	// ----------------> Definition of the seting functions <----------------
	//
	virtual void setPastilla(string myName) = 0;
	void setInfo(string infoPath = ".\\Informacion.csv"){
		
	};
	//
	// ----------------> Definition of the geting functions <----------------
	//
	vector<string> getInfo(){return info;};
	string getPastillaPath(){return pastillaPath; };
	//
	// ----------------> Misc <----------------
	//
	/* 
	TFR.h::Pastilla::TFR::getFull()

	Parameters:
	
	Returns:
		string
	
	Operation:
		Return the full table on a single string
	*/
	virtual string getFull() = 0;
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
	};
	/*
	TFR.h::Pastilla::readMyFile(myFilePath)

	Parameters:
		string myFilePath:

	Returns:
		vector<string> lineasTemp:
	*/
	vector<string> readMyFile(string myFilePath){
		ifstream myFile(myFilePath); 
		vector<string> lineasTemp;
		string  Linea;
		// Error check
		if (myFile.fail()) {
			cerr << "\n * File no opened!";
			//exit(EXIT_FAILURE);
		}
		// Extract lines from file
		if (myFile) {
			while (myFile.good()) {
				getline(myFile, Linea);
				lineasTemp.push_back(Linea);
			};
			//cout << "\n lineasTemp have a size of" << lineasTemp.size();
		}
		myFile.close();
		return lineasTemp;
	};
};

class TFR : public Pastilla{
private:
	vector<vector<string>> table;
	vector<string> headers;
	vector<string> elements;
	int rows, cols;
public:
	TFR();
	TFR(string myName){
		setPastilla(myName);
	};
	~TFR();
	//
	// ----------------> Definition of the seting functions <----------------
	//
	void setPastilla(string myName) {
		// Function variable declaration
		pastillaPath = ".\\tfr\\" + myName;
		pName = myName;
		// cout << "\n Initializing pastilla on path" << pastillaPath;
		vector<string> lineasTemp;
		vector<string> tempVec;
		int length;
		string Linea;
		string tmp;
		lineasTemp = readMyFile(pastillaPath);
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
	// ----------------> Definition of the geting function <----------------
	//
	// Get Header
	vector<string> getHeader() { return headers; }
	// Get Elements
	vector<string> getElements() { return elements; }
	// Get rows number
	int getRows() { return rows; }
	// Get columns number
	int getCols() { return cols; }
	/* 
	TFR.h::Pastilla::TFR::getFull()

	Parameters:
	
	Returns:
		string
	
	Operation:
		Return the full table on a single string
	*/
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
	TFR.h::Pastilla::TFR::getValue(element, header)
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
};

class MCA : public Pastilla{
private:
	vector<int> rois[2];
	vector<int> rawData;
	float calibration[2][2];
public:
	//
	// ----------------> Definition of the seting functions <----------------
	//
	void setPastilla(string myName){
		pName = myName;
		// Function variable declaration
		pastillaPath = ".\\mca\\" + pName;
		// cout << "\n Initializing pastilla on path" << pastillaPath;
		vector<string> lineasTemp;
		int start, length, tmp, j = 0;
		float ftmp;
		string sTmp;
		lineasTemp = readMyFile(pastillaPath);
		length = lineasTemp.size();
		for (int i = 28; i < length; i++){
			if(lineasTemp[i] == "<<CALIBRATION>>"){
				stringstream lineA(lineasTemp[i + 2]);
				while (getline(lineA, sTmp, ' ')){
					ftmp = stof(sTmp);
					calibration[0][j] = ftmp;
					j++;
				}
				j = 0;
				stringstream lineB(lineasTemp[i + 3]);
				while (getline(lineB, sTmp, ' ')){
					tmp = stoi(sTmp);
					calibration[1][j] = tmp;
					j++;
				}
			}
			if(lineasTemp[i] == "<<DATA>>"){
				i++;
				while (lineasTemp[i] == "<<END>>"){
					tmp = stoi(lineasTemp[i]);
					rawData.push_back(tmp);
					i++;
				}
				i = length;
				// cout << "\n " + to_string(i);
			}
		}
		//  cout << "\n End of the initiation \n --------------------><-------------------- \n\n";
		//  cout << getFull();
	}
	//
	// ----------------> Definition of the geting function <----------------
	//
	/* 
	TFR.h::Pastilla::MCA::getFull()

	Parameters:
	
	Returns:
		string
	
	Operation:
		Return the full table on a single string
	*/
	string getFull() { 
		int rows = rawData.size();
		//cout << "\n Returning full table";
		string myTable = "";
		for (int i = 0; i < rows; i++){
			myTable += rawData[i]+"\n";
		}
		return myTable;
	};
	/* 
	TFR.h::Pastilla::MCA::getHisto(save = "false")

	Parameters:
		bool save: conditional that diferenciate from save a file or not.

	Returns:
	
	Operation:
		Generate a histogram that represent the spectrum.
	*/
	void getHisto(bool save = "false") {};
	/* 
	TFR.h::Pastilla::MCA::getRois()

	Parameters:

	Returns:
		string
	
	Operation:
		Get string of el the rows on csv format.
	*/
	int getRois() {};
	/* 
	TFR.h::Pastilla::MCA::getRois(formula = "true")

	Parameters:
		bool formula: 

	Returns:
		string
	
	Operation:
		Get string with calibration.
	*/
	int getCalibration(bool formula = "true") {};
	//
	// ----------------> Misc <----------------
	//
};