#ifndef SYNTACTICANALYSIS_H
#define SYNTACTICANALYSIS_H

#include<iostream>
#include<stack>
#include<list>
#include<map>


using NOTERMINAL = std::string;
using TERMINAL = std::string;
using TNT = std::string;
using INICIAL = std::string;

class Gramatica{
public:
  std::pair<std::string,std::string> produccion;
};

/// ---------------Gramatic of lenguage-------------
/// PROGRAMA -> LISTA_SENTENCIAS
/// LISTA_SENTENCIAS -> SENTENCIA | LISTA_SENTENCIAS SENTENCIA
/// SENTENCIA ->  E ; | WHILE | IF_ELSE | SWITCH_CASE
/// WHILE ->WHILE ( CONDICION ) SENTENCIA | WHILE ( CONDICION ) { LISTA_SENTENCIAS }
/// IF_ELSE -> IF else  SENTENCIA | IF else { LISTA_SENTENCIAS }
/// SWITCH_CASE -> SWITCH ( i ) {LISTA_CASE} | SWITCH ( i ) {lista_CASE DEFAULT}
/// LISTA_CASE -> CASE | LISTA_CASE CASE
/// CASE -> CASE c : SENTENCIA | CASE c : {LISTA_SENTENCIAS}
///  DEFAULT -> DEFAULT : SENTENCIA | DEFAULT : {LISTA_SENTENCIAS}
/// CONDICION -> CONDICION_LOGICA | CONDICION_AND | CONDICION_OR
/// CONDICION_AND -> CONDICION_LOGICA && CONDICION LOGICA
/// CONDICION_OR -> CONDICION_LOGICA || CONDICION_LOGICA
/// CONDICION_LOGICA -> E > E | E < E | E >= E | E <= E | E==E | E!=E
/// E -> E + T | E - T | T
/// T -> T * T | T / F | F
/// F -> i | c
///
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
// estamos en el proyecto actual


#endif // SYNTACTICANALYSIS_H
