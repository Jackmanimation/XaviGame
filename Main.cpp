#include <fstream>
#include <iostream>

using namespace std;
bool gDebugMode = false;

int main (int argc, char* args[] )
{
    gDebugMode = true;
    ofstream logfile;
    gDebugMode = true;
    if (gDebugMode)
    {
        // open a file in write mode.
        logfile.open("/Users/denisjackman/Documents/workspace/JackmanGame/game.log");
    }
  	cout << " -- Game Version 1.0 (Test) -- " << endl;
	cout << " --- Starting ---" << endl;
    if (gDebugMode)
    {
      	logfile << " -- Game Version 1.0 (Test) -- " << endl;
	    logfile << " --- Starting ---" << endl;
    }
    int i=1;
    for (;i<argc;i++)
    {
        cout << "Argument " << i << " Arg : " << args[i] << endl ;
    }


	cout << " --- Ending ---" << endl;
    if (gDebugMode)
    {
	    logfile << " --- Ending ---" << endl;
    }

    if (gDebugMode)
    {
        // close the opened file.
        logfile.close();
    }
  	return 0;
}