#include "records.h"
#include <cstring>
#include <iostream>
#include <iomanip>
#include <stdint.h>

int main(int argc, char** argv) {
   if (argc != 3) {
      std::cout << "recordStore.exe [userName] [userKey] ";
      return 1;
   }

   auto name = std::string(argv[1]);
   auto key = std::string(argv[2]);

   auto recordStore = new RecordStore{ Record {name, key} };

   std::string input = "";

   while (input != "x")
   {
      if (input.length() >= 3)
      {
         auto command = input[0];
         auto value = input.substr(2);

         switch (command) {
            case 'a':
            {
               auto nameKeySeparatorIndex = value.find_first_of(' ');
               auto name = value.substr(0, nameKeySeparatorIndex);
               auto key = value.substr(nameKeySeparatorIndex + 1);
               auto record = Record{ name, key };
               auto recordLoc = recordStore->addLinkedRecord(record);
               std::cout << "Stored "<< record << " at [" << recordLoc << "]" << std::endl;
               break;
            }
            case 'g':
            {
               auto recordIndex = atoi(value.c_str());
               std::cout << "Getting record at index: " << recordIndex << std::endl;
               auto record = recordStore->getLinkedRecord(recordIndex);
               if (!record) {
                  std::cout << "No record found at index: " << value << std::endl;
               }
               else {
                  std::cout << "Got record stored at [" << value << "]:" << *record << std::endl;
               }

               break;
            }
            case 'f':
            {
               auto record = recordStore->findLinkedRecord(name);
               if (!record) {
                  std::cout << "No record found using: " << value << std::endl;
               }
               else {
                  std::cout << "Found record using name: [" << value << "]:" << *record << std::endl;
               }

               break;
            }

            default:
            {
               std::cout << "Unknown command or missing parameters" << std::endl;
               break;
            }
         }
      }

      input.clear();
      std::cout << "Options:" << std::endl;
      std::cout << "a NAME KEY - add (NAME, KEY) to the address book. NAME may be up to "
         << Record::MaxNameLength << " characters and KEY may be up to "
         << Record::KeyLength << " characters" << std::endl;
      std::cout << "g INDEX - get (NAME, KEY) stored in the address book at INDEX, or NULL if not found" << std::endl;
      std::cout << "f NAME - find (NAME, KEY) based on NAME, or NULL if not found" << std::endl;
      std::cout << "x - quit the program" << std::endl;
      std::getline(std::cin, input);
   }
   return 0;
}