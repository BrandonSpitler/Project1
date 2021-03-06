/* 
 * CS 154 Project 1: Bit Manipulation
 * 
 * If working solo (not with a partner), your repository
 * itself identifies who you are.
 * 
 * If you are working as a team, please identify yourselves
 * with your "CNetID: Name", by first uncommenting, and then 
 * editing the following two lines, filling your CNetIDs and Names */
char PP0[] = "jsmiller: Joshua S. Miller";
char PP1[] = "dpbooth: Daniel P. Booth";
/* Please leave "PP0" and "PP1" as is.
 * We will be grading the bits.c handed in by the FIRST ("PP0") person
 * in the pair above.
 * The SECOND ("PP1") person should hand in a bits.c with the SAME TWO LINES
 * (with "PP0" and "PP1") above, so that we can make sure the pair of people
 * really intended to be a pair. We will NOT be grading the bits.c handed in
 * by the SECOND person.
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

You will provide your solution to this Project by
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
  1. Use the dlc ("data lab checker") compiler (described in the handout) to 
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
       return ~(~x|~y);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x+1;
}
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
  /* multiply m&n by 8 */
  int SM = m<<3;
  int SN = n<<3;
  /* move set bits to mask bytes m and n */
  int M1 = 0xFF<<SN;  
  int M2 = 0xFF<<SM;
  /* mask out byte n, move it the rightmost and then move it */
    /* back to the m byte position */
  int A = (((x&M1)>>SN)<<SM)&M2;
  /* mask out byte m, move it the rightmost and then move it */
    /* back to the n byte position */
  int B = (((x&M2)>>SM)<<SN)&M1;
  /* turn off bytes m and n in the original x */
  int C = x&~M1&~M2;
  /* copy repositioned bytes into the original */
  return A|B|C;

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

  /* Smear the the top bit to create 111... for negative */
    /* and 000.... for positive */
  int A = x>>31;
  /* Create a mask with bits above bit n turned on  */
  int B = (1<<31)>>(33+~n);
  /* if positive, mask bits that go overflow into mask created in B*/
  /* if negative, convert it to positive, subtract one, and do the same */
  int C =  (~A&B&x) | (A&B&~x);
  /* if it fits, C will be zero, so return !0 = 1 */
  /* if it doesn't fit, there will be overlap, C is nonzero, !C = 0 */
  return !C;

}

/* 
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1, 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
  /* naively add x and y */
  int A = x+y;
  /* is that addition negative? smear topmost bit into B */
  int B = A>>31;
  /* is x negative? smear topmost bit of x into C */
  int C = x>>31;
  /* is y negative? smear topmost bit of y into C */
  int D = y>>31;
  /* if x and y both positive, P = 111... otherwise P = 000... */
  int P = ~C&~D;
  /* if x and y both negative N = 111..., otherwise N = 000... */
  int N = C&D;
  /* if both positive and the addition negative, then NO! overflow, non-zero */
  /* if both negative and the addition is positive then  NO! overflow, non-zero*/
  /* combine the above results, if neither is true, ie the addition is the right sign  */
  /* or the are opposite signs (no danger of overflow), then Z is zero */
  int Z = (P&B)|(N&~B);
  /* return 1 for non-overflow, and 0 for overflow */
  return !Z;
}

/* 
 * isGreater - if x > y  then return 1, else return 0 
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
  /* Smear negation bit to create a 111... for negative, 000.. for positive */
  int A = x>>31;
  int B = y>>31;
  /* Take the opposite of these masks to use later */
  int nA = ~A;
  int nB = ~B;
  /* C is true if, x>0 && y<0, and false if x<0, y>0 */
  int C = nA&B;
  /* P tells us if they are both positive */
  int P = nA&nB;
  /* N tells us if they are both negative */
  int N = A&B;
  /* if x < 0, then x2 = -y -1 */
  int x2 = (P&x) | (N&~y);
  /* if y < 0, then y2 = -x -1 */
  int y2 = (P&y) | (N&~x);
  /* subtract y2 from x2 -> D */
  int D = x2+~y2+1;
  /* if D is less than 0, E is non-zero and x > y */
  int E = ~(D>>31)&D;
  /* combine opposite sign comparison with subtraction */
    /* comparison/ convert to 0 or 1 */
  int Z = !!(C|E);

  return Z;
}

/* 
 * rotateLeft - Rotate x to the left by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateLeft(0x87654321,4) = 0x76543218
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateLeft(int x, int n) {
  /* shift top n bits left */
  int A = x<<n;
  /* take negative n -1 to use for subtraction later */
  int N = ~n;
  /* shift x right 32 - n bits so the top n bits are  */
    /* int the first n bit slots */
  int B = x>>(33+N);
  /* create a mask with only n right-most bits on */
  int C = ~((1<<31)>>(32+N));
  /* use that mask to pull out the bits we moved there from the left */
  int D = C&B;
  /* splice the new right-most bits into the left shifted x */
  return A|D;
  
}

/* 
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
  /* smear the negation bit to create negation truth value */
  int A = x>>31;
  /* negate x */
  int N = ~x+1;
  /* create B which is the same as x, but with the negation bit  */
    /* garunteed to be on */
  int B = N|(1<<31);
  /* if our truth value A is all ones, then x is negative, Z = B */
  /* if our truth value A is all zeros, then Z = x */
  int Z = (~A&x) | (A&B);
  /* mask G handles the case of -0 */
  int G = (!!(x<<1)<<31)>>31;
  return Z&G;
}

/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
  /* smear negation bit, if negative, A = 1111.... */
		      /* if positive, A = 000... */
  int A = x>>31;
  /* negate x */
  int N = ~x+1;
  /* if A is all zeros A&N = 00, then return 11...&x = x */
  /* if A is all ones A&N = N, then return 000...&x = 0 */
  return  (~A&x) | (A&N);
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
  /* mask A is topmost bit */
  int A = 1<<31;
  /* smear A to make B cover the bits through the exponent */
  int B = A>>8;
  /* take all bits except the exponent and negation bit -> mask C */
  int C = ~0^B;
  /* turn negation bit in C on -> D*/
  int D = B^A;
  /* check to see if all bits in the exponent are on */
  int E = (D&uf)^D;
  /* are any of the fractional bits on? */
  if (C&uf)
    /* if so, are the exponent bits all on? this measn NaN */
    if(!E)
      /* return original */
      return uf;
  /* otherise, simply flip the negation bit in the original and return */
  return uf^A;

}

/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
  int s_mask = 1 << 31;
  int temp_mask = (s_mask >> 8);
  int e_mask = s_mask^temp_mask;
  int neg_1 = s_mask >> 31;
  int f_mask = ~temp_mask;
  int odd_mask = 3;
  int case_mask = 1 << 22;
  int s = s_mask & uf;
  int e = e_mask & uf;
  int f = f_mask & uf;
  int E = e_mask ^ e;
  int odd = odd_mask & f;
  int O = !(odd^3);
  int shift = (f + O) >> 1;

  /* NaN Case */
  if (!E)
    return uf;
  /* exp = 0 case */
  if (!e){
    return s | shift;
  }
  /* exp = 1 case */
  /* shift from norm to denorm */
  if (!((e >> 23)^1)){
    return s | case_mask | shift;
  }
  /* decrease exp by 1*/
  return s | ((e + neg_1)&e_mask) | f;
  
  return 2;

}
