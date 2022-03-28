#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
    char c;
    int line = 1;
    ifstream targetFile("../source/file.txt", ios::in);
    ofstream outputFile("../source/output.launch", ios::trunc);
    if (!targetFile)
    {
        cout << "cannot load the file!" << endl;
    }

    while (targetFile.get(c))
    {
        if (c == '\n')
            line++;
    }
    targetFile.close();

    ifstream target("../source/file.txt", ios::in);
    // 重新定位到文件开头
    target.seekg(0, ios::beg);

    string str[line][3];
    for (int i = 0; i < line; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            target >> str[i][j];
        }
    }

    outputFile << "<launch>" << endl;
    for (int i = 0; i < line; i++)
    {
        if (str[i][0] == "rosrun")
        {
            outputFile
                << "    <node pkg="
                << "\""
                << str[i][1]
                << "\" "
                << "name=\""
                << str[i][2]
                << "_node\" "
                << "type=\""
                << str[i][2]
                << "\" />"
                << endl;
        }
        if (str[i][0] == "roslaunch")
        {
            outputFile
                << "    <include file=\"$(find "
                << str[i][1]
                << ")/launch/"
                << str[i][2]
                << "\" />"
                << endl;
        }
    }
    outputFile << "</launch>" << endl;

    target.close();
    outputFile.close();
    return 0;
}
