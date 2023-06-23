first read two numbers
>,              store first num at c1
>,              store second num at c2
<<              pointer at c0

next convert numbers to integers by subtracting 48
++++++ ++++++   add 12 to c0=12
[               while c0 not 0
 >----          decrease c1 by 4
 >----          decrease c2 by 4
 <<-            decrease c0 by 1
]               pointer at c0=0

next multiply by using the following algorithm
while c1 is not null
    invariant : c4=Bx(num1 minus c1) plus (num2 minus c2) c3= num2 minus c2
    while c2 is not null
        decrease c2
        increase c2
        increase c2
    loop
    while c3 is not null
        decrease c3
        increase c2
    loop
    decrease c1
loop
final result: c1=0 c2=num2 c4=BxA c3=0

>               pointer at c1
[               while c1 not 0
 >              pointer at c2
 [              while c2 not 0
    >+          increase c3
    >+          increase c4
    <<-         decrease c2
 ]
 >              pointer at c3
 [              while c3 not 0
    <+          increase c2
    >-          decrease c3
 ]
 <<-            decrease c1
]               pointer at c1 and c1=0 c3=0 c2=num2 c4=num1 * num2

next separate the digits of the product before printing
>               pointer at c2
[               while c2 not 0
    -           decrease c2
]               pointer at c2 and c2=0
>+              increase c3 gives c3=1
>               pointer at c4
>+++++ +++++    increase c5 to c5=10
<               pointer at c4

[               while c4 not 0        
 -              decrease c4
 >-             decrease c5

 [              while c5 not 0
    >>>         move pointer frwrd 3 places at a time to first zero cell 
 ]
                pointer at zero cell that is multiple of 3 cells after c5  (c8 for first loop)                   
 +++++ +++++    set the zero cell (c8 for 1st loop) to 10
 <<+            add 2 to cell 2 places bfr zero cell(c6 for 1st loop)
 [
    <<<         move pointer bckwrds 3 places at a time to first zero cell
 ]              pointer at 1st zero cell that is multiple of 3 cells behind (c2 for 1st loop)

 >>>>           move pointer 4 places forward from zero cell (pointer at c6)           
]
<-              decrease c5 by 1 (c5 = num1 minus 1)

<+++++ +++++    add 10 to c4
>>>             move pointer to c7
[               while c7 not 0
    -           decrease c7
    <<<-        decrease c4
    >>>         move pointer back to c7
]
<<<             move pointer to c4

convert integer back to ascii character before printing
<++++++ ++++++  add 12 to c3
[               while c3 not 0
 >++++          add 4 to c4
 >              move pointer to c5
 [
     ++++       add 4 to c4
     >          point to c5
 ]
 <              
 [
     <          move pointer backward to first zero cell
 ]
 >-             subtract one from next cell
]

print the two digits
>>              move pointer two places forward
[               if cell not 0
    .           print cell
    <<          move pointer backward two places
]
<               move pointer backwards
[
    <<          move pointer two steps at a time backwards to first zero cell        
]
>>.             print the cell after moving pointer two places forward
[
-               decrease current cell till 0
]
+++++ +++++ .   add 10 and print "\n"
