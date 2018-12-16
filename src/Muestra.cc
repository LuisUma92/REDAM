/*
$Id: Muestra.hh 1000501  2018-12-15 22:17 LFUC $

\file Muestra.hh
\brief Definition of the Muestra class
version 0.1.1
 */
#pragma once
//================================= ooOOOoo =================================
#include "Muestra.hh"
//================================= ooOOOoo =================================
void Muestra::setCode(std::string sampleName) {
    code = sampleName;
};
//================================= ooOOOoo =================================
void Muestra::setPastillas() {
    int n = 1;
    for (int i = 0; i < 3; i++)
    {
        // cout << "\n Initializing pastilla "<< n;
        std::string name = code + " P"+std::to_string(n)+".tfr";
        pastillas[i].setPastilla(name);
        n++;
    }
};
//================================= ooOOOoo =================================
Muestra::Muestra(std::string sampleName) {
    setCode(sampleName);
    setPastillas();
}
//================================= ooOOOoo =================================
TFR Muestra::getSample(int num) { 
    if (num == 0 || num == 1 || num == 2) {
        std::cout << "\n Here is you pastilla P" << num;
        return  pastillas[num];
    }
    else {
        std::cout << "\n You enter an invalid number.";
    }
}
//================================= ooOOOoo =================================
float Muestra::promedioSimple(std::string element,std::string header = "Conc") {
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