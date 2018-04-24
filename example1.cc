/*
 * Usage of CDK Matrix
 *
 * File:   example1.cc
 * Author: Stephen Perkins
 * Email:  stephen.perkins@utdallas.edu
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
  stringstream stream;

  BinaryFileHeader *myHeader= new BinaryFileHeader();
  ifstream binInfile;
  binInfile.open("cs3377.bin", ios::in | ios::binary);
  binInfile.read((char *) myHeader, sizeof(BinaryFileHeader));
  stream <<hex <<uppercase<< myHeader->magicNumber<<" "<<dec<<myHeader->versionNumber<<" "<<dec<<myHeader->numRecords;
  string result1,result2,result3;
  stream>>result1>>result2>>result3;
  string fullHeader1= "Magic: "+result1;
  string fullHeader2= "Version: "+result2;
  string fullHeader3= "NumRecords: "+result3;
const char* header1= fullHeader1.c_str();
 const char* header2= fullHeader2.c_str();
 const char* header3= fullHeader3.c_str();

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
  drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
  sleep (10);


  // Cleanup screen
  endCDK();
}
