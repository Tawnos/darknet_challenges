#include "encryptedBuffer.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <stdint.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "encryptedBuffer.exe [key] " << argc;
        return 1;
    }

    auto buffer = new EncryptedBuffer{ argv[1] };

    std::string input = "";

    while (input != "x")
    {
        if (input[0] == 'r') {
            auto length = atoi(input.substr(2).c_str());
            std::cout << "Reading " <<  std::dec << length << " bytes:" << std::endl;
            auto readBack = buffer->readBuf(length);
            std::cout << std::hex << std::setfill('0');
            for (auto i = 0; i < length; i++) {
                std::cout << readBack[i];
            }
            std::cout << std::endl;
            delete readBack;
        }
        else if (input[0] == 'w') {
            auto value = input.substr(2);
            std::cout << "Writing [" << value << "] to buffer" << std::endl;
            auto written = buffer->writeBuf(value);
            std::cout << "Wrote " << written << " bytes" << std::endl;
        }

        input.clear();
        std::cout << "Options:" << std::endl;
        std::cout << "r LENGTH - read LENGTH bytes (max 1024) from the buffer" << std::endl;
        std::cout << "w VALUE - write VALUE to the front of the buffer, truncating at 1024 bytes" << std::endl;
        std::cout << "x - quit the program" << std::endl;
        std::getline(std::cin, input);
    }
    return 0;
}