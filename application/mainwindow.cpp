﻿/****************************************************************************
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

//! [0]
#include <QtWidgets>

#include "mainwindow.h"
//! [0]

//! [1]
MainWindow::MainWindow()
    : textEdit(new QPlainTextEdit)
//! [1] //! [2]
{
    setCentralWidget(textEdit);

    createActions();
    createStatusBar();

    readSettings();

    connect(textEdit->document(), &QTextDocument::contentsChanged,
            this, &MainWindow::documentWasModified);

#ifndef QT_NO_SESSIONMANAGER
    QGuiApplication::setFallbackSessionManagementEnabled(false);
    connect(qApp, &QGuiApplication::commitDataRequest,
            this, &MainWindow::commitData);
#endif

    setCurrentFile(QString());
    setUnifiedTitleAndToolBarOnMac(true);



    //INIT NOT TEMPLATE

    //TO ANALISIS LEXICO
    BuildAutomathonToVariables();
    BuildAutomathonToNumbers();
    BuildHashWordReserve();

    //TO ANALISIS SINTACTICO
    BuildSintacticAnalysis();
}



//! [2]

//! [3]
void MainWindow::closeEvent(QCloseEvent *event)
//! [3] //! [4]
{
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}
//! [4]




                    //PRIVATE SLOTS

//! [5]
void MainWindow::newFile()
//! [5] //! [6]
{
    if (maybeSave()) {
         textEdit->clear();
        setCurrentFile(QString());
    }

}
//! [6]







//! [7]
void MainWindow::open()
//! [7] //! [8]
{
    if (maybeSave()) { // maybeSave  verifica si hay un texto de entrada para guardarlo en caso
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}
//! [8]

//! [9]
bool MainWindow::save()
//! [9] //! [10]
{
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}
//! [10]



//! [11]
bool MainWindow::saveAs()
//! [11] //! [12]
{
    QFileDialog dialog(this);
    dialog.setWindowModality(Qt::WindowModal);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    if (dialog.exec() != QDialog::Accepted)
        return false;
    return saveFile(dialog.selectedFiles().first());
}
//! [12]



//! [13]
void MainWindow::about()
//! [13] //! [14]
{
   QMessageBox::information(this, tr("About Application"),
            tr("The <b>Application</b> example demonstrates how to "
               "write modern GUI applications using Qt, with a menu bar, "
               "toolbars, and a status bar."));
}
//! [14]

//! [15]
void MainWindow::documentWasModified()
//! [15] //! [16]
{
    setWindowModified(textEdit->document()->isModified());
}
//! [16]

//! [17]

void MainWindow::message(){
    QMessageBox::information(this,"Aviso","cartas de clash royale");
    //afdVariables.printAFD();
    /*
    std::cout << afdVariables.DeltaHat("Monos4653") << std::endl;
    for(auto it = this->wordReserved.begin() ; it != wordReserved.end() ; it++){
        std::cout << (*it).first << " " << (*it).second << std::endl;
    }*/
    //afdNumbers.printAFD();
    //std::cout << afdNumbers.DeltaHat(".83264") << std::endl;
}


void MainWindow::showTables(){
    //QMessageBox::information(this,"aviso","esto es un aviso");
    TabDialog tabdialog(tablaSimbolos,buffer);
    tabdialog.exec();


}




