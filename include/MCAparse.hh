/*
$Id: MCAparse.hh 1000501  2018-12-15 22:17 LFUC $

\file MCAparse.hh
\brief Definition of the MCA class
version 0.2.0
 */
#pragma once
//================================= ooOOOoo =================================
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pastilla.hh"
//================================= ooOOOoo =================================
class MCA : public Pastilla{
  private:
	std::vector<int> rois[2];
	std::vector<int> rawData;
	float calibration[2][2];
  public:
	MCA(){ };
	MCA(std::string myName);
	~MCA(){ };
	//
	// ----------------> Definition of the seting functions <----------------
	//
	void setDirPath(std::string myPath = ".\\mca\\");
	void setPastilla(std::string myName);
	//
	// ----------------> Definition of the geting function <----------------
	//
/* //================================= ooOOOoo =================================
Pastilla.h::Pastilla::MCA::getFull()

Parameters:

Returns:
    string

Operation:
    Return the full table on a single string
*/
	std::string getFull() ;
/* //================================= ooOOOoo =================================
Pastilla.h::Pastilla::MCA::getHisto(save = false)

Parameters:
    bool save: conditional that diferenciate from save a file or not.

Returns:

Operation:
    Generate a histogram that represent the spectrum.
*/
	void getHisto(bool save = false);
/* //================================= ooOOOoo =================================
Pastilla.h::Pastilla::MCA::getRois()

Parameters:

Returns:
    string

Operation:
    Get string of el the rows on csv format.
*/
	int getRois();
/* //================================= ooOOOoo =================================
Pastilla.h::Pastilla::MCA::getRois(formula = true)

Parameters:
    bool formula: 

Returns:
    string

Operation:
    Get string with calibration.
*/
    int getCalibration(bool formula = true);
//
// ----------------> Misc <----------------
//
};