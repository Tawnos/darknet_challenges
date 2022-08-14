#pragma once
#include "messages.h"

class MessageProcessor
{
public:
    
    void AddMessageToProcess(MessageType type, const BaseMessage* message);

private:
    void processMessage(const NPCMessage* npcMessage);
    void processMessage(const UserMessage* npcMessage);
};