void MainWindow::generateTables(){
    tablaSimbolos.clear();
    tablaErrores.clear();
    buffer.clear();
    analisiSintactico.bufferCpy.clear();

    //para el analisis sintactico

    std::string filenameCurrent = curFile.toStdString();
    std::fstream entrada;
    std::string line;             //numeroColumna//
    std::list<std::pair<std::string,int>> listWords;
    unsigned int numLinea = 1;
    bool escomentario;
    entrada.open(filenameCurrent, std::ios::in);
    while(getline(entrada,line)){
        //qDebug() << QString::fromStdString(line);
        //comentar esta linea cuando thales haga su tarea
        //convertStringToList(line,listWords);
        //separarv2(line,listWords,escomentario);
        separar(line,listWords);
        /*
            con la funcion LIMPIAR devolvera la linea limpia
        */
        visitLine(listWords,numLinea);
        listWords.clear();numLinea++;
    }
    entrada.close();

    printTablaSimbolos();
    printBuffer();
    printTablaErrores();

    //parte del analisis sintactico

    //analisiSintactico.printTablaAnalisisSintatico();
    std::cout <<"BufferCpy Aceptado ? "<< analisiSintactico.verifyBufferCpyValidation(buffer,tablaErrores) << std::endl;
    printTablaErrores();
    /*
    std::list<TNT> l;
    if(analisiSintactico.findInTASLL1("E","TOKEN_(",l)){
        std::cout << "imprimiendo l" << std::endl;
        for(auto it = l.begin() ;it != l.end() ; it++){
            std::cout << (*it) << " ";
        }
        std::cout << "\n";
    }else{
        std::cout << "Empty" << std::endl;
    }
    */


    //La parte semantica estara embedida en la parte sintactica
    //debido a que la prte Semantica utiliza una pila tambien paa
    //hacer las reglas

    //PARTE SEMANTICA
    bool accepted = true;
    std::stack<std::pair<TNT,std::list<TNT>> > stack_pri;
    if( analisiSintactico.verifyBufferCpyValidation(buffer,tablaErrores) ){

        analisiSintactico.Regla1(buffer,tablaErrores,accepted,stack_pri);
        std::cout << "AcCepted in Analisis Semantico: " << accepted << std::endl;

        std::stack<std::pair<TNT,std::list<TNT>> > stack_pri_cpy = stack_pri;
        //Test

        while(!stack_pri_cpy.empty()){

            std::cout << stack_pri_cpy.top().first ;

            if(!stack_pri_cpy.top().second.empty()){
               std::cout << "  "  << stack_pri_cpy.top().second.begin()->front() << std::endl;
            }
            else{
                std::cout << " NULL" << std::endl;
            }
            stack_pri_cpy.pop();
        }
        // End Test

        auto len_stack = stack_pri.size();
        std::list<TNT> frase;
        while(!stack_pri.empty()){
            concatenarSeconds(stack_pri.top().second,frase);

            frase = stack_pri.top().second;
            printListaenlazada(frase);
            stack_pri.pop();
            len_stack--;
        }

        //std::cout << "NO Terminal " << std::endl;
        //std::cout << stack_pri.top().first << std::endl;
        std::cout << "Frase final" << std::endl;
        printListaenlazada(frase);
        std::cout << std::endl;


        //Ultimo Paso
        //printValue
        printValue(frase); // esta frase lo contiene el E=> No terminal Inicial




    }

}//end Generate Tables
















                                        //FUNCIONES PRIVATE


void MainWindow::createActions()
//! [17]
{
    //! [18] QMENU FILE
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
    QToolBar *fileToolBar = addToolBar(tr("File"));


    const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
    QAction *newAct = new QAction(newIcon, tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);    
    fileMenu->addAction(newAct);
    fileToolBar->addAction(newAct);

//! [19]
    const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"));
    QAction *openAct = new QAction(openIcon, tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);
    fileMenu->addAction(openAct);
    fileToolBar->addAction(openAct);
//! [18] //! [19]

    const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/images/save.png"));
    QAction *saveAct = new QAction(saveIcon, tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);
    fileMenu->addAction(saveAct);
    fileToolBar->addAction(saveAct);

    const QIcon saveAsIcon = QIcon::fromTheme("document-save-as");
    QAction *saveAsAct = fileMenu->addAction(saveAsIcon, tr("Save &As..."), this, &MainWindow::saveAs);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));

//! [20]

    fileMenu->addSeparator(); //agrega -----------------------

    const QIcon exitIcon = QIcon::fromTheme("application-exit");
    QAction *exitAct = fileMenu->addAction(exitIcon, tr("E&xit"), this, &QWidget::close);
    exitAct->setShortcuts(QKeySequence::Quit);
//! [20]
    exitAct->setStatusTip(tr("Exit the application"));










//! [21]  QMENU EDIT
    QMenu *editMenu = menuBar()->addMenu(tr("&Edit"));
    QToolBar *editToolBar = addToolBar(tr("Edit"));
//!
#ifndef QT_NO_CLIPBOARD
    const QIcon cutIcon = QIcon::fromTheme("edit-cut", QIcon(":/images/cut.png"));
    QAction *cutAct = new QAction(cutIcon, tr("Cu&t"), this);
//! [21]
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip(tr("Cut the current selection's contents to the "
                            "clipboard"));
    connect(cutAct, &QAction::triggered, textEdit, &QPlainTextEdit::cut);
    editMenu->addAction(cutAct);
    editToolBar->addAction(cutAct);

    const QIcon copyIcon = QIcon::fromTheme("edit-copy", QIcon(":/images/copy.png"));
    QAction *copyAct = new QAction(copyIcon, tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, &QAction::triggered, textEdit, &QPlainTextEdit::copy);
    editMenu->addAction(copyAct);
    editToolBar->addAction(copyAct);

    const QIcon pasteIcon = QIcon::fromTheme("edit-paste", QIcon(":/images/paste.png"));
    QAction *pasteAct = new QAction(pasteIcon, tr("&Paste"), this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current "
                              "selection"));
    connect(pasteAct, &QAction::triggered, textEdit, &QPlainTextEdit::paste);
    editMenu->addAction(pasteAct);
    editToolBar->addAction(pasteAct);

    menuBar()->addSeparator();

