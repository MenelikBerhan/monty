,               read first num1 and store at c0
> ,             read second num2 and store ate c1

subtract 48 from c0 and c1 to convert to int
> ++++ ++++ ++++  add 12 to c2 = 12
[
< ----          subtract 4 from c1 12 times
< ----          subtract 4 from c0 12 times
>> -            decrease c2 by 1
]

copy c1 to c2 and c3
<               point to c1 for loop counter
[
> + > +         add 1 to c2 and c3 c1 times
<< -            decrease c1 by 1
]

copy number back to c1 from c3
>>              point to c3
[
<< +            add 1 to c1 c3 times
>> -            decrease c3 by 1
]

next add c1 to c1 c0 minus 1 number of times
<<< -           point to c0 and decrease by 1
[
    next add 1 to c1 c2(=c1) number of times
    >>          point to c2
    [
    < +         add 1 to c1  c2(=c1) number of times
    >> +        add 1 to c3  c2 times to backup c2 and assign it back to c2 after loop
    < -         decrease c2
    ]

    next assign c3 back to c2
    >           point to c3
    [
    < +         add 1 to c2 c3 number of times
    > -         decrease c3
    ]
<<< -           decrease c0
]

next add 48 to c1 to convert to char
>>>              point to c3=0
++++ ++++ ++++  add 12 to c3 = 12
[
<< ++++         add 4 to c1 12 times
>> -             decrease c3 by 1
]
<< .             print c1
