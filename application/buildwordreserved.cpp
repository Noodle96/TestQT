#include"mainwindow.h"


/*
    llenaremos la hash wordreserved con la palabra reservada con su token respectivo
    [int]= TOKEN_INT
    [for]= TOKEN_FOR
      .       .
      .       .
      .       .
    [+] = TOKEN_+

*/

void MainWindow::BuildHashWordReserve(){
    //add WordReserved in hash
    std::string TOKEN = "TOKEN_";
    std::string mywordReserved [] = {"alignas","alignof","and","and_eq","asm","auto","bitand","bitor","bool",
                                      "break","case","catch","char","char16_t","char32_t","cin","class","compl","const",
                                      "constexpr","const_cast","continue","cout","decltype","default","delete","do",
                                      "double","dynamic_cast","else","enum","explicit","export","extern","false",
                                      "float","for","friend","goto","if","inline","int","long","mutable","namespace",
                                      "new","noexcept","not","not_eq","nullptr","operator","or","or_eq","private",
                                      "protected","public","register","reinterpret_cast","return","short","signed",
                                      "sizeof","static","static_assert","static_cast","struct","switch","template",
                                      "this","thread_local","throw","true","try","typedef","typeid","typename","union",
                                      "unsigned","using","virtual","void","volatile","wchar_t","while","xor","xor_eq",
                                      "main"};
    std::list<std::string> bloqueReservedWord(mywordReserved, mywordReserved + sizeof (mywordReserved) / sizeof (std::string) );
    for(auto it = bloqueReservedWord.begin() ; it != bloqueReservedWord.end() ; it++){
        wordReserved.insert(std::make_pair((*it),TOKEN+(*it)));
    }
    //add simbolos in the hash
    std::string mysimbolsReserved [] = {"::","++","--","(",")","[","]","{","}",".","->","+","-","!","~","*","&",".*","->*",
                                        "/","%","<<",">>","<","<=",">",">=","==","!=","^","|","&&","||","=","+=","-=","*=",
                                        "/=","%=","<<=",">>=","&=","^=","|=",",",";"};
    std::list<std::string> bloqueSimbolsReserved(mysimbolsReserved, mysimbolsReserved + sizeof (mysimbolsReserved) / sizeof (std::string));
    for(auto it = bloqueSimbolsReserved.begin() ; it != bloqueSimbolsReserved.end() ; it++){
        wordReserved.insert(std::make_pair((*it),TOKEN+(*it)));
    }


}
