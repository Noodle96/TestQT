#ifndef LEXEMAATTRIBUTES_H
#define LEXEMAATTRIBUTES_H

#include<iostream>

using NUMFILA = long int;
using NUMCOLUMNA = long int;

class LexemaAttributes{
private:
    std::string m_lexema;
    NUMFILA m_numFila;
    NUMCOLUMNA m_numColumna;
public:
    LexemaAttributes(std::string lex="",
                     NUMFILA f=0,
                     NUMCOLUMNA c=0)
                     {
                     this->m_lexema = lex;
                     this->m_numFila = f;
                     this->m_numColumna = c;
                     }
    ~LexemaAttributes(){}

    //Funciones set and get
    std::string getLexema(){return this->m_lexema;}
    NUMFILA getNumFila(){return this->m_numFila;}
    NUMCOLUMNA getNumColumna(){return this->m_numColumna;}
    void setLexema(std::string lex){this->m_lexema = lex;}
    void setNumFila(NUMFILA nf){this->m_numFila = nf;}
    void setNumColumna(NUMCOLUMNA nc){this->m_numColumna = nc;}


};

#endif // LEXEMAATTRIBUTES_H
