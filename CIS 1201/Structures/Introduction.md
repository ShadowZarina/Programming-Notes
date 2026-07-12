## SAMPLE PROBLEM 1 (DOT NOTATION)
```
#include <stdio.h>

//make a structure fraction
struct Fraction1 {
    int num1;
    int den1;
};

//adddition of fractions
int main() {
    
    struct Fraction1 s1;
    struct Fraction1 s2;
    
    s1.num1 = 50;
    s1.den1 = 100;
    s2.num1 = 15;
    s2.den1 = 30;
    
    // Formula: (n1*d2 + n2*d1) / (d1*d2)
    float result = (float)(s1.num1 * s2.den1 + s2.num1 * s1.den1) / (s1.den1 * s2.den1);
    
    printf("%d/%d + %d/%d = %.2f", s1.num1, s1.den1, s2.num1, s2.den1, result);

    return 0;
}
```
## OUTPUT
50/100 + 15/30 = 1.00
