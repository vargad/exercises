#!/usr/bin/env ruby

def date_time(time)
    months = ["January", "February", "March", "April", "May", "June",
              "July", "August", "September", "October", "November", "December"].freeze
    hour, minute = time[11..12].to_i, time[14..15].to_i
    return "#{time[0..1].to_i} #{months[time[3..4].to_i-1]} #{time[6..9]} year #{hour} hour#{hour!=1 ? 's' : ''} #{minute} minute#{minute!=1 ? 's' : ''}"
end

if __FILE__ == $0
    puts(date_time("01.01.2018 00:00"))
    raise unless date_time("01.01.2018 00:00") == "1 January 2018 year 0 hours 0 minutes"
    raise unless date_time("04.08.1984 08:15") == "4 August 1984 year 8 hours 15 minutes"
    raise unless date_time("17.12.1990 07:42") == "17 December 1990 year 7 hours 42 minutes"
end
