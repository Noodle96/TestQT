#include"mainwindow.h"

/*
    Esta funcion visitara la linea sacada del file y por cada palabra :
    1 .- Buscare el la hash wordReserved para verificar si es palabra reservada o
         los automatas(identificador,Num), en caso asi sea, llena la Tabla de simbolos
         y el buffer.
    2 .- si no lo encuentra en la hasj o automata , llena la tabla de errores
*/


//principal function
void MainWindow::visitLine(std::list<std::string>&linea,unsigned int numLinea){
    int word = 1;
    bool contentPoint = false;
    std::unordered_map<std::string,std::string>::iterator IteFindHashPR;
    std::unordered_map<std::string,std::list<std::string>>::iterator IteFindhashTS;
    for(auto it = linea.begin() ; it != linea.end(); it++,word++){
        //std::cout << "#" << word <<" "<< (*it) << std::endl;
        //PRIMERO BUSCAREMOS EN LA HASH DE PALABRAS RESERVADAS
        IteFindHashPR = wordReserved.find((*it));
        if(IteFindHashPR != wordReserved.end()){//find

            //std::cout << "encontro " << (*it) << "with token " << (*IteFind).second <<  std::endl;
            //ahora a llenar la tabla de simboos
            IteFindhashTS = tablaSimbolos.find((*IteFindHashPR).second);
            if(IteFindhashTS != tablaSimbolos.end()){//find
                //SI->H    //nothing to do
            }else{//not find
                //NO->push
                tablaSimbolos[(*IteFindHashPR).second].push_back(  (*IteFindHashPR).first  );
            }
            //ahora llenar el buffer
            buffer.push_back(std::make_pair((*IteFindHashPR).second,(*IteFindHashPR).first));


        }else{//not find
            //std::cout << "not find " << (*it)<<  std::endl;
            //en caso no encuentre en la hash de palabras reservadad buscara en los automatas
            //primero en el afd de variables
            if(  afdVariables.DeltaHat((*it))  ){ //find
                //llenaremos la tabla de simbolos
                tablaSimbolos["TOKEN_id"].push_back((*it));
                //llenaremos el buffer
                buffer.push_back(std::make_pair("TOKEN_id",(*it)));
            }else{//not find
                //sino buscaremos en el afd de numeros
                if( afdNumbers.DeltaHat((*it)) ){//find
                    contentPoint = contienePunto((*it));
                    //llenaremo la tabla de simbolos
                    if(contentPoint){
                        tablaSimbolos["TOKEN_numReal"].push_back((*it));
                        buffer.push_back(std::make_pair("TOKEN_numReal",(*it)));
                    }else{
                        tablaSimbolos["TOKEN_num"].push_back((*it));
                        buffer.push_back(std::make_pair("TOKEN_num",(*it)));
                    }
                }else{//not find
                    //entonces si no encontro enla hashPR y ni en los automatas
                    //pues llena la tabla de errores
                    tablaErrores.push_back("ERROR en la linea "+std::to_string(numLinea)+ " " + (*it) +" palabra no permitido");
                }
            }
        }
    }
}




/*
    convierte un string de palabras en una lista de palabras
*/
void MainWindow::convertStringToList(std::string linea,std::list<std::string> &listaPalabras){
    quitarTabs(linea);
    std::string wordTemp="";
    for(auto it = linea.begin() ; it != linea.end(); it++){
        if(  (*it) != ' '   ){
            wordTemp += (*it);
        }else if(   (*it)==' ' && !wordTemp.empty()       ){
            listaPalabras.push_back(wordTemp);
            wordTemp.clear();
        }
    }
    if(!wordTemp.empty()){
        listaPalabras.push_back(wordTemp); wordTemp.clear();
    }
}



/*
    quita los tabs del string
*/
void MainWindow::quitarTabs(std::string &linea){
    std::string sintabs = "";
    for(auto it = linea.begin() ; it != linea.end(); it++){
        if( (*it) != '\t' ) sintabs+=(*it);
    }
    linea = sintabs;
}


/*
    function que determina si un string contiene punto
*/
bool MainWindow::contienePunto(std::string str){
    for(auto it = str.begin() ; it != str.end(); it++){
        if((*it)=='.')return true;
    }
    return false;
}




//end line.cpp