#endif // !QT_NO_CLIPBOARD




    //! [22]  QMENU BUILD
    //agregando el menuBar el toolbar para Build
    QMenu *buildMenu = menuBar()->addMenu("&Build");
    QToolBar *buildToolBar = addToolBar("Build") ;
    //![22]
    const QIcon runIcon = QIcon::fromTheme("", QIcon(":/images/run.jpeg"));
    QAction *runAct = new QAction(runIcon, tr("&Run"), this);
    runAct->setStatusTip(tr("Run The Program"));
    //objeto,tipoobjeto::senhial,
    connect(runAct,&QAction::triggered,this,&MainWindow::generateTables);
    //runAct->setEnabled(false);
    buildMenu->addAction(runAct);
    buildToolBar->addAction(runAct);



    //![23] QMENU SHOW
    QMenu *showTablesMenu = menuBar()->addMenu("&ShowTables");
    QToolBar *showTablesToolBar = addToolBar("Show Tables") ;
    const QIcon showIcon = QIcon::fromTheme("", QIcon(":/images/tables.png"));
    QAction *showAct = new QAction(showIcon, tr("&show"), this);
    showAct->setStatusTip(tr("ShowTables"));
    connect(showAct,&QAction::triggered,this,&MainWindow::showTables);
    showTablesMenu->addAction(showAct);
    showTablesToolBar->addAction(showAct);
    //! [23]







    //QMENU HELPMENU
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
    QAction *aboutAct = helpMenu->addAction(tr("&About"), this, &MainWindow::about);
    aboutAct->setStatusTip(tr("Show the application's About box"));

//! [22]

    QAction *aboutQtAct = helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
//! [22]

//! [23]











#ifndef QT_NO_CLIPBOARD
    cutAct->setEnabled(false);
//! [23] //! [24]
    copyAct->setEnabled(false);
    connect(textEdit, &QPlainTextEdit::copyAvailable, cutAct, &QAction::setEnabled);
    connect(textEdit, &QPlainTextEdit::copyAvailable, copyAct, &QAction::setEnabled);
#endif // !QT_NO_CLIPBOARD
}
//! [24]








//! [32]
void MainWindow::createStatusBar()
//! [32] //! [33]
{
    statusBar()->showMessage(tr("Ready"));
}
//! [33]

//! [34] //! [35]








void MainWindow::readSettings()
//! [34] //! [36]
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    const QByteArray geometry = settings.value("geometry", QByteArray()).toByteArray();
    if (geometry.isEmpty()) {
        const QRect availableGeometry = QApplication::desktop()->availableGeometry(this);
        resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
        move((availableGeometry.width() - width()) / 2,
             (availableGeometry.height() - height()) / 2);
    } else {
        restoreGeometry(geometry);
    }
}
//! [35] //! [36]










//! [37] //! [38]
void MainWindow::writeSettings()
//! [37] //! [39]
{
    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());
    settings.setValue("geometry", saveGeometry());
}
//! [38] //! [39]













//! [40]
bool MainWindow::maybeSave()
//! [40] //! [41]
{
    if (!textEdit->document()->isModified())
        return true;
    //pasa aqui en caso de que hay aido modificado
    const QMessageBox::StandardButton ret
        = QMessageBox::warning(this, tr("Application"),
                               tr("The document has been modified.\n"
                                  "Do you want to save your changes?"),
                               QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    switch (ret) {
    case QMessageBox::Save:
        return save();
    case QMessageBox::Cancel:
        return false;
    default:
        break;
    }
    return true;
}
//! [41]












//! [42]
void MainWindow::loadFile(const QString &fileName)
//! [42] //! [43]
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName), file.errorString()));
        return;
    }

    QTextStream in(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    textEdit->setPlainText(in.readAll());
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}
//! [43]










//! [44]
bool MainWindow::saveFile(const QString &fileName)
//! [44] //! [45]
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(QDir::toNativeSeparators(fileName),
                                  file.errorString()));
        return false;
    }

    QTextStream out(&file);
#ifndef QT_NO_CURSOR
    QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
    out << textEdit->toPlainText();
#ifndef QT_NO_CURSOR
    QApplication::restoreOverrideCursor();
#endif

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);

    return true;
}
//! [45]















//! [46]
void MainWindow::setCurrentFile(const QString &fileName)
//! [46] //! [47]
{
    qDebug() << fileName; // here show path
    curFile = fileName;
    textEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName = curFile;
    if (curFile.isEmpty())
        shownName = "untitled.txt";
    setWindowFilePath(shownName);
}
//! [47]







//! [48]
QString MainWindow::strippedName(const QString &fullFileName)
//! [48] //! [49]
{
    return QFileInfo(fullFileName).fileName();
}








//! [49]
#ifndef QT_NO_SESSIONMANAGER
void MainWindow::commitData(QSessionManager &manager)
{
    if (manager.allowsInteraction()) {
        if (!maybeSave())
            manager.cancel();
    } else {
        // Non-interactive: save without asking
        if (textEdit->document()->isModified())
            save();
    }
}
#endif







//END MAINWINDOWS.H
