#!/usr/bin/env python3

def date_time(time):
    months = ["January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"]
    hour, minute = int(time[11:13]), int(time[14:16])
    return f"{int(time[0:2])} {months[int(time[3:5])-1]} {time[6:10]} year {hour} hour{'s' if hour!=1 else ''} {minute} minute{'s' if minute!=1 else ''}"

if __name__ == '__main__':
    print(date_time("01.01.2018 00:00"))
    assert date_time("01.01.2018 00:00") == "1 January 2018 year 0 hours 0 minutes"
    assert date_time("04.08.1984 08:15") == "4 August 1984 year 8 hours 15 minutes"
    assert date_time("17.12.1990 07:42") == "17 December 1990 year 7 hours 42 minutes"
