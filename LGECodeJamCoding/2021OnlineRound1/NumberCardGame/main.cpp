/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 22 - 3 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <fstream>

using namespace std;

void inputByReadConsole()
{
    int T = 0;
    cin >> T;
    string s = "";
}

void inputByReadFile()
{
    ifstream fileInput("F:/Research/CodingPractice/LGECodeJamCoding/LGECodeJamCoding/2021OnlineRound1/NumberCardGame/input.txt");
    string str;
    fileInput >> str;
    int T = 0;
    fileInput >> T;
    cout << T << endl;
    string s = "";
    while (T --> 0) {
        fileInput >> s;
        cout << s << endl;
    }
    fileInput.close();
}

int main()
{
    inputByReadFile();
    return 0;
}
