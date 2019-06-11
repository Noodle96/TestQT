/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include<iostream>
#include<fstream>
#include<unordered_map> //hash

#include"afd.h"
#include"syntacticanalysis.h"
#include"lexemaattributes.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
class QPlainTextEdit;
class QSessionManager;
QT_END_NAMESPACE


#define TOKENID "TOKEN_id"
#define TOKENNUM "TOKEN_num"
#define TOKENNUMREAL "TOKEN_numReal"

using TABLASIMBOLOS = std::unordered_map<std::string,std::list<LexemaAttributes*>>;
using  BUFFER = std::list<std::pair<std::string,LexemaAttributes*>>;
using WORDRESERVED = std::unordered_map<std::string,std::string>;

//! [0]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

    void loadFile(const QString &fileName);


    //function not template
    void BuildAutomathonToVariables();
    void BuildAutomathonToNumbers();
    void BuildHashWordReserve();
    void visitLine(std::list<std::pair<std::string,int>>&,unsigned int);
    void convertStringToList(std::string,std::list<std::string>&);
    void separar(std::string,std::list<std::pair<std::string,int>>&);
    void quitarTabs(std::string &linea);
    bool contienePunto(std::string);

    //printed
    void printTablaSimbolos();
    void printBuffer();
    void printTablaErrores();


    //sintactic part
    void BuildSintacticAnalysis();


protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void about();
    void message();
    void generateTables(); //dado el archivo curFile llenara la tabla de simbolos, buffer o tabla de errores
    void documentWasModified();
#ifndef QT_NO_SESSIONMANAGER
    void commitData(QSessionManager &);
#endif

private:
    void createActions();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);

    QPlainTextEdit *textEdit;
    QString curFile;




    AUTOMATA::AFD<std::string,std::string> afdVariables;
    AUTOMATA::AFD<std::string , std::string> afdNumbers;


    //hash para las palabras reservadas y simbolos de c++
    WORDRESERVED wordReserved;




    //tabla de simbolos

    //OBJETO [if|6|2] => representa que se creo un OBJETO(lexemaAttribures) con lexema if, fila 6 y columna 2
    //                                           - lexema:string
    //                                           - numfila: NUMFILA
    //                                           -numColumna: NUMCOLUMNA
    //
    //<TOKEN_if, lista<OBJETOS*> >
     TABLASIMBOLOS tablaSimbolos;

    //buffer
    //<TOKEN_id,OBJECT*>
    BUFFER buffer;


    //tabla de errores tanto para erroreslexicos como para errores sintacticos
    std::vector<std::string> tablaErrores;



    //para el analisis sintactico
    SintacticAnalysis analisiSintactico;



};
//! [0]

#endif
