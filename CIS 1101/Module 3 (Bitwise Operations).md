# Left Shifting

## EXAMPLE 1:

x << n<br>
15 << 2 <br>
15 in binary is 1111<br>

(Table is aligned to bits (exponents of 2))

0000 1111 <br>
0001 1110  (after 1st shift)<br>
0011 1100  (after 2nd shift)<br>

In terms of bits:<br>
= 15 is now 60  as 32 + 16 + 8 + 4 = 60<br>
In terms of binary:<br>
1111 + 11110 + 111100 = 0b11110000110111001<br>

## EXAMPLE 2:

x >> n
15 >> 2

0000 1111  (15 has now become -15)<br>
0000 0111<br>
0000 0011<br>


> 2's complement is added to get the real value of the number after every addition:

1111 0000 <br>v
+ 1<br>
= 1111 0001<br>
1111 1100<br>
= 0000 0011<br>
+ 1<br>
== 0000 0100 or 4 in math terms<br>

# USING AND (&) ON 2 NUMBERS
99 & 51 = 35

99 - 0110 0011<br>
51 - 0011 0011<br>
== RESULT AFTER USING BITWISE AND (&) --> 0010 0011 (or 35 in math terms as 32 + 2 + 1)<br>
99 - 0110 0011<br>
51 - 0011 0011<br>
== RESULT AFTER USING BITWISE OR (^) --> 0101 0000 (or 80 as 64 + 16)<br>
99 - 0110 0011<br>
51 - 0011 0011<br>
== RESULT AFTER USING BITWISE XOR (|) --> 0111 0011 (or 115 in math)<br>
