#include <gtest/gtest.h>
#include <gtest/gtest-spi.h>
#include "encryptedBuffer.h"


void TestRead(int readLen)
{
    auto t = new EncryptedBuffer{ "key" };
    t->readBuf(readLen);
}

void TestWrite(int writeLen)
{
    auto t = new EncryptedBuffer{ "key" };
    t->writeBuf(std::string(writeLen, '*'));
}


TEST(BoundsTest, InBoundsReadWrite)
{
    EXPECT_NO_FATAL_FAILURE(TestRead(1024));
    EXPECT_NO_FATAL_FAILURE(TestWrite(1024));
}

TEST(BoundsTest, OutOfBoundsReadWrite)
{
    EXPECT_FATAL_FAILURE(TestRead(1025), "should not allow reading beyond the end of buffer");
    EXPECT_FATAL_FAILURE(TestWrite(1025), "should not allow writing beyond the end of buffer");
}