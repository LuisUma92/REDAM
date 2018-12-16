/*
$Id: TFRparse.hh 1000501  2018-12-15 22:17 LFUC $

\file TFRparse.hh
\brief Definition of the TFR class
version 0.2.0
 */
#pragma once
//================================= ooOOOoo =================================
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "Pastilla.hh"
//================================= ooOOOoo =================================
class TFR : public Pastilla{
private:
	std::vector<std::vector<std::string>> table;
	std::vector<std::string> headers;
	std::vector<std::string> elements;
	int rows, cols;
public:
	TFR(){ };
	TFR(std::string myName);
	~TFR(){ };
	//
	// ----------------> Definition of the seting functions <----------------
	//
	void setDirPath(std::string myPath = ".\\tfr\\");
	void setPastilla(std::string myName);
	//
	// ----------------> Definition of the geting function <----------------
	//
	// Get Header
	std::vector<std::string> getHeader() { return headers; };
	// Get Elements
	std::vector<std::string> getElements() { return elements; };
	// Get rows number
	int getRows() { return rows; };
	// Get columns number
	int getCols() { return cols; };
/* //================================= ooOOOoo =================================
Pastilla.h::Pastilla::TFR::getFull()

Parameters:

Returns:
	string

Operation:
	Return the full table on a single string
*/
	std::string getFull();
	//
	// ----------------> Misc <----------------
	//
/* //================================= ooOOOoo =================================
Pastilla.h::Pastilla::TFR::getValue(element, header)
	This function extract an specific value from tha table

Parameters:
	string element:
	string header:

Returns:
	string
	*/
	std::string getValue(std::string element, std::string header);
};