/*
$Id: Pastilla.hh 1000501  2018-12-14 02:07 LFUC $

\file Pastilla.hh
\brief Definition of the Pastilla class
version 0.2.1
*/
#pragma once
//================================= ooOOOoo =================================
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
//================================= ooOOOoo =================================
class Pastilla{
protected:
	//================================= ooOOOoo =================================
	// Variables definitions
	std::string dirPath;				
	std::string pName;
	std::vector<std::string> info;
public:
	Pastilla() {};
	virtual ~Pastilla() {};
	//
	// ----------------> Definition of the seting functions <----------------
	//
	virtual void setPastilla(std::string myName) = 0;
	virtual void setDirPath(std::string myPath) = 0;
	void setInfo(std::string infoPath);
	//
	// ----------------> Definition of the geting functions <----------------
	//
	std::vector<std::string> getInfo(){return info;};
	std::string getDirPath(){return dirPath; };
	//
	// ----------------> Misc <----------------
	//
/* ================================= ooOOOoo =================================
Pastilla.h::Pastilla::TFR::getFull()

Parameters:

Returns:
	string

Operation:
	Return the full table on a single string
*/
	virtual std::string getFull() = 0;
/*//================================= ooOOOoo =================================
Pastilla.h::Pastilla::getPos(find, searchHere)

Parameters:
	string find:
	vector<string> searchHere:

Returns:
*/
	int getPos(std::string find, std::vector<std::string> searchHere);
/*//================================= ooOOOoo =================================
Pastilla.h::Pastilla::readMyFile(myFilePath)

Parameters:
	string myFilePath:

Returns:
	vector<string> lineasTemp:
*/
	std::vector<std::string> readMyFile(std::string myFilePath);
/*//================================= ooOOOoo =================================
Bla
*/ 
	bool exists(std::string filePathS)
	{
		return true;
	}
/*//================================= ooOOOoo =================================
Pastilla.h::Pastilla::isItDir(myPath)

Parameters:
	string myPath:

Returns:
*/
	void isItDir(std::string myPath, std::string fileType);
};