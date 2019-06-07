#ifndef SYNTACTICANALYSIS_H
#define SYNTACTICANALYSIS_H

#include<iostream>
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
    void insertInTablaAnalisSintactico(NOTERMINAL nt, TERMINAL ter, TNT tnt){
        tablaAnalisisSintactico[nt][ter].push_back(tnt);
    }
    void PrintBufferCpy(){
        std::cout << "IMPRIMIENDO BUFFER CPY" << std::endl;
        for (auto e : bufferCpy){ // compiler uses type inference to determine the right type
                std::cout << e.first << ' ' << e.second  << std::endl;
        }
    }
    void printTablaAnalisisSintatico(){
        std::cout << "IMPRIMIENDO TABLA DE ANALISIS SINTACTICO LL1 " << std::endl;
        for(auto it = tablaAnalisisSintactico.begin() ;it != tablaAnalisisSintactico.end() ; it++){
            //std::cout << (*it).first << "->";
            for(auto et = (*it).second.begin() ; et != (*it).second.end() ; et++){
                //std::cout << (*et).first << "-->";
                std::cout << "["<< (*it).first << "][" << (*et).first << " ] = ";
                for(auto ot = (*et).second.begin() ; ot != (*et).second.end() ; ot++){
                    //std::cout << "["<< (*it).first << "][" << (*et).first << " ] = " << (*ot) << "\n";
                    std::cout << (*ot) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }



};

#endif // SYNTACTICANALYSIS_H
