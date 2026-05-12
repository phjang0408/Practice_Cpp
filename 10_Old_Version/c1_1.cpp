#include <iostream>
//숫자 맞추기 게임
int main()
{
    int answer_number = 1423, user_number;
    std::cout << "[number selection]" << std::endl;
    while (1)
    {
    std::cin >> user_number;
        if (answer_number == user_number)
        {
            std::cout << "Correct!" << std::endl;
            break;
        }
        else if (answer_number < user_number)
        {
            std::cout << "Too Big!" << std::endl;
        }
        else if (answer_number > user_number)
        {
            std::cout << "Too Small!" << std::endl;
        }
    }
}