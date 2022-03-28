#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    ifstream targetFile("/Users/mafumaful/code/C:C++/ROS tools/src/test1.cpp", ios::in);
    if (!targetFile)
    {
        cout << "cannot load the file!" << endl;
    }

    return 0;
}
