#ifndef SYNTACTICANALYSIS_H
#define SYNTACTICANALYSIS_H

#include<iostream>
#include<stack>
#include<list>
#include<vector>
#include<map>
#include<algorithm>
#include<QDebug>

#include"lexemaattributes.h"

using NOTERMINAL = std::string;
using TERMINAL = std::string;
using TNT = std::string;
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
///
/// gramtica 2
/// E -> E + T | E - T | T
/// T -> T * T | T / F | F
/// F -> i | c
///


class SintacticAnalysis{
public:
    std::map< NOTERMINAL,std::map< TERMINAL,std::list<TNT> > > tablaAnalisisSintactico;
    //std::stack<TNT> pila;
    std::list<std::pair<TOKEN,LexemaAttributes* >> bufferCpy;
    std::list<TERMINAL> listasTerminales;
public:

    bool findInTASLL1(TNT tnt,TERMINAL term,std::list<TNT>&lista){
        lista = tablaAnalisisSintactico[tnt][term];
        if(lista.empty()) return false;
        return true;
    }
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
    void pushPila(std::stack<TNT> &pl,std::list<TNT> &l){
        for(auto it = l.begin() ; it != l.end() ; it++){
            pl.push((*it));
        }
    }


    //std::cout << tablaAnalisisSintactico["E"]["TOKEN_*"].empty() << std::endl; // 1 or 0 => ok
    bool verifyBufferCpyValidation( const std::list<std::pair<std::string,LexemaAttributes*>> &buffer,std::vector<std::string> &tablaErrores){
        //pusheando la pila con $
        std::stack<TNT> pila;
        pila.push("$");
        pila.push("E"); //initial in buildsintacticanalysis.cpp
        //copiando buffer a bufferCopy
        for(auto it = buffer.begin() ; it != buffer.end(); it++){
            bufferCpy.push_back(std::make_pair((*it).first,(*it).second));
        }

        bufferCpy.push_back( std::make_pair("$",nullptr ));
        //haciendo el reconocimiento de el buffercopy con la pila(push and pop)
        //![1] v1

        auto a = (bufferCpy.begin());

        bool accepted = true;
        TNT x;
        std::list<TNT>l;
        while(!pila.empty()){
            //qDebug() << "fffffffffffffff";
            l.clear();
            if(pila.top()=="$" && a->first=="$") return accepted;
            x= pila.top();
            QString xq = x.c_str();
            //qDebug() << xq;
            //qDebug() << a->first.c_str();
            if(x == a->first){
                pila.pop(); a++;
            }else{
                if(findInTASLL1(x,a->first,l)){
                    if((*l.begin())=="e") {
                        pila.pop();
                    }
                    else if( (*l.begin())=="sync" ){
                        if(pila.size() <= 2){
                            //indicar error
                            tablaErrores.push_back("ERROR SINTACTICO: lexema " + a->second->getLexema() + " de sobra en la linea "
                                                   + std::to_string(a->second->getNumFila()) + " y columna "
                                                   + std::to_string(a->second->getNumColumna()));
                            a++;
                            accepted = false;
                        }else{
                            //indicar error
                            tablaErrores.push_back("ERROR SINTACTICO: lexema " + a->second->getLexema() + " de sobra en la linea "
                                                   + std::to_string(a->second->getNumFila()) + " y columna "
                                                   + std::to_string(a->second->getNumColumna()));
                            pila.pop();
                            accepted=false;

                        }
                    }else{
                        pila.pop();
                        l.reverse();
                        pushPila(pila,l);
                    }
                }else{
                    auto it = std::find(listasTerminales.begin(),listasTerminales.end(),x);
                    if(it != listasTerminales.end()){//find
                        //indicar error
                        tablaErrores.push_back("ERROR SINTACTICO: Puede que le falte colocar un lexema antes o despues de "
                                               + a->second->getLexema()+ " en la linea "
                                               + std::to_string(a->second->getNumFila()) + " y columna "
                                               + std::to_string(a->second->getNumColumna()));
                        pila.pop();
                        accepted=false;
                    }else{
                        //indicar error
                        tablaErrores.push_back("ERROR SINTACTICO: Puede que le falte colocar un lexema antes o despues de "
                                               + a->second->getLexema() + " en la linea "
                                               + std::to_string(a->second->getNumFila()) + " y columna "
                                               + std::to_string(a->second->getNumColumna()));
                        a++;
                        accepted=false;
                    }
                }
            }//end else
        }
        qDebug() << "end";
        //![1]

    }
};




#endif // SYNTACTICANALYSIS_H
