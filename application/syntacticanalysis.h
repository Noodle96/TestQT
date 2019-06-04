#ifndef SYNTACTICANALYSIS_H
#define SYNTACTICANALYSIS_H

#include<stack>
#include<list>
#include<map>

using NOTERMINAL = std::string;
using TERMINAL = std::string;
using TNT = std::string;


class SintacticAnalysis{
public:
    std::map< NOTERMINAL,std::map< TERMINAL,std::list<TNT> > > tablaAnalisisSintactico;
    std::stack<TNT> pila;
    std::list<std::pair<std::string,std::string>> bufferCpy;
public:



};

#endif // SYNTACTICANALYSIS_H
