#include "records.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

int RecordStore::addLinkedRecord(Record record)
{
   if (currentRecordCount < MaxRecords)
   {
      memcpy(&linkedRecords[currentRecordCount], &record, sizeof(Record));
      return currentRecordCount++;
   }
   return -1;
}

const Record* RecordStore::getLinkedRecord(int index)
{
   if (index >= MaxRecords || index >= currentRecordCount)
   {
      std::cerr << "Requested a record beyond what was stored" << std::endl;
      return nullptr;
   }

   return &linkedRecords[index];
}


const Record* RecordStore::findLinkedRecord(std::string name)
{
   auto foundRecord = std::find_if(linkedRecords.begin(), linkedRecords.end(), [&](auto r) { return 0 == std::string_view(r.name.data()).compare(name); });
   if (foundRecord == std::end(linkedRecords))
   {
      return nullptr;
   }
   return &*foundRecord;
}
