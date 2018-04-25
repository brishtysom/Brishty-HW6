/*
 * Binary File IO displayed in CDK Matrix
 *
 * File:   example1.cc
 * Author: Brishty Som
 * Email:  bxs151130@utdallas.edu
 */

#include <iostream>
#include "cdk.h"
#include <fstream>
#include <iomanip>
#include "BinaryClasses.h"
#include <sstream>
#include <string>

#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 15
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;


int main()
{
  //Read Header Objects from Binary File
  stringstream stream;
  const int maxLength= 25;

  BinaryFileHeader *myHeader= new BinaryFileHeader();
  BinaryFileRecord *myRecord= new BinaryFileRecord();
  ifstream binInfile;
  binInfile.open("cs3377.bin", ios::in | ios::binary);
  binInfile.read((char *) myHeader, sizeof(BinaryFileHeader));
  stream <<hex <<uppercase<< myHeader->magicNumber<<" "<<dec<<myHeader->versionNumber<<" "<<dec<<myHeader->numRecords;
  string result1,result2,result3;
  stream>>result1>>result2>>result3;
  string fullHeader1= "Magic:"+result1;
  string fullHeader2= "Version:"+result2;
  string fullHeader3= "NumRecords:"+result3;
const char* header1= fullHeader1.c_str();
 const char* header2= fullHeader2.c_str();
 const char* header3= fullHeader3.c_str();

 //Read Record Objects from Binary File
 stringstream buffer1,buffer2,buffer3,buffer4,len1,len2,len3,len4;

   binInfile.read((char*) myRecord, sizeof(BinaryFileRecord));
   len1<< unsigned(myRecord->strLength);
   for(int j=0; j<maxLength;j++){
     buffer1<< myRecord->stringBuffer[j];

   }

   binInfile.read((char*) myRecord, sizeof(BinaryFileRecord));
   len2<< unsigned(myRecord->strLength);  
 for (int j=0; j<maxLength;j++){
     buffer2 << myRecord->stringBuffer[j];
   }  

   binInfile.read((char*) myRecord, sizeof(BinaryFileRecord));
   len3<< unsigned(myRecord->strLength);   
for(int j=0; j<maxLength;j++){
     buffer3 << myRecord->stringBuffer[j];
   }   

   binInfile.read((char*) myRecord, sizeof(BinaryFileRecord));
   len4<< unsigned(myRecord->strLength);   
for(int j=0;j<maxLength;j++){
     buffer4 << myRecord->stringBuffer[j];
   }

//Formating to const char* for matrix cells

 string seed,money,l1,l2,l3,l4,leader,entre,skill;
   len1>>l1;
   len3>>l2;
   len3>>l3;
   len4>>l4;
   buffer1 >> seed >>money;
   buffer2>>leader;
   buffer3>>entre;
   buffer4>>skill;
   string fullBox1= "strlen:"+l1;
   string fullBox2= "strlen:"+l2;
   string fullBox3= "strlen:"+l3;
   string fullBox4= "strlen:"+l4;
   string seedMoney= seed+" "+money;
   const char* length1= fullBox1.c_str();
   const char* length2= fullBox2.c_str();
   const char* length3= fullBox3.c_str();
   const char* length4= fullBox4.c_str();
   const char* word1= seedMoney.c_str();
   const char* word2= leader.c_str();
   const char* word3= entre.c_str();
   const char* word4= skill.c_str();

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"R0", "a", "b", "c"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"C0", "a", "b", "c","d","e"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  /*
   * Dipslay a message
   */

setCDKMatrixCell(myMatrix, 1, 1,header1);
  setCDKMatrixCell(myMatrix,1,2,header2);
  setCDKMatrixCell(myMatrix, 1, 3,header3);
  setCDKMatrixCell(myMatrix,2,1, length1);
  setCDKMatrixCell(myMatrix,2,2, word1);
  setCDKMatrixCell(myMatrix,3,1,length2);  
setCDKMatrixCell(myMatrix,3,2,word2);
 setCDKMatrixCell(myMatrix,4,1,length3);
 setCDKMatrixCell(myMatrix,4,2,word3);
 setCDKMatrixCell(myMatrix,5,1,length4);
 setCDKMatrixCell(myMatrix,5,2,word4);
  drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
  sleep (10);


  // Cleanup screen
  endCDK();
}
