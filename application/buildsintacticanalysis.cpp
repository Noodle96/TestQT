#include"mainwindow.h"


void MainWindow::BuildSintacticAnalysis(){


    //lA CREACION Y LLENADO DE LA PILA SE HACE EN LA FUNCION INTERNA MISMA
    //LA COPIA DEL BUFFERS A BUFFERCOPY SE HACE EN LA FUNCION INTERNA MISMA

    analisiSintactico.listasTerminales.push_back("TOKEN_id");
    analisiSintactico.listasTerminales.push_back("TOKEN_+");
    analisiSintactico.listasTerminales.push_back("TOKEN_*");
    analisiSintactico.listasTerminales.push_back("TOKEN_(");
    analisiSintactico.listasTerminales.push_back("TOKEN_)");
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

    //Initial element E of table sintactic ll1

    //ahora manualmente llenado la tabla de analisis sintactica LL1
    analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_id","T");analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_id","Ep");
    analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_(","T");analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_(","Ep");
    analisiSintactico.insertInTablaAnalisSintactico("E","TOKEN_)",SYNC);analisiSintactico.insertInTablaAnalisSintactico("E","$",SYNC);

    analisiSintactico.insertInTablaAnalisSintactico("Ep","TOKEN_+","TOKEN_+");analisiSintactico.insertInTablaAnalisSintactico("Ep","TOKEN_+","T");
    analisiSintactico.insertInTablaAnalisSintactico("Ep","TOKEN_+","Ep");analisiSintactico.insertInTablaAnalisSintactico("Ep","TOKEN_)",E);
    analisiSintactico.insertInTablaAnalisSintactico("Ep","$",E);

    analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_id","F");analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_id","Tp");
    analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_+",SYNC);analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_(","F");
    analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_(","Tp");analisiSintactico.insertInTablaAnalisSintactico("T","TOKEN_)",SYNC);
    analisiSintactico.insertInTablaAnalisSintactico("T","$",SYNC);

    analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_+",E);analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_*","TOKEN_*");
    analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_*","F");analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_*","Tp");
    analisiSintactico.insertInTablaAnalisSintactico("Tp","TOKEN_)",E);analisiSintactico.insertInTablaAnalisSintactico("Tp","$",E);

    analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_id","TOKEN_id");analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_+",SYNC);
    analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_*",SYNC);analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_(","TOKEN_(");
    analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_(","E");analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_(","TOKEN_)");
    analisiSintactico.insertInTablaAnalisSintactico("F","TOKEN_)",SYNC);analisiSintactico.insertInTablaAnalisSintactico("F","$",SYNC);
    //


}
