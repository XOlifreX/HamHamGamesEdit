#include <iostream>
#include <string>

#include "SaveManager.h"


int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <save-file-path>" << std::endl;
        return 1;
    }

    std::string save(argv[1]);

    SaveManager sManager(save);
    sManager.saveChanges();

    return 0;
}