#pragma once
#include <array>
#include <string>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <cstdarg>

enum class MessageType : uint8_t
{
    User,
    NPC
};


class BaseMessage {};

class NPCMessage : public BaseMessage
{
    static const inline std::array<std::string, 3> AllowedNPCNames = { "cmdc0de", "gourry", "gulo" };
public:
    NPCMessage(std::string name)
        : npcName(name)
    {
        if (std::find(AllowedNPCNames.begin(), AllowedNPCNames.end(), npcName) == AllowedNPCNames.end()) {
           throw std::runtime_error{ "Invalid NPC name specified" };
        }
    }
    
    void runNPCInteraction() const
    {
        auto fileName = "/ctf/npcScripts/" + npcName + ".txt";
        std::cout << "Sending response from " << fileName << std::endl;
        
        auto file = std::ifstream{ fileName };
        std::string npcMessage;
        std::getline(file, npcMessage);
        std::cout << npcMessage << std::endl;
    }
private:
    std::string npcName;
};

class UserMessage : public BaseMessage
{
public:
    UserMessage(std::string name, std::string message)
        : userName(name),
        message(message)
    {}
    
    void printUserMessage() const
    {
        std::cout << userName << " sent a message: " << message << std::endl;
    }
private:
    std::string userName;
    std::string message;
};