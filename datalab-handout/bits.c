/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) { 
 return ~(~x | ~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */

int getByte(int x, int n) {
  return (x >> (n << 3)) & 0xff;

}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) { 
  return (x >> n) & (~(( (~(!n)) << 31) >> (n + ~1 + 1)));
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	int mask1 = 0x55 | (0x55 << 8) | (0x55 << 16) | (0x55 << 24); // 0x55555555
	int mask11 = 0x33 | (0x33 << 8) | (0x33 << 16) | (0x33 << 24); // 0x33333333
	int mask2 = 0x0f | (0x0f << 8) | (0x0f << 16) | (0x0f << 24);// 0x0f0f0f0f
	int mask3 = 0xff | (0xff << 16); // 0x00ff00ff
	int mask4 = 0xff | (0xff << 8); // 0x0000ffff
	unsigned int ux = x;
	ux = (ux & mask1) + ((ux >> 1) & mask1);
	ux = (ux & mask11) + ((ux >> 2) & mask11);
	ux = (ux & mask2) + ((ux >> 4) & mask2);
	ux = (ux & mask3) + ((ux >> 8) & mask3);
	ux = (ux & mask4) + ((ux >> 16) & mask4);
  return ux;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
  int a = x | (x >> 16);
  a = a | ( a >> 8);
  a = a | (a >> 4);
  a = a | (a >> 2);
  a = a | (a >> 1);
  return (1 ^ (a & 1));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
	unsigned int cneg = ~x + 1;
	unsigned int left = cneg >> (n + ~1 + 1);
	int fneg = (x >> 31) & ((!left) | (!(left^1) & !(cneg ^ (1 << (n + ~1 + 1)))));
	int fpos = (~(x >> 31)) & (!(x >> (n + ~1 + 1)));
	return (fneg | fpos) & 1;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
		int num = x +( (x >> 31) & ( (((!!n)<<31)>>31) & ( (1 << n) - 1 ) ) );
    return num >> n;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	unsigned int ux = x;
	int zero = !(x ^ 0);
	return !zero & !(ux >> 31);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	int negMpos = ((x >> 31) ^ 0) & ((y >> 31) ^ 1) & 1;
	int same = !( ((x >> 31) ^ (y >> 31)) & 1);
	int normal = ((x + ~y + 1));
	int equal = !normal; 
	return negMpos | (same & ((normal >> 31) & 1)) | equal;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
  
  return 2;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
 unsigned frac = uf & 0x7fffff;
 unsigned exp = (uf >> 23) & 0xff;
 if(exp == 0xff && frac)
	 return uf;
 return  uf^0x80000000;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  unsigned int ux;
  int flag = (x >> 31) & 1;
  if(flag) 
    ux = ~x + 1;
  else
		ux = x;
	
	if(x == 0) {
		return 0;
	}
	int cnt = 0;
	unsigned nx = ux;
	while(nx != 0) {
		nx = nx >> 1;
		cnt++;
	}
	int bias = (1 << 7) - 1;
	int exp = cnt - 1 + bias;
  if(cnt <= 24) {
		return (flag << 31) | (exp << 23) | ((ux << (24 - cnt)) & 0x7fffff);	
	} else {
		int num1 = cnt - 24; // 1 count in the head
		int left = (0xff >> (8 - num1)) & ux; // 1 should be omit or becaome carry
		int middle = 1 << ((cnt - 24) - 1); // used to round to even
		int frac = (ux >> (num1)) & 0x7fffff; // frac section
		if(left == middle) {
			if(frac & 1) {
				if(frac == 0x7fffff) {
					frac = 0;
					exp += 1;
				} else {
					frac += 1;	
				}
			} else {
				frac = frac;	
			}
		} else if(left > middle) {
			if(frac == 0x7fffff) {
				frac = 0;
				exp += 1;
			}	else {
				frac += 1;
			}
		} else {
			frac = frac;
		}
		return (flag << 31) | (exp << 23) | frac;
	}
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  unsigned frac = uf & 0x7fffff;
  unsigned exp = (uf >> 23) & 0xff;
  if(exp == 0xff && frac)
 	 return uf;
  int flag = uf & (1 << 31);
  if(exp != 0) {
	 if(exp == 0xff || exp + 1 == 0xff) {
		uf = flag | (0xff << 23) | 0x800000;
	 } else {
		int newExp = exp + 1;
  	 	uf = (uf & (~(0xff << 23))) | (newExp << 23);
	 }
  } else {
	 uf = flag | ( frac << 1 );
  }
  return uf;
}
