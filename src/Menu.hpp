#ifndef MENU
#define MENU
#include <vector>
#include <string>
#include <iostream>
#include <conio.h>

int chooseMenuItem(std::vector<std::string>& options, std::string_view top_msg);

int chooseMode();

#endif