#!/usr/bin/env ruby

def bigger_price(limit, data)
    return data.sort_by{ |p| p[:price] }.reverse[0..limit-1]
end

if __FILE__ == $0
    p(bigger_price(2, [
            {name: "cheese", price: 110},
            {name: "wine", price: 152},
            {name: "meat", price: 60},
            {name: "olives", price: 50}
        ]))

    raise unless bigger_price(2, [
            {name: "cheese", price: 110},
            {name: "wine", price: 152},
            {name: "meat", price: 60},
            {name: "olives", price: 50}
        ]) == [
            {name: "wine", price: 152},
            {name: "cheese", price: 110}
        ]

    raise unless bigger_price(1, [
            {name: "pen", price: 2},
            {name: "paper", price: 120}
        ]) == [{name: "paper", price: 120}]
end
