/***********************************************************************
 * Author:       Brennan Douglas
 * Date:         01/15/2017
 * Description:  This is the source code file for all my personal
 *               utility functions.
 * ********************************************************************/

#include "douglbre_util.hpp"

#include <functional>
#include <string>
#include <iostream>
#include <vector>

// The purpose of this function is to provide a generic way to always create a menu.
// It takes the menu title which is printed above the options on each iteration, an
// array of the title of each option, an array of the callback functions for each
// option, and finally an integer with the amount of options in the arrays.
void douglbre::user::menu_loop(std::string menu_title, std::string *titles, douglbre::v_v_callback* callbacks, int size) {
    std::string s_input;
    int input;
    do {
        input = 0;
        std::cout << menu_title << std::endl;
        for(int i = 0; i < size + 1; i++) {
            if(i == size) {
                std::cout << "  (" << i + 1 << ") Quit" << std::endl;
            } else {
                std::cout << "  (" << i + 1 << ") " << titles[i] << std::endl;
            }
        }
        std::cout << "  Select option: ";
        std::cin >> s_input;
        try {
            input = std::stoi(s_input);
            std::cin.ignore(1000, '\n');
            if(input > 0 && input <= size) {
                callbacks[input - 1]();
                std::cout << std::endl;
            } else if(input != size + 1) {
                std::cout << "That was not an option please try again." << std::endl << std::endl;
            }
        } catch ( std::invalid_argument e ) {
            std::cerr << "Invalid input, please input the integer of one of the options." << std::endl;
        }

    } while(input != size + 1);
}

// This function does the same as the previous one, but after getting a valid input
// it quits instead of reprinting.
void douglbre::user::menu_single(std::string menu_title, std::string *titles, v_v_callback *callbacks, int size) {
    std::string s_input;
    int input;
    do {
        input = 0;
        std::cout << menu_title << std::endl;
        for(int i = 0; i < size; i++) {
                std::cout << "  (" << i + 1 << ") " << titles[i] << std::endl;
        }
        std::cout << "  Select option: ";
        std::cin >> s_input;
        try {
            input = std::stoi(s_input);
            std::cin.ignore(1000, '\n');
            if (input > 0 && input <= size) {
                callbacks[input - 1]();
                std::cout << std::endl;
            } else {
                std::cout << "That was not an option please try again." << std::endl << std::endl;
            }
        } catch ( std::invalid_argument e ) {
            std::cerr << "Invalid input, please input the integer of one of the options." << std::endl;
        }
    } while(input <= 0 || input > size);
}

// This function produces a random double between the two values provided.
double douglbre::util::rand_clamp(double min, double max) {
    return min + ((max - min) * ((double) std::rand() / RAND_MAX));
}

std::string* douglbre::util::split_string(std::string str, std::string delim, std::size_t* out_size) {
    std::vector<std::string> vec;
    size_t pos = 0;
    std::string token = "";

    while ((pos = str.find(delim)) != std::string::npos) {
            token = str.substr(0, pos);
            vec.push_back(token);
            str.erase(0, pos + delim.length());
    }
    // Get the last token
    vec.push_back(str);

    *out_size = vec.size();
    std::string* out_array = new std::string[(*out_size)];
    for(unsigned int i = 0; i < (*out_size); i++) {
        out_array[i] = vec[i];
    }
    return out_array;
}

template <> void douglbre::user::validate_input(std::string prompt, std::string* input, std::function<bool(std::string)> valid) {
    bool noneNull;
    do {
        noneNull = false;
        std::cout << prompt << std::flush;

        std::getline(std::cin, (*input));

        std::string tmp = (*input);
        tmp.erase(std::remove(tmp.begin(), tmp.end(), ' '), tmp.end());
        if(tmp != "") {
            noneNull = true;
        } else {
            std::cerr << "Invalid input, please try again." << std::endl;
        }

    } while (!noneNull || !valid(*input));
}