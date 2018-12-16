/*
$Id: MCAparse.cc 1000501  2018-12-15 22:17 LFUC $

\file MCAparse.cc
\brief Implementation of the MCA class
version 0.2.0
 */
#pragma once
//================================= ooOOOoo =================================
#include "MCAparse.hh"
//================================= ooOOOoo =================================
MCA::MCA(std::string myName){
    setPastilla(myName);
};
//
// ----------------> Definition of the seting functions <----------------
//
//================================= ooOOOoo =================================
void MCA::setDirPath(std::string myPath = ".\\mca\\"){
    dirPath = myPath;
    isItDir(dirPath, "MCA");
};
//================================= ooOOOoo =================================
void MCA::setPastilla(std::string myName){
    setDirPath();
    pName = myName;
    // Function variable declaration
    // cout << "\n Initializing pastilla on path" << dirPath;
    std::vector<std::string> lineasTemp;
    int start, length, tmp, j = 0;
    float ftmp;
    std::string sTmp;
    lineasTemp = readMyFile(dirPath+pName);
    length = lineasTemp.size();
    for (int i = 28; i < length; i++){
        if(lineasTemp[i] == "<<CALIBRATION>>"){
            std::stringstream lineA(lineasTemp[i + 2]);
            while (getline(lineA, sTmp, ' ')){
                ftmp = stof(sTmp);
                calibration[0][j] = ftmp;
                j++;
            }
            j = 0;
            std::stringstream lineB(lineasTemp[i + 3]);
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
            // std::cout << "\n " + to_string(i);
        }
    }
    //  std::cout << "\n End of the initiation \n --------------------><-------------------- \n\n";
    //  std::cout << getFull();
}
//
// ----------------> Definition of the geting function <----------------
//
//================================= ooOOOoo =================================
std::string MCA::getFull() { 
    int rows = rawData.size();
    //cout << "\n Returning full table";
    std::string myTable = "";
    for (int i = 0; i < rows; i++){
        myTable += rawData[i]+"\n";
    }
    return myTable;
};
//================================= ooOOOoo =================================
void MCA::getHisto(bool save = false) {};
//================================= ooOOOoo =================================
int MCA::getRois() {};
//================================= ooOOOoo =================================
int MCA::getCalibration(bool formula = true) {};
//================================= ooOOOoo =================================