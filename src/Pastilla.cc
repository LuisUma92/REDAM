/*
$Id: Pastilla.cc 1000501  2018-12-14 02:07 LFUC $

\file Pastilla.hh
\brief Implementation of the Pastilla class
version 0.2.1
*/
#pragma once
//================================= ooOOOoo =================================
#include "Pastilla.hh"
//================================= ooOOOoo =================================
int Pastilla::getPos(std::string find, std::vector<std::string> searchHere) {
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
//================================= ooOOOoo =================================
std::vector<std::string> Pastilla::readMyFile(std::string myFilePath){
    std::ifstream myFile(myFilePath); 
    std::vector<std::string> lineasTemp;
    std::string  Linea;
    // Error check
    if (myFile.fail()) {
        std::cerr << "\n * File no opened!";
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
//================================= ooOOOoo =================================
void Pastilla::isItDir(std::string myPath, std::string fileType)
{
    std::string tempS;
    while(exists(myPath)==false)
    {
        std::cout << "Write the path to the directory that contain "+ fileType +" files" << std::endl;
        std::cin >> tempS;
        setDirPath(tempS);
        if(exists(myPath)==false)
        {
            std::cout << "We are having problems with the directory, try again." << std::endl;
        };
    };
};
