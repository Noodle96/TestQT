#include"mainwindow.h"


void MainWindow::BuildSintacticAnalysis(){
    //inicializando la pila con dolar
    analisiSintactico.pila.push("$");

    //copiando buffer a bufferCopy
    for(auto it = buffer.begin() ; it != buffer.end(); it++){
        analisiSintactico.bufferCpy.push_back((*it));
    }
    analisiSintactico.bufferCpy.push_back( std::make_pair("$","$" ));

    //ahora manualmente llenado la tabla de analisis sintactica LL1



}
