#ifndef SYNTACTICANALYSIS_H
#define SYNTACTICANALYSIS_H

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



};
// estamos en el proyecto actual


#endif // SYNTACTICANALYSIS_H
