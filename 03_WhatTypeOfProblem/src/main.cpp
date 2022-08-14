#include "messageProcessor.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <stdint.h>
#include <string>

int main(int argc, char** argv) {
   if (argc != 1) {
      std::cout << "messageProcessor.exe";
      return 1;
   }

   std::string input = "";
   auto messageProcessor = new MessageProcessor{};
   while (input != "x")
   {
      try
      {
         if (input.length() >= 3)
         {
            auto command = input[0];
            auto value = input.substr(2);

            switch (command) {
            case 'a':
            {
               auto nameMessageSeparatorIndex = value.find_first_of(' ');
               auto name = value.substr(0, nameMessageSeparatorIndex);
               auto message = value.substr(nameMessageSeparatorIndex + 1);

               auto userMessage = new UserMessage{ name, message };
               std::cout << "User Message created at: " << std::hex << userMessage << std::endl;
               break;
            }
            case 'n':
            {
               auto npcMessage = new NPCMessage{ value };
               std::cout << "NPC Message created at: " << std::hex << (void*)npcMessage << std::endl;
               break;
            }
            case 's':
            {
               auto typeAddressSeparatorIndex = value.find_first_of(' ');
               auto messageType = (MessageType)stoi(value.substr(0, typeAddressSeparatorIndex));
               auto messageAddress = (const BaseMessage*)(void*)stoll(value.substr(typeAddressSeparatorIndex + 1), 0, 16);

               std::cout << "Submitting message at address [" << std::hex << messageAddress << "] to process" << std::endl;
               messageProcessor->AddMessageToProcess(messageType, messageAddress);
               break;
            }
            default:
            {
               std::cout << "Unknown command or missing parameters" << std::endl;
               break;
            }
            }
         }
      }
      catch (const std::exception& e)
      {
         std::cerr << e.what() << std::endl;
      }

      input.clear();
      std::cout << "Options:" << std::endl;
      std::cout << "a USERNAME MESSAGE - create a MESSAGE from USER. Returns ADDRESS" << std::endl;
      std::cout << "n NPCNAME - create a communication from NPCNAME (allowed: cmdc0de, gourry, gulo). Returns ADDRESS." << std::endl;
      std::cout << "s MESSAGETYPE ADDRESS - submit message oF MESSAGETYPE (0 for USER, 1 for NPC) at ADDRESS for processing" << std::endl;
      std::cout << "x - quit the program" << std::endl;
      std::getline(std::cin, input);
   }
   return 0;
}