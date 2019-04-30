#ifndef AFD_H
#define AFD_H
#include<iostream>
#include<map>
#include<list>


namespace AUTOMATA {
    template<typename TS, typename TA>
    class AFD{
    private:
        std::map<TS,TS> states;
        std::map<TA,TA> alphabet;
        TS initialState;
        std::map<TS,TS> finalStates;
        std::map< TS,std::map<TA,TS>> MAdyacencia;
        std::map< TS,std::map<TA, std::list<TS>>> MTest;
    public:
        AFD(){}
        ~AFD(){}
        void addState(TS stt){states.insert(std::make_pair(stt,stt));}
        void addAlphabet(TA alp){alphabet.insert(std::make_pair(alp,alp));}
        void setInitialState(TS iniStt){this->initialState = iniStt;}
        void addFinalState(TS sttf){finalStates.insert(std::make_pair(sttf,sttf));}
        void fillMatrizAdyacencia(TS stt1, TA alp, TS stt2){
            //MAdyacencia.insert( std::make_pair(stt1,insert(std::make_pair(alp,stt2))) );
            MAdyacencia [stt1][alp]=stt2;
            //MTest[stt1][alp].push_back(stt2);
        }

        void printAFD(){
            //imprimiendo los estados
            std::cout << "Estados del AFD" << std::endl;
            for(auto it = states.begin(); it != states.end(); it++){
                std::cout << (*it).first << " ";
            }
            std::cout<<std::endl;

            std::cout << "Estado Inicial del AFD: " << initialState << std::endl;

            std::cout << "Estados finales  del AFD" << std::endl;
            for(auto it = finalStates.begin(); it != finalStates.end(); it++){
                std::cout << (*it).first << " ";
            }
            std::cout<<std::endl;

            //imprimiendo el alphabeto dep AFD
            std::cout << "Alphabeto del AFD" << std::endl;
            for(auto it = alphabet.begin(); it != alphabet.end(); it++){
                std::cout << (*it).first << " ";
            }
            std::cout<<std::endl;

            std::cout << "Imprimiendo la Matriz de adyacencia" << std::endl;
            for(auto it = MAdyacencia.begin() ; it != MAdyacencia.end() ; it++){
                //std::cout << (*it).first << "->";
                std::cout << "hola" << std::endl;
                for(auto et = (*it).second.begin()  ; et != (*it).second.end() ; et++){
                    std::cout << (*it).first << " " << (*et).first << " " << (*et).second << std::endl;
                }
            }
        }
        /*
            -> La Clase AFD contendra una funcion filtro, el cual analizara la
            expresion antes de ser procesada para verificar que contenga los
            caracteres permitidos, considerando que el alfabeto se a...z
            example
            *monos       Esta palabara no aceptara
            alias        esta palabra sera aceptada
        */
        bool DeltaHat(std::string){
            //el filtro estara incluido dentro de la funcion delta hat


        }

        //funciones alternativos
        void addStateByBloque(std::list<TS> &bloque){
            for(auto it = bloque.begin() ; it != bloque.end() ; it++){
                addState((*it));
            }
        }
        void addAlphabetByBloque(std::list<TA> &bloque){
            for( auto it = bloque.begin();  it != bloque.end() ; it++){
                addAlphabet((*it));
            }
        }
    };
}


#endif // AFD_H
