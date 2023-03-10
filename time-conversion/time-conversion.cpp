/**
 * @file time-conversion.cpp
 * @author Alexander Khvolis(ExpliuM)
 * @link https://www.hackerrank.com/challenges/time-conversion/problem?isFullScreen=true
 * @version 0.1
 * @date 2023-02-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <functional>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <locale>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s)
{
    struct std::tm tm;

    std::istringstream is(s);
    string ampm;
    is.imbue(std::locale("en_US.utf-8"));
    is >> std::get_time(&tm, "%H:%M:%S") >> ampm;

    if (ampm.compare("PM") == 0)
    {
        if (tm.tm_hour != 12)
        {
            tm.tm_hour += 12;
        }
    }
    else if (tm.tm_hour == 12)
    {
        tm.tm_hour = 0;
    }

    std::ostringstream oss;
    oss << std::put_time(&tm, "%H:%M:%S");
    std::string result = oss.str();

    return result;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    // fout << result << "\n";
    cout << result << "\n";

    // fout.close();

    return 0;
}
