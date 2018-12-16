/*
$Id: TFRparse.cc 1000501  2018-12-15 22:17 LFUC $

\file TFRparse.cc
\brief Implementation of the TFR class
version 0.2.0
 */
#pragma once
//================================= ooOOOoo =================================
#include "TFRparse.hh"
//================================= ooOOOoo =================================
TFR::TFR(std::string myName){
    TFR::setPastilla(myName);
};
//================================= ooOOOoo =================================
void TFR::setDirPath(std::string myPath = ".\\tfr\\"){
    dirPath = myPath;
    isItDir(dirPath, "TFR");
};
//================================= ooOOOoo =================================
void TFR::setPastilla(std::string myName) {
    // Function variable declaration
    setDirPath();
    pName = myName;
    // cout << "\n Initializing pastilla on path" << dirPath;
    std::vector<std::string> lineasTemp;
    std::vector<std::string> tempVec;
    int length;
    std::string Linea;
    std::string tmp;
    lineasTemp = readMyFile(dirPath+pName);
    // Complete the table matrix
    length = std::stoi(lineasTemp[26].c_str()) + 28;
    // cout << "\n 'length' have a size of " +  to_string(length) ;
    for (int i = 28; i < length; i++){
        tempVec.clear();
        std::stringstream line(lineasTemp[i]);
        while (getline(line, tmp, ','))	{
            tmp.erase(std::remove(tmp.begin(), tmp.end(), '"'), tmp.end());
            tempVec.push_back(tmp);
        };
        table.push_back(tempVec);
        // cout << "\n " + to_string(i);
    };
    rows = table.size();
    // cout << "\n You expect to have " << to_string(rows) << " rows";
    cols = table[0].size();
    // cout << "\n You expect to have " << to_string(cols) << " cols";
    // Write the headers list
    std::stringstream line(lineasTemp[27]);
    //cout << "\n Creating headers with \n" << line.str();
    while (getline(line, tmp, ','))
    {
        tmp.erase (std::remove(tmp.begin(), tmp.end(), '"'), tmp.end());
        headers.push_back(tmp);
    };
    // Write the elemnts list
    // cout << "\n Creating elemts \n";
    length = std::stoi(lineasTemp[26].c_str());
    for (int i = 0; i < length; i++)
    {
        elements.push_back(table[i][0]);
        // std::out << "\n " + to_string(i);
        // std::cout << "\n " + elements[i];
    };
    //  std::cout << "\n End of the initiation \n --------------------><-------------------- \n\n";
    //  std::cout << getFull();
}
//================================= ooOOOoo =================================
std::string TFR::getFull() {
    //cout << "\n Returning full table";
    std::string myTable = "";
    for (int i = 0; i < cols; i++)
    {
        myTable += headers[i];
    };
    myTable += "\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            myTable += table[i][j]+",";
        };
        myTable += "\n";

    };
    return myTable;
};
//================================= ooOOOoo =================================
std::string TFR::getValue(std::string element, std::string header){
    int headerPos;
    int elementPos;
    std::string tableElement = "";
    // cout << "\n Searching for " << header << "\n";
    headerPos = getPos(header, headers);
    // cout << "\n Searching for " << element << "\n";
    elementPos = getPos(element, elements);
    tableElement += table[elementPos][headerPos];
    // cout << "\n Requested value es " + tableElement + "\n --------------------><-------------------- \n\n";
    return tableElement; 
}
//================================= ooOOOoo =================================