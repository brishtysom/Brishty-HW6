//Brishty Som

#include <fstream>
#include "BinaryClasses.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  const int maxLength= 25;

  BinaryFileHeader *myHeader= new BinaryFileHeader();
  BinaryFileRecord *myRecord= new BinaryFileRecord();

  ifstream binInfile;
  binInfile.open("cs3377.bin", ios::in | ios::binary);
 binInfile.read((char *) myHeader, sizeof(BinaryFileHeader));
 printf("Magic: 0x%X\n", myHeader->magicNumber);  
 cout << "Version " <<dec<< myHeader->versionNumber<<endl;
 cout << "Records "<<dec<< myHeader->numRecords<<endl;
 //for (uint64_t i=0; i <myHeader->numRecords; i++){

 binInfile.read((char*) myRecord, sizeof(BinaryFileRecord));
 cout<< unsigned(myRecord->strLength)<<endl;
 for(int i=0; i<maxLength; i++){
   cout << myRecord->stringBuffer[i];
 }
 cout <<endl;
binInfile.close();

 return 0;
}
