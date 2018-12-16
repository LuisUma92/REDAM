/*
$Id: Muestra.hh 1000501  2018-12-15 22:17 LFUC $

\file Muestra.hh
\brief Definition of the Muestra class
version 0.1.1
 */
#pragma once
//================================= ooOOOoo =================================
#include "TFRparse.hh"
#include "MCAparse.hh"

class Muestra {
private:
	std::string code;
	TFR  pastillas[3];
	// Set function for the code
	void setCode(std::string sampleName);
	void setPastillas();
public:
	Muestra(std::string sampleName) ;
	~Muestra(){}
	// Definition of get function
	// Get smaple name on code
	std::string getCode() { return code; };
	// Get the Pastilla especified by the int num wich correspond to the nummber of the tablet
	TFR getSample(int num) ;
	//
	// ----------------> Misc <----------------
	//
/*//================================= ooOOOoo =================================
Muestra.h::Muestra::promedioSimple(element, header = "Conc")
	This function return the aritmetical mean of the specific element for the header selected.

Parameter:
	string element: 
		From wich you want to get the aritmetical mean. 
		We recomend to verifies the element list for the Pastilla object to avoid errors
	string header:
		The header specifies the column that you want to acces.
		This function uses as standart header the "Conc" header that correspond to the concentration

Return
	This function return a float with the aritmetical mean of  the three valuos fora an element and a header
*/
	float promedioSimple(std::string element,std::string header = "Conc") ;
};