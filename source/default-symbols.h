#ifndef DEFAULT_SYMBOLS_H
#define LINKED_LIST_H
#include <string>

//
//      ___
//     ┤   ├
//      ‾‾‾
//
struct Resistor{
    int x;
    int y;
    std::string symbol="\n ___\n┤   ├\n ‾‾‾\n";
};

//
//     | |
//     ┤ ├
//     | |
//
struct Capacitor{
    int x;
    int y;
    std::string symbol = "\n| |\n┤ ├\n| |\n";
};

//     |╲|
//     | ╲
//     ┤  ├
//     | ╱
//     |╱|
struct Opamp{
    int x;
    int y;
    std::string symbol = " |╲| \n | ╲ \n ┤  ├ \n | ╱ \n |╱| ";
};

//     
//     
//     -◠◠◠-
//     
//     
struct Inductor{
    int x;
    int y;
    /*std::string symbol = "     \n     \n-◠◠◠-\n     \n";*/
    std::string symbol = "     \n     \n-ωωω-\n     \n";
};


#endif
