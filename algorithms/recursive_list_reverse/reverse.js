#!/usr/bin/env node
// 2017 Daniel Varga (vargad88@gmail.com)

class LinkedList
{
    constructor(data, rest=null)
    {
        this.data = data;
        this.next = rest;
    }

    toString()
    {
        return `${this.data}, ${this.next}`;
    }
};

function make_list()
{
    // alternate solution
    //return Array.from(arguments).reverse().reduce((c, e) => new LinkedList(e, c), null)
    list = null
    for (let e of Array.from(arguments).reverse())
        list = new LinkedList(e, list)
    return list
}

function reverse(list, rest=null) {
    if (Object.is(list, null)) return rest;
    return reverse(list.next, new LinkedList(list.data, rest))
}

let l = make_list(1,2,3,4,5,6,7)
console.log(l.toString())
let l2 = reverse(l)
console.log(l2.toString())
