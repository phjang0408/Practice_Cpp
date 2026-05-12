#include <iostream>

namespace mynamespace
{
    int n1value = 10;
}

int main()
{
    int command;
    std::cin >> command;

    switch(command){
        case 1:
            std::cout << "You input : " << command << std::endl;
            break;
        case 2:
            std::cout << "You input : " << command << std::endl;
            break;
        default:
            std::cout << "Default input : " << command << std::endl;
            break;
    }

    return 0;
}