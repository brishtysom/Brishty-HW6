#ifndef BINARYCLASSES_H_
#define BINARYCLASSES_H_

#include "stdint.h"
using namespace std;


class BinaryFileHeader
{
 public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;

};

const int maxRecordStringLength= 25;

class BinaryFileRecord
{
 public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];

};

#endif //BINARYCLASSES_H
