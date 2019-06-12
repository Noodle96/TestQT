#include"mainwindow.h"

/*
    Esta funcion visitara la linea sacada del file y por cada palabra :
    1 .- Buscare el la hash wordReserved para verificar si es palabra reservada o
         los automatas(identificador,Num), en caso asi sea, llena la Tabla de simbolos
         y el buffer.
    2 .- si no lo encuentra en la hash o automata , llena la tabla de errores
*/


//principal function
void MainWindow::visitLine(std::list<std::pair<std::string,int>>&linea,unsigned int numLinea){
    int word = 1;
    bool contentPoint = false;
    WORDRESERVED::iterator IteFindHashPR;
    //TABLASIMBOLOS::iterator IteFindhashTS;
    for(auto it = linea.begin() ; it != linea.end(); it++,word++){
        //std::cout << "#" << word <<" "<< (*it) << std::endl;
        //PRIMERO BUSCAREMOS EN LA HASH DE WORDRESERVED
        IteFindHashPR = wordReserved.find((*it).first);
        if(IteFindHashPR != wordReserved.end()){//find
            //std::cout << "encontro " << (*it) << "with token " << (*IteFind).second <<  std::endl;
            //ahora a llenar la tabla de simboos                /////(*it)/////
            LexemaAttributes *newlexema = new LexemaAttributes((*IteFindHashPR).first,numLinea,(*it).second);
            tablaSimbolos[(*IteFindHashPR).second].push_back(newlexema);

            //IteFindhashTS = tablaSimbolos.find((*IteFindHashPR).second);
            //if(IteFindhashTS != tablaSimbolos.end()){//find
                //SI->H    //nothing to do
            //}else{//not find
                //NO->push
                //tablaSimbolos[(*IteFindHashPR).second].push_back(  (*IteFindHashPR).first  );
            //}
            //ahora llenar el buffer
            buffer.push_back(std::make_pair((*IteFindHashPR).second,newlexema));

        }else{//not find
            //std::cout << "not find " << (*it)<<  std::endl;
            //en caso no encuentre en la hash de palabras reservadad buscara en los automatas
            //primero en el afd de variables
            if(  afdVariables.DeltaHat((*it).first)  ){ //find
                //llenaremos la tabla de simbolos
                LexemaAttributes *newlexema = new LexemaAttributes((*it).first,numLinea,(*it).second);
                tablaSimbolos[TOKENID].push_back(newlexema);
                //llenaremos el buffer
                buffer.push_back(std::make_pair(TOKENID,newlexema));
            }else{//not find
                //sino buscaremos en el afd de numeros
                if( afdNumbers.DeltaHat((*it).first) ){//find
                    LexemaAttributes *newlexema = new LexemaAttributes((*it).first,numLinea,(*it).second);
                    contentPoint = contienePunto((*it).first);
                    //llenaremo la tabla de simbolos
                    if(contentPoint){
                        tablaSimbolos[TOKENNUMREAL].push_back(newlexema);
                        buffer.push_back(std::make_pair(TOKENNUMREAL,newlexema));
                    }else{
                        tablaSimbolos[TOKENNUM].push_back(newlexema);
                        buffer.push_back(std::make_pair(TOKENNUM,newlexema));
                    }
                }else{//not find
                    //entonces si no encontro enla hashPR y ni en los automatas
                    //pues llena la tabla de errores
                    tablaErrores.push_back("ERROR en la linea "+std::to_string(numLinea)+ " " + (*it).first +" palabra no permitido");
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


//funcion Thales
void MainWindow::separar(std::string fila, std::list<std::pair<std::string,int>> &respuesta)
{
    size_t i=0;
    size_t columna = 0;
    std::string lexema="";
    while(i<fila.size())
    {
        char cursor=fila[i];//guardamos el caracter para no acceder cada rato mas abajo
        //cout<<"------"<<"cursor:::::"<<cursor<<"----"<<endl;
        if((cursor>='a'&&cursor<='z') || (cursor>='A'&&cursor<='Z') || (cursor>='0'&&cursor<='9') || cursor=='_')
        {
            //Si es un caracter alfanumerico
            lexema=lexema+cursor;
            //se concatena progresivamente
            i++;
        }
        else if(cursor==' ')
        {
            //ignora los espacion
            while(fila[i]==' ')
            {
                i++;
            }
            if(lexema!="")
            {
                //divide
                //cout<<"------"<<lexema<<"--"<<"1"<<"----"<<endl;
                respuesta.push_back(std::make_pair(lexema,columna));
                lexema="";
                columna = i;
            }
        }
        else
        {
            //adddddd
            if(lexema!="")
            {
                //divide
                //cout<<"------"<<lexema<<"--"<<"2"<<"----"<<endl;
                respuesta.push_back(std::make_pair(lexema,columna));
                lexema="";
                columna = i;
            }
            //divide solo el caracter
            std::string temp="";
            temp=temp+cursor;//la lista no quiere aceptar agregar un char, por eso lo convertimos a string
            //cout<<"------"<<temp<<"--"<<"3"<<"----"<<endl;
            respuesta.push_back(std::make_pair(temp,columna));
            i++; columna = i;
        }
    }
    if(lexema!="")
    {
        //la ultima division
        //cout<<"------"<<lexema<<"--"<<"4"<<"----"<<endl;
        respuesta.push_back(std::make_pair(lexema,columna));
    }
}







void MainWindow::separarv2(std::string fila, std::list<std::pair<std::string,int>> &respuesta, bool esComentario){
    size_t columna = 0;
    size_t i=0;
    std::string lexema="";
    while(i<fila.size())
    {//BEGIN_WHILE
        char cursor=fila[i];//guardamos el caracter para no acceder cada rato mas abajo
        if(esComentario==0)
        {//BEGIN_IF_COMENTARIO==FALSO
            if((cursor>='a'&&cursor<='z') || (cursor>='A'&&cursor<='Z') || cursor=='_')
            {//BEGIN_IF_ADD SECUENCIA ALFANUMERICO
                //Si es un caracter alfanumerico
                while((cursor>='a'&&cursor<='z') || (cursor>='A'&&cursor<='Z') || (cursor>='0'&&cursor<='9') || cursor=='_')
                {
                    lexema=lexema+cursor;
                    i++;
                    cursor=fila[i];
                }
                //se concatena progresivamente
                if(lexema!="")
                {
                    respuesta.push_back(std::make_pair(lexema,columna)); //AÑADE SECUENCIA DE ALFANUMERICO
                    lexema="";
                    columna=i;
                }

            }//END_IF_ADD SECUENCIA ALFANUMERICO

            else if(((cursor>='0'&&cursor<='9')) || cursor=='.')
            {
                char tipo=cursor;
                while(cursor>='0'&&cursor<='9')
                {
                    lexema=lexema+cursor;
                    i++;
                    cursor=fila[i];
                }
                if(tipo!='.'&&cursor=='.')
                {
                    lexema=lexema+cursor;
                    i++;
                    cursor=fila[i];
                    while(cursor>='0'&&cursor<='9')
                    {
                        lexema=lexema+cursor;
                        i++;
                        cursor=fila[i];
                    }
                }
                respuesta.push_back(std::make_pair(lexema,columna));
                lexema="";
                columna=i;
            }
            else if(cursor==' ')
            {
                //ignora los espacion
                while(fila[i]==' ')
                {
                    i++;
                }
                cursor=fila[i];
            }
            else if(cursor=='\t')
            {
                //ignora los espacion
                while(fila[i]=='\t')
                {
                    i++;
                }
                cursor=fila[i];
            }
            //EXCEPCIONES
            else{
                //adddddd
                if (cursor=='+')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]=='+')
                    {
                        lexema=lexema+cursor;
                        i++;
                    }
                    respuesta.push_back(std::make_pair(lexema,columna));
                    lexema="";
                    columna = i;
                }
                else if (cursor=='-')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]=='-')
                    {
                        lexema=lexema+cursor;
                        i++;
                    }
                    respuesta.push_back(std::make_pair(lexema,columna));
                    lexema="";
                    columna = i;
                }
                else if (cursor==':')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]==':')
                    {
                        lexema=lexema+cursor;
                        i++;
                    }
                    respuesta.push_back(std::make_pair(lexema,columna));
                    lexema="";
                    columna=i;
                }
                else if (cursor=='>')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]=='>'||fila[i]=='=')
                    {
                        lexema=lexema+fila[i];
                        i++;
                    }
                    respuesta.push_back(std::make_pair(lexema,columna));
                    lexema="";
                    columna=i;
                }
                else if (cursor=='<')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]=='<'||fila[i]=='=')
                    {
                        lexema=lexema+fila[i];
                        i++;
                    }
                    respuesta.push_back(std::make_pair(lexema,columna));
                    lexema="";
                    columna=i;
                }
                else if (cursor=='&')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]=='&')
                    {
                        lexema=lexema+fila[i];
                        i++;
                    }
                    respuesta.push_back(std::make_pair(lexema,columna));
                    lexema="";
                    columna=i;
                }
                else if (cursor=='|')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]=='|')
                    {
                        lexema=lexema+fila[i];
                        i++;
                    }
                    respuesta.push_back(std::make_pair(lexema,columna));
                    lexema="";
                    columna=i;
                }
                else if (cursor=='=')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]=='=')
                    {
                        lexema=lexema+fila[i];
                        i++;
                    }
                    respuesta.push_back(std::make_pair(lexema,columna));
                    lexema="";
                    columna=i;
                }
                else if (cursor=='!')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]=='=')
                    {
                        lexema=lexema+fila[i];
                        i++;
                    }
                    respuesta.push_back(std::make_pair(lexema,columna));
                    lexema="";
                    columna=i;
                }
                else if (cursor=='/')
                {
                    i++;
                    lexema=lexema+cursor;
                    if(fila[i]=='/')
                    {
                        break;
                    }
                    if(fila[i]=='*')
                    {
                        esComentario=1;
                    }
                    else
                    {
                        respuesta.push_back(std::make_pair(lexema,columna));
                        lexema="";
                        columna=i;
                    }
                }
                else
                {
                    std::string temp="";
                    temp=temp+cursor;
                    respuesta.push_back(std::make_pair(temp,columna));
                    i++;
                    columna=i;
                }
            }

        }//END_IF_COMENTARIO==FALS0
        else
        {
            if(cursor=='*')
            {
                i++;
                if(fila[i]=='/')
                    esComentario=0;
            }
            i++;
        }
    }//END_WHILE
}//END_FUNCTION






























//end line.cpp
