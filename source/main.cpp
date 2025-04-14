// g++ main.cpp -o vicad-test -lsfml-system -lsfml-window


#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <SFML/Window.hpp>
#include <ostream>
#include <string>
/*#include <thread>*/
const int window_w = 30;
const int window_h = 60;

struct pos{
    int x;
    int y;
} user_position;

std::string resistor_ascii="\n ___\n┤   ├\n ‾‾‾\n";

//
//      ___
//     ┤   ├
//      ‾‾‾
//
struct Resistor{
    int x;
    int y;
    std::string symbol = resistor_ascii;
};

//NOTE: probably more spaces are needed for this to work. 5x5 boxes are needed
std::string capacitor_ascii= "\n| |\n┤ ├\n| |\n";
//
//     | |
//     ┤ ├
//     | |
//
struct Capacitor{
    int x;
    int y;
    std::string symbol = capacitor_ascii;
};

std::string opamp_ascii= " |╲| \n | ╲ \n ┤  ├ \n | ╱ \n |╱| ";
//     |╲|
//     | ╲
//     ┤  ├
//     | ╱
//     |╱|
struct Opamp{
    int x;
    int y;
    std::string symbol = opamp_ascii;
};

//     
//     
//     -◠◠◠-
//     
//     
struct Inductor{
    int x;
    int y;
    /*std::string symbol = inductor_ascii;*/
};


/*thread thread1(up, intarg1);*/
/*thread thread2(move_left, intarg2);*/
/**/
/*thread1.join();*/
/*thread2.join();*/

void clear() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls"); // Windows
    #else
        system("clear"); // Linux/macOS
    #endif
}

int refresh(int window_w, int window_h, pos user_position){
    clear();
    //main window
    for (int i=0; i<window_w; i++) {
        for (int j=0; j<window_h; j++) {
            if(i==user_position.x && j==user_position.y){
                std::cout<<"X";
            } else {
                std::cout<<".";
            }
        }
        std::cout<<std::endl;
    }
    //bottom bar
    std::cout<<"x:"<<user_position.x<<" y:"<<user_position.y<<std::endl;
    return 0;
}

int update_position(pos& user_position, std::string direction){
    int step = 3;

    if(direction=="up"){
        user_position.x -= step;
        std::cout<<"up"<<std::endl;
    }
    else if(direction=="down"){
        user_position.x += step;
        std::cout<<"down"<<std::endl;
    }
    else if(direction=="right"){
        user_position.y += step;
        std::cout<<"right"<<std::endl;
    }
    else if(direction=="left"){
        user_position.y -= step;
        std::cout<<"left"<<std::endl;
    }

    sf::sleep(sf::milliseconds(100));
    return 0;
}

int place(std::string object_name){
    std::cout<<"\n"<<object_name<<std::endl;
    //TODO: do this better
    //add function to delete places objects
    //add a data structure to store the objects
    //add option to make custom symbols (edit in nvim, save to files)
    if (object_name == "capacitor"){
        Capacitor cap;
        std::cout<<cap.symbol<<std::endl;
    }

    else if (object_name == "resistor"){
        Resistor res;
        std::cout<<res.symbol<<std::endl;
    }

    else if (object_name == "opamp"){
        Opamp op;
        std::cout<<op.symbol<<std::endl;
    }

    sf::sleep(sf::milliseconds(100));
    return 0;
    }

int main (int argc, char *argv[]) {
    pos user_position;
    user_position.x = window_w/2;
    user_position.y = window_h/2;

    refresh(window_w, window_h, user_position);
    while (true)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
            update_position(user_position, "left");
            refresh(window_w, window_h, user_position);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)){
            update_position(user_position, "right");
            refresh(window_w, window_h, user_position);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
            std::cout<<"up"<<std::endl;
            update_position(user_position, "up");
            refresh(window_w, window_h, user_position);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)){
            update_position(user_position, "down");
            refresh(window_w, window_h, user_position);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
            place("capacitor");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
            place("resistor");
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)){
            place("opamp");
        }

        sf::sleep(sf::milliseconds(10));
    }
    return 0;
}
