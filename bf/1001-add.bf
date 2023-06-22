,               read first num1 and store at c0
> ,             read second num2 and store ate c1

next subtract 48 from c1 to convert to int
> ++++ ++++ ++++  add 12 to c2 = 12
[
< ----          subtract 4 from c1 12 times
> -             decrease c2 by 1
]

<               point to c1 for next loop
[
< +             add one to c0 c1 times
> -             decrease c1 by 1
]               
< .             print c0 = num1 plus num2