#pragma once
#include "Pastilla.h"

class Muestra {
private:
	string code;
	TFR  pastillas[3];
	// Set function for the code
	void setCode(string sampleName) {
		code = sampleName;
	};
	// Set function for the sample array
	void setPastillas() {
		int n = 1;
		for (int i = 0; i < 3; i++)
		{
			// cout << "\n Initializing pastilla "<< n;
			string name = code + " P"+to_string(n)+".tfr";
			pastillas[i].setPastilla(name);
			n++;
		}
	};
public:
	Muestra(string sampleName) {
		setCode(sampleName);
		setPastillas();
	}
	~Muestra(){}
	// Definition of get function
	// Get smaple name on code
	string getCode() { return code; }
	// Get the Pastilla especified by the int num wich correspond to the nummber of the tablet
	TFR getSample(int num) { 
		if (num == 0 || num == 1 || num == 2) {
			cout << "\n Here is you pastilla P" << num;
			return  pastillas[num];
		}
		else {
			cout << "\n You enter an invalid number.";
		}
	}
	//
	// ----------------> Misc <----------------
	//
	/*
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
	float promedioSimple(string element,string header = "Conc") {
		// int rowPos = pastillas[0].getPos(element, pastillas[0].getElements());
		float aritMean = 0;
		for (int i = 0; i < 3; i++)
		{
			// cout << "Pastilla P" << to_string(i+1);
			aritMean += stof(pastillas[i].getValue(element, header));
			// cout << "\n" << to_string(aritMean) << "\n --------------------><-------------------- \n\n";
		}
		aritMean  = aritMean / 3.0;
		// cout << "\n The aritmetical mean is " << aritMean;
		return aritMean;
	}
};