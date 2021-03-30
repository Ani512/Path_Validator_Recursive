/*
Anirudh Umarji - AMU180000 - CS 3377.0W1	

This Code helps in displaying the specific output from the filecnt file 
using pipes and an user argument. 
*/

#include <iostream>
#include <filesystem>
#include <string.h>
#include <stdio.h>
#include "version.h"

using namespace std;
namespace fs = std::filesystem;

int main(int argc, char *argv[])
{
  if (argc < 1) // If user does not enter option
  {
    cout << "No arguments passed\n";
    exit(1);
  }
  else
  {
    string outArray[3];
    string filecntOut;
    int pos = 0;

    while (getline(cin, filecntOut)) // While there is an output in filedisp
    {
      outArray[pos] = filecntOut; // Storing the output from filecnt line by line in an array
      pos++;
    }

    // Output according to User Input
    if (strcmp("-d", argv[1]) == 0)
    {
      cout << outArray[0] << endl;
    }
    else if (strcmp("-f", argv[1]) == 0)
    {
      cout << outArray[1] << endl;
    }
    else if (strcmp("-b", argv[1]) == 0)
    {
      cout << outArray[2] << endl;
    }
  }
}

// Comment is this
