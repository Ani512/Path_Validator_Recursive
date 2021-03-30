/*
Anirudh Umarji - AMU180000 - CS 3377.0W1	

This Code helps in identifying if a path entered by the user is right and if it is right, then,
checks if the path is a directory and if it is then, recursively gives me the number of files stored,
number of directories in it and the amount of bytes inside the directory according to User input.
*/

#include <iostream>
#include <filesystem>
#include <string>
#include <stdio.h>
#include "version.h"

using namespace std;
namespace fs = std::filesystem;

static long fileCount = 0, directoryCount = 0, sizeCount = 0; // Static variables because of recursive calls
static double VERSION = 1.2;

void parseDir(const fs::path &path, fs::file_status status = fs::file_status{})
{
	fs::directory_options options = (fs::directory_options::skip_permission_denied | fs::directory_options::follow_directory_symlink);
	// cout << path;
	if (fs::exists(path))
	{
		// cout << " exists\n";
		if (fs::is_directory(path))
		{
			// cout << path << " is a directory\n";
			try // Try-catch method to catch any fatal expressions other than links and permissions
			{
				for (auto &p : fs::recursive_directory_iterator(path, fs::directory_options(options))) // Iterating through all files in the directory
				{
					// cout << p.path() << '\n';
					if (fs::is_regular_file(p.path())) // Checking if the file is a regular file
					{
						fileCount++; // Increments if regular file
						sizeCount += fs::file_size(p.path());
					}
					else if (fs::is_directory(p.path()))
					{
						directoryCount++; // Increments if a directory is encountered
					}
				}
			}
			catch (fs::filesystem_error &error)
			{
				cout << "Caught fatal exception: " << error.what() << endl; // If fatal error found due to symlink or permission then exit
				exit(1);
			}
		}
		else
		{
			cout << path << " is not a directory\n"; // Exits if path entered by user not a directory
			exit(1);
		}
	}
	else
	{
		cout << " does not exist\n"; // Exits if invalid path entered by user
		exit(1);
	}

	// Output
	cout << "The total number of directories in directory " << path << " is: " << directoryCount << endl;
	cout << "The total number of files in directory " << path << " is: " << fileCount << endl;
	cout << "The total number of bytes occupied by all files in directory " << path << " is: " << sizeCount << endl;
}

int main(int argc, char *argv[])
{
	if (argc < 1) // Argc < 1 means "0" arguments passed
	{
		cout << "No arguments passed\n";
		exit(1);
	}
	else
	{
		// cout << "Parsing Directory = " << argv[1] << endl << endl;
        printVersion(VERSION); 
		parseDir(argv[1]); // Path stored in argv[1]
	}
	return 0;
}

// Reference -
// https://en.cppreference.com/w/cpp/filesystem
// Comment is this
