#include"mainwindow.h"


void MainWindow::BuildSintacticAnalysis(){


    //lA CREACION Y LLENADO DE LA PILA SE HACE EN LA FUNCION INTERNA MISMA
    //LA COPIA DEL BUFFERS A BUFFERCOPY SE HACE EN LA FUNCION INTERNA MISMA


    //copiando buffer a bufferCopy
    /*
    for(auto it = buffer.begin() ; it != buffer.end(); it++){
        analisiSintactico.bufferCpy.push_back((*it));
    }
    */
    //analisiSintactico.bufferCpy.push_back( std::make_pair("$","$" ));

     /*
        sync : seran errores recuoerables
        e : desapilar de la pila
    */


    //ahora manualmente llenado la tabla de analisis sintactica LL1
    analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_id","T");analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_id","Ep");
    analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_(","T");analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_(","Ep");
    analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_)","sinc");analisiSintactico.insertInTablaAnalisSintactico("E","$","sinc");

    analisiSintactico.insertInTablaAnalisSintactico("Ep","TOKEN_+","TOKEN_+");analisiSintactico.insertInTablaAnalisSintactico("Ep","TOKEN_+","T");
    analisiSintactico.insertInTablaAnalisSintactico("Ep","TOKEN_+","Ep");analisiSintactico.insertInTablaAnalisSintactico("Ep","TOKEN_)","e");
    analisiSintactico.insertInTablaAnalisSintactico("Ep","$","e");

    analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_id","F");analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_id","Tp");
    analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_+","sinc");analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_(","F");
    analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_(","Tp");analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_)","sinc");
    analisiSintactico.insertInTablaAnalisSintactico("T","$","sinc");

    analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_+","e");analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_*","TOKEN_*");
    analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_*","F");analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_*","T+");
    analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_)","e");analisiSintactico.insertInTablaAnalisSintactico("Tp","$","e");

    analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_id","TOKEN_id");analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_+","sinc");
    analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_*","sinc");analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_(","TOKEN_(");
    analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_(","E");analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_(","TOKEN_)");
    analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_)","sinc");analisiSintactico.insertInTablaAnalisSintactico("F","$","$");
    //


}
