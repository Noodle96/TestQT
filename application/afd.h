#ifndef AFD_H
#define AFD_H

#include<map>


namespace AUTOMATA {
    template<typename TS, typename TA>
    class AFD{
    private:
        std::map<TS,TS> states;
    };
}


#endif // AFD_H
