#include <iostream>
#include <cassert>
#include <set>
#include <map>
#include <string>
#include <regex>
#include <algorithm>

std::string date_time(std::string const &time) {
    static const char *months[] = {"January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    int day = std::stod(time.substr(0,2));
    int month = std::stod(time.substr(3,2))-1;
    auto year = time.substr(6,4);
    int hour = std::stod(time.substr(11,2));
    int minute = std::stod(time.substr(14,2));
    return std::to_string(day)+" "+months[month]+" "+year+" year "
        +std::to_string(hour)+(hour==1 ? " hour " : " hours ")
        +std::to_string(minute)+(minute==1 ? " minute" : " minutes");
}

int main()
{
    std:: cout << date_time("01.01.2018 00:00") << std::endl;
    assert(date_time("01.01.2018 00:00") == "1 January 2018 year 0 hours 0 minutes");
    assert(date_time("04.08.1984 08:15") == "4 August 1984 year 8 hours 15 minutes");
    assert(date_time("17.12.1990 07:42") == "17 December 1990 year 7 hours 42 minutes");
}
