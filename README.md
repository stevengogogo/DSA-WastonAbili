# Double Linked List: List migration

## Requirement

- Time limit: 1s
- Mem Limit: 65536 KB


## Constraint

- n of cargos: max 10e6
- k of lines: 10e3
- l is the index: [0,10e4]

## Printout

- print logs from 0-(k-1) lines
- skip null line

## Plan

![](img/DLL.jpg)

- Reader
    - Parse a string
    - Parse an int
    - Parse an int 
    - Terminate for EOF




## Implementation of Double linked list

![](img/Plan.png)

https://gist.github.com/mycodeschool/7429492



## Enter

![](img/Enter.png)


- New node
  - link `.prev` to `last node`
  - link `.next` to `End`
- End node
  - Link `.prev` to `new node`
- Last node
  - Link `.next` to `new node`


```pseudo
EnterLine(list*,log)

ptr_end  = list->end
ptr_last = list->end.prev

end
```


## Reverse a doubly linked list


## Memory

- Node
    - 1 x `int`: 4 byte
    - 2 x `pointer`: 8 bytpe
    - Sum: 20 byte
    - 10e6 nodes: 
        - 20 MB



## References

1. XOR linked list. [[wiki](https://en.wikipedia.org/wiki/XOR_linked_list)]