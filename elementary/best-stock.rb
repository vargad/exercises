#!/usr/bin/env ruby

def best_stock(data)
    return data.sort_by{|k,v| v }[-1][0]
end

if __FILE__ == $0
    puts(best_stock({ CAL: 42.0, GOG: 190.5, DAG: 32.2 }))

    raise unless best_stock({ CAL: 42.0, GOG: 190.5, DAG: 32.2 }) == :GOG
    raise unless best_stock({ CAL: 31.4, GOG: 3.42, APL: 170.34 }) == :APL
end
