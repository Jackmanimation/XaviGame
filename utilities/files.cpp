/*
Name        :   files.cpp
Author      :   Denis Jackman
Date        :   27/06/2016
Version     :   1:00:00
Function    :   This snippet reads all the files from a directory and prints out the file names
Compile     :   g++ files.cpp -w -o files

Change History
Name        :   Date        :   Version :   Reason
D Jackman   :   27/06/2016  :   1:00:00 :   Original Version
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <iostream>

using namespace std;

int main()
{
    DIR *dir;
    struct dirent *dp;
    char * file_name;
    dir = opendir("../assets");
    while ((dp=readdir(dir)) != NULL)
    {
        if ( !strcmp(dp->d_name, ".") || !strcmp(dp->d_name, "..") )
        {
            // do nothing (straight logic)
        }
        else
        {
            file_name = dp->d_name; // use it
            cout << "file_name: \"" << file_name << "\"" << endl;;
        }
    }
    closedir(dir);
    return 0;
}
