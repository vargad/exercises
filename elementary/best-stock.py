#!/usr/bin/env python3

def best_stock(data):
    return sorted(data.items(), key=lambda x: x[1])[-1][0]

if __name__ == '__main__':
    print(best_stock({ "CAL": 42.0, "GOG": 190.5, "DAG": 32.2 }))

    assert best_stock({ "CAL": 42.0, "GOG": 190.5, "DAG": 32.2 }) == "GOG"
    assert best_stock({ "CAL": 31.4, "GOG": 3.42, "APL": 170.34 }) == "APL"
