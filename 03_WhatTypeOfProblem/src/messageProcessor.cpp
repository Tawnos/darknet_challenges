#include "messageProcessor.h"

void MessageProcessor::AddMessageToProcess(MessageType type, const BaseMessage* message)
{
    switch (type) {
    case MessageType::NPC:
    {
        auto npcMessage = static_cast<const NPCMessage*>(message);
        processMessage(npcMessage);
        break;
    }
    case MessageType::User:
    {
        auto userMessage = static_cast<const UserMessage*>(message);
        processMessage(userMessage);
        break;
    }
    default:
        throw "Unknown message type";
    }
}

void MessageProcessor::processMessage(const NPCMessage* npcMessage)
{
    std::cout << "Received NPC interaction" << std::endl;
    npcMessage->runNPCInteraction();
}

void MessageProcessor::processMessage(const UserMessage* userMessage)
{
    std::cout << "Received message from user" << std::endl;
    userMessage->printUserMessage();
}