#include <array>
#include <string>
#include <exception>

class EncryptedBuffer {
    public:
        EncryptedBuffer(std::string privateKey) {
            if (privateKey.length() > KeyLength) {
                throw std::runtime_error("provided key length was greater than the storage space");
            }
            for (auto i = 0; i < privateKey.length(); i++) { key[i] = privateKey[i]; }
        }
        char* readBuf(int length);
       int writeBuf(std::string s);

    private:
        static inline const int BufferLength = 1024;
        static inline const int KeyLength = 256;
        
        std::array<char, BufferLength> buffer{0};
        std::array<char, KeyLength> key;
};