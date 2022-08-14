#include "encryptedBuffer.h"
#include <cassert>
#include <cstring>
#include <algorithm>

char* EncryptedBuffer::readBuf(int length)
{
    // make sure the caller isn't requesting more than the buffer length
    assert(length <= BufferLength);

    // allocate a buffer large enough and copy what was read into the buffer
    auto readValue = new char[length];

    memcpy(readValue, buffer.data(), length);
    return readValue;
}

int EncryptedBuffer::writeBuf(std::string s)
{
    // make sure the caller isn't writing beyond the end of the buffer
    auto writeLength = std::min((int)s.size(), BufferLength);
    memcpy(buffer.data(), s.data(), writeLength);
    return writeLength;
}