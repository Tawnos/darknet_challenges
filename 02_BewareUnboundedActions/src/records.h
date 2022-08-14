#include <cstring>
#include <string>
#include <array>
#include <optional>
#include <utility>
#include <iostream>

class Record
{
    friend class RecordStore;
public:
    static inline const int MaxNameLength = 32;
    static inline const int KeyLength = 64;
    
    Record() = default;
    Record(std::string userName, std::string userKey) {
        if (userName.length() > MaxNameLength || userKey.length() > KeyLength) {
            throw "Nope";
        }

        memmove(name.data(), userName.c_str(), userName.length());
        memmove(key.data(), userKey.c_str(), userKey.length());
    }

    friend std::ostream& operator << (std::ostream& os, Record r) {
        os << "("
            << std::string_view(r.name.data(), Record::MaxNameLength) << ", "
            << std::string_view(r.key.data(), Record::KeyLength)
            << ")";
        return os;
    }

private:

    std::array<char, MaxNameLength> name{ 0 };
    std::array<char, KeyLength> key{ 0 };
};

class RecordStore
{
private:
    static inline const int MaxRecords = 10;

public:
    RecordStore(Record userRecord) : myRecord(userRecord) {}
    int addLinkedRecord(Record record);
    const Record* getLinkedRecord(int index);
    const Record* findLinkedRecord(std::string name);

private:
    int currentRecordCount = 0;

    Record myRecord;
    std::array<Record, MaxRecords> linkedRecords{ };
};