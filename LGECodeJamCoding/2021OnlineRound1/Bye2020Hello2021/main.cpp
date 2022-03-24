/**
 * author thanhtung thanhtungpfiev@gmail.com
 *
 * date 24 - 3 - 2022
 *
 * class %{Cpp:License:ClassName}
 *
 * brief
 *
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function for finding sum of larger numbers
string findSum(string str1, string str2)
{
    // Before proceeding further, make sure length
    // of str2 is larger.
    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initially take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    return str;
}
void inputByReadConsole()
{
    int T = 0;
    cin >> T;
    while (T --> 0) {
        int N = 0;
        cin >> N;
        vector<string> arr;
        string temp;
        for (int i = 0; i < N; ++i) {
            cin >> temp;
            arr.push_back(temp);
        }
        int cnt = 0;
        for (int i = 0; i < N - 1; ++i) {
            for (int j = i + 1; j < N; ++j) {
                string result = findSum(arr[i], arr[j]);
                if (result.size() > 4) {
                    string temp1 = result.substr(0, 4);
                    string temp2 = result.substr(result.size() - 4);
                    if (temp1 == "2020" && temp2 == "2021") {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << endl;
    }
}

int main()
{
    inputByReadConsole();
    return 0;
}
