#include "Menu.hpp"

int chooseMenuItem(std::vector<std::string>& options, std::string_view top_msg)
{
    int counter = 1;
    int chosen_option = counter;
    while (chosen_option != options.size())
    {
        system("CLS");
        std::cout << top_msg << std::endl;
        for (size_t i = 0; i < options.size(); ++i)
        {
            if ((i + 1) == counter) 
                std::cout << options[i] << " <"<< std::endl;
            else 
                std::cout << options[i] << std::endl;
        }
        char pressed = _getch();
        if ((pressed == 72 || pressed == 'w') && counter != 1)
            counter--;
        if ((pressed == 80 || pressed == 's') && counter != options.size())
            counter++;
        if (pressed == '\r' || pressed == '\n') 
        {
            chosen_option = counter;
            system("CLS");
            return chosen_option;
            break;
        }
        
    }
    
    return -1;
}