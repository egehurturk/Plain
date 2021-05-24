# Plain

Plain is a programming language capable of basic math operations

```txt
? this is a comment, this will be ignored


? variable declaration:
? (def <varname> := <int_literal>)
? multiple variable declarations are not allowed (as of v0.0.0.1 development):
? NOT ALLOWED: (dev <varname1> := <int_literal>, <varname2> := <int_literal>)
? statements end with a period (.)

def a := 45.
def b:=34.
def c := 45.
def d := 64.
def e := 34.
def f := 23.


? a + b + c + d + e + f
add (a,b,c,d,e,f).

? b - c - d - e - f - a
sub (b,c,d,e,f,a).

? 4 * 5 * a * b * c
mul (4,5,a,b,c).

? print value of a
p   (a).

? print value of a * b
p   (mul (a,b) ).

```
