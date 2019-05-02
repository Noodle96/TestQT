#include"mainwindow.h"

//imprime la tabla de simbolos
void MainWindow::printTablaSimbolos(){
    std::cout << "TABLA DE SIMBOLOS" << std::endl;
    for(auto it = tablaSimbolos.begin() ;  it != tablaSimbolos.end(); it++){
        std::cout <<(*it).first << " ";
        for(auto et = (*it).second.begin() ; et != (*it).second.end(); et++){
            std::cout << (*et) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// imprime el buffer
void MainWindow::printBuffer(){
    std::cout << "BUFFER" << std::endl;
    for(auto it = buffer.begin() ;it != buffer.end() ; it++){
        std::cout << (*it).first << " " << (*it).second << std::endl;
    }
    std::cout << std::endl;
}

//imprrime la tabla de errores
void MainWindow::printTablaErrores(){
    std::cout << "TABLA DE ERRORES" << std::endl;
    for(auto it = tablaErrores.begin()  ; it != tablaErrores.end(); it++){
        std::cout << (*it) << std::endl;
    }
    std::cout << std::endl;
}
