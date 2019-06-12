#ifndef SYNTACTICANALYSIS_H
#define SYNTACTICANALYSIS_H

#include<iostream>
#include<stack>
#include<list>
#include<map>

#include"lexemaattributes.h"

using NOTERMINAL = std::string;
using TERMINAL = std::string;
using TNT = std::string;
using INICIAL = std::string;
using TOKEN = std::string;

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
    //std::stack<TNT> pila;
    std::list<std::pair<TOKEN,LexemaAttributes* >> bufferCpy;
public:
    void insertInTablaAnalisSintactico(NOTERMINAL nt, TERMINAL ter, TNT tnt){
        tablaAnalisisSintactico[nt][ter].push_back(tnt);
    }
    void PrintBufferCpy(){
        std::cout << "IMPRIMIENDO BUFFER CPY" << std::endl;
        for (auto e : bufferCpy){ // compiler uses type inference to determine the right type
                std::cout << e.first << ' ' << (e).second << std::endl;
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
    void pushPila(std::stack<TNT> &pl,TNT elem){
        pl.push(elem);
    }

    bool verifyBufferCpyValidation( const std::list<std::pair<std::string,LexemaAttributes*>> &buffer){
        //pusheando la pila con $
        std::stack<TNT> pila;
        pila.push("$");
        pila.push("E"); //initial in buildsintacticanalysis.cpp


        //copiando buffer a bufferCopy
        for(auto it = buffer.begin() ; it != buffer.end(); it++){
            bufferCpy.push_back(std::make_pair((*it).first,(*it).second));
        }

        //bufferCpy.push_back( std::make_pair("$","$" ));

        //haciendo el reconocimiento de el buffercopy con la pila(push and pop)
        //![1] v1
        std::list<TNT> listTemp;
        for (auto it = bufferCpy.begin(); it != bufferCpy.end();it++){
            //primer caso
            if( pila.top() == (*it).first ){ //relacionamos a , es decir sale de la pila y del buffer
                pila.pop();continue;
            }else {
                if(tablaAnalisisSintactico[pila.top() ][ (*it).first].empty()){ //No llega nada [a][b] = ""  |=>| error no salvable
                    //llenar la tabla de errores
                }
            }
        }

        //std::cout << tablaAnalisisSintactico["E"]["TOKEN_*"].empty() << std::endl; // 1 or 0 => ok

        //![1]
        return true;
    }




};




#endif // SYNTACTICANALYSIS_H
