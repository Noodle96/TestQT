#include "mainwindow.h"

/*
    En esta funcion construiremos el automata finito determinista para
    poder identificar una expresion  bajo los siguientes requerimientos:
    *La expresion no podra empezar por un numero.
    exmaples:
    royale         Accepted
    royale3        Acceptes
    Royale         Accepted
    3royale        Not Accepted


*/
void MainWindow::BuildAutomathonToVariables(){

    //add los estados totales
    std::string mystrings[] = {"q1","q2","q3"};
    std::list<std::string> bloqueStates(mystrings, mystrings + sizeof (mystrings) / sizeof (std::string));
    afdVariables.addStateByBloque(bloqueStates);

    //set INitialState
    afdVariables.setInitialState("q1");

    //add finalStates
    afdVariables.addFinalState("q2");

     //add alfabeto //62
    std::string myalphabet[] = {"A","a","B","b","C","c","D","d","E","e","F","f","G","g","H","h","I","i",
                                "J","j","K","k","L","l","M","m","N","n","O","o","P","p","Q","q","R","r",
                                "S","s","T","t","U","u","V","v","W","w","X","x","Y","y","Z","z","_","0",
                                 "1","2","3","4","5","6","7","8","9"};
    std::list<std::string> bloqueAlphabet(myalphabet,myalphabet+sizeof (myalphabet)/sizeof (std::string));
    afdVariables.addAlphabetByBloque(bloqueAlphabet);

    //fill matriz de adyacencia
    afdVariables.fillMatrizAdyacencia("q1","A","q2"); afdVariables.fillMatrizAdyacencia("q1","a","q2");
    afdVariables.fillMatrizAdyacencia("q1","B","q2"); afdVariables.fillMatrizAdyacencia("q1","b","q2");
    afdVariables.fillMatrizAdyacencia("q1","C","q2"); afdVariables.fillMatrizAdyacencia("q1","c","q2");
    afdVariables.fillMatrizAdyacencia("q1","D","q2"); afdVariables.fillMatrizAdyacencia("q1","d","q2");
    afdVariables.fillMatrizAdyacencia("q1","E","q2"); afdVariables.fillMatrizAdyacencia("q1","e","q2");
    afdVariables.fillMatrizAdyacencia("q1","F","q2"); afdVariables.fillMatrizAdyacencia("q1","f","q2");
    afdVariables.fillMatrizAdyacencia("q1","G","q2"); afdVariables.fillMatrizAdyacencia("q1","g","q2");
    afdVariables.fillMatrizAdyacencia("q1","H","q2"); afdVariables.fillMatrizAdyacencia("q1","h","q2");
    afdVariables.fillMatrizAdyacencia("q1","I","q2"); afdVariables.fillMatrizAdyacencia("q1","i","q2");
    afdVariables.fillMatrizAdyacencia("q1","J","q2"); afdVariables.fillMatrizAdyacencia("q1","j","q2");
    afdVariables.fillMatrizAdyacencia("q1","K","q2"); afdVariables.fillMatrizAdyacencia("q1","k","q2");
    afdVariables.fillMatrizAdyacencia("q1","L","q2"); afdVariables.fillMatrizAdyacencia("q1","l","q2");
    afdVariables.fillMatrizAdyacencia("q1","M","q2"); afdVariables.fillMatrizAdyacencia("q1","m","q2");
    afdVariables.fillMatrizAdyacencia("q1","N","q2"); afdVariables.fillMatrizAdyacencia("q1","n","q2");
    afdVariables.fillMatrizAdyacencia("q1","O","q2"); afdVariables.fillMatrizAdyacencia("q1","o","q2");
    afdVariables.fillMatrizAdyacencia("q1","P","q2"); afdVariables.fillMatrizAdyacencia("q1","p","q2");
    afdVariables.fillMatrizAdyacencia("q1","Q","q2"); afdVariables.fillMatrizAdyacencia("q1","q","q2");
    afdVariables.fillMatrizAdyacencia("q1","R","q2"); afdVariables.fillMatrizAdyacencia("q1","r","q2");
    afdVariables.fillMatrizAdyacencia("q1","S","q2"); afdVariables.fillMatrizAdyacencia("q1","s","q2");
    afdVariables.fillMatrizAdyacencia("q1","T","q2"); afdVariables.fillMatrizAdyacencia("q1","t","q2");
    afdVariables.fillMatrizAdyacencia("q1","U","q2"); afdVariables.fillMatrizAdyacencia("q1","u","q2");
    afdVariables.fillMatrizAdyacencia("q1","V","q2"); afdVariables.fillMatrizAdyacencia("q1","v","q2");
    afdVariables.fillMatrizAdyacencia("q1","W","q2"); afdVariables.fillMatrizAdyacencia("q1","w","q2");
    afdVariables.fillMatrizAdyacencia("q1","X","q2"); afdVariables.fillMatrizAdyacencia("q1","x","q2");
    afdVariables.fillMatrizAdyacencia("q1","Y","q2"); afdVariables.fillMatrizAdyacencia("q1","y","q2");
    afdVariables.fillMatrizAdyacencia("q1","Z","q2"); afdVariables.fillMatrizAdyacencia("q1","z","q2");
    afdVariables.fillMatrizAdyacencia("q1","_","q2");
    afdVariables.fillMatrizAdyacencia("q1","0","q3"); afdVariables.fillMatrizAdyacencia("q1","1","q3");
    afdVariables.fillMatrizAdyacencia("q1","2","q3"); afdVariables.fillMatrizAdyacencia("q1","3","q3");
    afdVariables.fillMatrizAdyacencia("q1","4","q3"); afdVariables.fillMatrizAdyacencia("q1","5","q3");
    afdVariables.fillMatrizAdyacencia("q1","6","q3"); afdVariables.fillMatrizAdyacencia("q1","7","q3");
    afdVariables.fillMatrizAdyacencia("q1","8","q3"); afdVariables.fillMatrizAdyacencia("q1","9","q3");


    afdVariables.fillMatrizAdyacencia("q2","A","q2"); afdVariables.fillMatrizAdyacencia("q2","a","q2");
    afdVariables.fillMatrizAdyacencia("q2","B","q2"); afdVariables.fillMatrizAdyacencia("q2","b","q2");
    afdVariables.fillMatrizAdyacencia("q2","C","q2"); afdVariables.fillMatrizAdyacencia("q2","c","q2");
    afdVariables.fillMatrizAdyacencia("q2","D","q2"); afdVariables.fillMatrizAdyacencia("q2","d","q2");
    afdVariables.fillMatrizAdyacencia("q2","E","q2"); afdVariables.fillMatrizAdyacencia("q2","e","q2");
    afdVariables.fillMatrizAdyacencia("q2","F","q2"); afdVariables.fillMatrizAdyacencia("q2","f","q2");
    afdVariables.fillMatrizAdyacencia("q2","G","q2"); afdVariables.fillMatrizAdyacencia("q2","g","q2");
    afdVariables.fillMatrizAdyacencia("q2","H","q2"); afdVariables.fillMatrizAdyacencia("q2","h","q2");
    afdVariables.fillMatrizAdyacencia("q2","I","q2"); afdVariables.fillMatrizAdyacencia("q2","i","q2");
    afdVariables.fillMatrizAdyacencia("q2","J","q2"); afdVariables.fillMatrizAdyacencia("q2","j","q2");
    afdVariables.fillMatrizAdyacencia("q2","K","q2"); afdVariables.fillMatrizAdyacencia("q2","k","q2");
    afdVariables.fillMatrizAdyacencia("q2","L","q2"); afdVariables.fillMatrizAdyacencia("q2","l","q2");
    afdVariables.fillMatrizAdyacencia("q2","M","q2"); afdVariables.fillMatrizAdyacencia("q2","m","q2");
    afdVariables.fillMatrizAdyacencia("q2","N","q2"); afdVariables.fillMatrizAdyacencia("q2","n","q2");
    afdVariables.fillMatrizAdyacencia("q2","O","q2"); afdVariables.fillMatrizAdyacencia("q2","o","q2");
    afdVariables.fillMatrizAdyacencia("q2","P","q2"); afdVariables.fillMatrizAdyacencia("q2","p","q2");
    afdVariables.fillMatrizAdyacencia("q2","Q","q2"); afdVariables.fillMatrizAdyacencia("q2","q","q2");
    afdVariables.fillMatrizAdyacencia("q2","R","q2"); afdVariables.fillMatrizAdyacencia("q2","r","q2");
    afdVariables.fillMatrizAdyacencia("q2","S","q2"); afdVariables.fillMatrizAdyacencia("q2","s","q2");
    afdVariables.fillMatrizAdyacencia("q2","T","q2"); afdVariables.fillMatrizAdyacencia("q2","t","q2");
    afdVariables.fillMatrizAdyacencia("q2","U","q2"); afdVariables.fillMatrizAdyacencia("q2","u","q2");
    afdVariables.fillMatrizAdyacencia("q2","V","q2"); afdVariables.fillMatrizAdyacencia("q2","v","q2");
    afdVariables.fillMatrizAdyacencia("q2","W","q2"); afdVariables.fillMatrizAdyacencia("q2","w","q2");
    afdVariables.fillMatrizAdyacencia("q2","X","q2"); afdVariables.fillMatrizAdyacencia("q2","x","q2");
    afdVariables.fillMatrizAdyacencia("q2","Y","q2"); afdVariables.fillMatrizAdyacencia("q2","y","q2");
    afdVariables.fillMatrizAdyacencia("q2","Z","q2"); afdVariables.fillMatrizAdyacencia("q2","z","q2");
    afdVariables.fillMatrizAdyacencia("q2","_","q2");
    afdVariables.fillMatrizAdyacencia("q2","0","q2"); afdVariables.fillMatrizAdyacencia("q2","1","q2");
    afdVariables.fillMatrizAdyacencia("q2","2","q2"); afdVariables.fillMatrizAdyacencia("q2","3","q2");
    afdVariables.fillMatrizAdyacencia("q2","4","q2"); afdVariables.fillMatrizAdyacencia("q2","5","q2");
    afdVariables.fillMatrizAdyacencia("q2","6","q2"); afdVariables.fillMatrizAdyacencia("q2","7","q2");
    afdVariables.fillMatrizAdyacencia("q2","8","q2"); afdVariables.fillMatrizAdyacencia("q2","9","q2");

    afdVariables.fillMatrizAdyacencia("q3","A","q3"); afdVariables.fillMatrizAdyacencia("q3","a","q3");
    afdVariables.fillMatrizAdyacencia("q3","B","q3"); afdVariables.fillMatrizAdyacencia("q3","b","q3");
    afdVariables.fillMatrizAdyacencia("q3","C","q3"); afdVariables.fillMatrizAdyacencia("q3","c","q3");
    afdVariables.fillMatrizAdyacencia("q3","D","q3"); afdVariables.fillMatrizAdyacencia("q3","d","q3");
    afdVariables.fillMatrizAdyacencia("q3","E","q3"); afdVariables.fillMatrizAdyacencia("q3","e","q3");
    afdVariables.fillMatrizAdyacencia("q3","F","q3"); afdVariables.fillMatrizAdyacencia("q3","f","q3");
    afdVariables.fillMatrizAdyacencia("q3","G","q3"); afdVariables.fillMatrizAdyacencia("q3","g","q3");
    afdVariables.fillMatrizAdyacencia("q3","H","q3"); afdVariables.fillMatrizAdyacencia("q3","h","q3");
    afdVariables.fillMatrizAdyacencia("q3","I","q3"); afdVariables.fillMatrizAdyacencia("q3","i","q3");
    afdVariables.fillMatrizAdyacencia("q3","J","q3"); afdVariables.fillMatrizAdyacencia("q3","j","q3");
    afdVariables.fillMatrizAdyacencia("q3","K","q3"); afdVariables.fillMatrizAdyacencia("q3","k","q3");
    afdVariables.fillMatrizAdyacencia("q3","L","q3"); afdVariables.fillMatrizAdyacencia("q3","l","q3");
    afdVariables.fillMatrizAdyacencia("q3","M","q3"); afdVariables.fillMatrizAdyacencia("q3","m","q3");
    afdVariables.fillMatrizAdyacencia("q3","N","q3"); afdVariables.fillMatrizAdyacencia("q3","n","q3");
    afdVariables.fillMatrizAdyacencia("q3","O","q3"); afdVariables.fillMatrizAdyacencia("q3","o","q3");
    afdVariables.fillMatrizAdyacencia("q3","P","q3"); afdVariables.fillMatrizAdyacencia("q3","p","q3");
    afdVariables.fillMatrizAdyacencia("q3","Q","q3"); afdVariables.fillMatrizAdyacencia("q3","q","q3");
    afdVariables.fillMatrizAdyacencia("q3","R","q3"); afdVariables.fillMatrizAdyacencia("q3","r","q3");
    afdVariables.fillMatrizAdyacencia("q3","S","q3"); afdVariables.fillMatrizAdyacencia("q3","s","q3");
    afdVariables.fillMatrizAdyacencia("q3","T","q3"); afdVariables.fillMatrizAdyacencia("q3","t","q3");
    afdVariables.fillMatrizAdyacencia("q3","U","q3"); afdVariables.fillMatrizAdyacencia("q3","u","q3");
    afdVariables.fillMatrizAdyacencia("q3","V","q3"); afdVariables.fillMatrizAdyacencia("q3","v","q3");
    afdVariables.fillMatrizAdyacencia("q3","W","q3"); afdVariables.fillMatrizAdyacencia("q3","w","q3");
    afdVariables.fillMatrizAdyacencia("q3","X","q3"); afdVariables.fillMatrizAdyacencia("q3","x","q3");
    afdVariables.fillMatrizAdyacencia("q3","Y","q3"); afdVariables.fillMatrizAdyacencia("q3","y","q3");
    afdVariables.fillMatrizAdyacencia("q3","Z","q3"); afdVariables.fillMatrizAdyacencia("q3","z","q3");
    afdVariables.fillMatrizAdyacencia("q3","_","q3");
    afdVariables.fillMatrizAdyacencia("q3","0","q3"); afdVariables.fillMatrizAdyacencia("q3","1","q3");
    afdVariables.fillMatrizAdyacencia("q3","2","q3"); afdVariables.fillMatrizAdyacencia("q3","3","q3");
    afdVariables.fillMatrizAdyacencia("q3","4","q3"); afdVariables.fillMatrizAdyacencia("q3","5","q3");
    afdVariables.fillMatrizAdyacencia("q3","6","q3"); afdVariables.fillMatrizAdyacencia("q3","7","q3");
    afdVariables.fillMatrizAdyacencia("q3","8","q3"); afdVariables.fillMatrizAdyacencia("q3","9","q3");
}





// end buildautomathon.cpp
