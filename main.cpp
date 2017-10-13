#include <iostream>
#include <fstream>
#include <algorithm>


std::string base_name(std::string const &path) {
    return path.substr(path.find_last_of("/\\") + 1);
}

/**
 * Write a program which will perform the job of moving the file from one location to another.
 * The source and destination path will be entered by the user.
 * Perform the required error checking and handle the exceptions accordingly.
 */
int main() {
    //std::string s_from_f = "/home/mauri/Pictures/Wallpapers/test.jpg";
    //std::string s_to_f = "/home/mauri/Pictures/test.jpg";
    std::string temp, temp2;
    while (true) {
        std::cout << "Do you want to move a file?y/n: " << std::endl;
        std::cin >> temp;
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        if (temp != "y") { break; }
        std::cout << "Please insert the path of your file" << std::endl;
        std::cin >> temp;
        std::ifstream test(temp);
        if (!test) {
            std::cout << "The file doesn't exist" << std::endl;
            continue;
        }
        const char *c_from_f = temp.c_str();
        std::cout << "Please insert the path of where you want to move the file:"
                  << " remember to place at the end of file its name or rename it."
                  << std::endl;
        std::cin >> temp2;
        const char *c_to_f = temp2.c_str();
        int outcome = rename(c_from_f, c_to_f);
        if (outcome != 0) {
            std::cout << "Something went wrong, check the last file path" << std::endl;
        } else {
            std::cout << "The file " << base_name(temp) << " got moved."
                      << std::endl;
        }
    }
    return 0;
}
