#!/usr/bin/env python3

def bigger_price(limit, data):
    return sorted(data, reverse=True, key=lambda d: d["price"])[0:limit]

if __name__ == '__main__':
    print(bigger_price(2, [
            {"name": "cheese", "price": 110},
            {"name": "wine", "price": 152},
            {"name": "meat", "price": 60},
            {"name": "olives", "price": 50}
        ]))

    assert bigger_price(2, [
            {"name": "cheese", "price": 110},
            {"name": "wine", "price": 152},
            {"name": "meat", "price": 60},
            {"name": "olives", "price": 50}
        ]) == [
            {"name": "wine", "price": 152},
            {"name": "cheese", "price": 110}
        ]

    assert bigger_price(1, [
            {"name": "pen", "price": 2},
            {"name": "paper", "price": 120}
        ]) == [{"name": "paper", "price": 120}]
