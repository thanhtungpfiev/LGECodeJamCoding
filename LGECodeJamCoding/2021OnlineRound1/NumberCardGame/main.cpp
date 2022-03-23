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
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int convertCharToNumber(char c)
{
    int number;
    if (c >= '0' && c <= '9') {
        number = int(c) - '0';
    } else {
        number = int(c) - 'A' + 10;
    }
    return number;
}

char convertNumberToChar(int num)
{
    char ch;
    if (num >= 0 && num <= 9) {
        ch = char(num + '0');
    } else {
        ch = char(num - 10 + 'A');
    }
    return ch;
}

string mul(vector<int>& S, vector<int>& D, int B)
{
    string result;
    vector<int> temp(S.size() + D.size() - 1);

    for (int i = 0; i < S.size(); ++i) {
        for (int j = 0; j < D.size(); ++j) {
            temp[i + j] += ((S[i]) * (D[j]));
        }
    }
    for (int i = temp.size() - 1; i > 0; --i) {
        if (temp[i] >= B) {
            temp[i - 1] +=  temp[i] / B;
            temp[i] %= B;
        }
    }
    if (temp[0] >= B) {
        int new0 = temp[0] / B;
        temp[0] %= B;
        temp.insert(temp.begin(), new0);
    }
    for (int i = 0; i < temp.size(); ++i) {
        result += convertNumberToChar(temp[i]);
    }
    return result;
}

void genBinaryArray(vector<vector<int>>& binaryArray, vector<int>& c, int step)
{
    if (step == c.size()) {
        if (count(c.begin(), c.end(), 1) + count(c.begin(), c.end(), 0) == c.size()) {
            binaryArray.push_back(c);
        }
        return;
    }
    for (int i = 0; i < 2; ++i) {
        c[step] = i;
        genBinaryArray(binaryArray, c, step + 1);
    }
}

void inputByReadConsole()
{
    int T = 0;
    cin >> T;
    string s = "";
    while (T --> 0) {
        cin >> s;
        vector<int> arr;
        vector<int> S;
        vector<int> D;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '6') {
                arr.push_back(9);
            } else {
                arr.push_back(convertCharToNumber(s[i]));
            }
        }
        sort(arr.begin(), arr.end(), greater<int>());
        vector<vector<int>> binaryArray;
        vector<int> c(arr.size());
        genBinaryArray(binaryArray, c, 0);
        long long result = 0;
        for (int i = 0; i < binaryArray.size(); ++i) {
            vector<int> e = binaryArray[i];
            int cnt1 = 0, cnt2 = 0;
            long long firstNum = 0, secondNum = 0;
            for (int j = e.size() - 1; j >= 0; --j) {
                if (e[j] == false) {
                    firstNum += arr[j] * pow(10, cnt1);
                    cnt1++;
                } else {
                    secondNum += arr[j] * pow(10, cnt2);
                    cnt2++;
                }
            }
            result = max(result, firstNum * secondNum);
        }
        cout << result << endl;
    }
}

void inputByReadFile()
{
    ifstream fileInput("F:/Research/CodingPractice/LGECodeJamCoding/LGECodeJamCoding/2021OnlineRound1/NumberCardGame/input.txt");
    string str;
    fileInput >> str;
    int T = 0;
    fileInput >> T;
    string s = "";
    while (T --> 0) {
        fileInput >> s;
        vector<int> arr;
        vector<int> S;
        vector<int> D;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '6') {
                arr.push_back(9);
            } else {
                arr.push_back(convertCharToNumber(s[i]));
            }
        }
        sort(arr.begin(), arr.end(), greater<int>());
        vector<vector<int>> binaryArray;
        vector<int> c(arr.size());
        genBinaryArray(binaryArray, c, 0);
        long long result = 0;
        for (int i = 0; i < binaryArray.size(); ++i) {
            vector<int> e = binaryArray[i];
            int cnt1 = 0, cnt2 = 0;
            long long firstNum = 0, secondNum = 0;
            for (int j = e.size() - 1; j >= 0; --j) {
                if (e[j] == false) {
                    firstNum += arr[j] * pow(10, cnt1);
                    cnt1++;
                } else {
                    secondNum += arr[j] * pow(10, cnt2);
                    cnt2++;
                }
            }
            result = max(result, firstNum * secondNum);
        }
        cout << result << endl;
    }
    fileInput.close();
}

int main()
{
    inputByReadConsole();
    return 0;
}
