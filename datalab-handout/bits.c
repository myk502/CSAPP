/* 
 * CS:APP Data Lab 
 * 
 * 
 * Finished by fanesemyk, a self-learner of CSAPP	
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
	return ~(~x|~y);
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
	int shift=n<<3;
	return (x>>shift)&0xff;
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

	//First get the result of arithmaticshift,then set 0 of the high bits
	//the mask 0x00..011..1 could be get by its reveserse
	int mask=(1<<31>>31)<<(32+~n)<<1;//avoid undefined behaviour
	mask=~mask;
	return (x>>n)&mask;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
	//take reference to XuYajing's blog
	//use divide and conquer,first divide x to 8*4bit
	//The address:https://elegenthus.github.io/post/Manipulating%20Bits/
	int sum=0,mask;
	mask=0x11|(0x11<<8);//Now mask equals to 0x1111
	mask=mask|(mask<<16);//Now mask equals to 0x11111111
	sum+=x&mask;
	sum+=(x>>1)&mask;
	sum+=(x>>2)&mask;
	sum+=(x>>3)&mask;
	//4 bits a group
	mask=0xff|(0xff<<8);//Now mask equals to 0xffff
	sum=(sum&mask)+((sum>>16)&mask);
	mask=(0xf<<8)+0xf;//Now mask equals to 0x0f0f
	sum=(sum&mask)+((sum>>4)&mask);
	mask=0xff;
	sum=(sum&mask)+((sum>>8)&mask);
	return sum;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
	//just like the xor trick
	//calculate the and sum of all bits in ~x
	int t=~x;
	t=t&(t>>16);
	t=t&(t>>8);
	t=t&(t>>4);
	t=t&(t>>2);
	t=t&(t>>1);
	t&=0x1;
	return t;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
	return 1<<31;
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
int fitsBits(int x, int n) 
{
	//To see whether the (n-1) bit equals to all MSB (w-n) bits
	x=x>>(n+~0);
	//(x==0)||(x==-1)
	return (!x)|(!(x+1));
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
	int bias,flag;//bias is the bias needed for negative number
	//flag is the MSB of x
	flag=(x>>31);
	bias=(1<<n)+(~0);
	bias&=flag;//Only negative numbers need bias
	x+=bias;
	return x>>n;
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
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
	//when x is 0,return 0
	int flag=(x>>31);//Now the LSB of flag is the MSB of x
	flag&=0x1;//only keep the LSB of flag
	return (!flag)^(!x);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
	//we can not use y-x to avoid overflow
	//This problem is too hard so I take reference to Internet
	//when x and y has the same MSB，calculate y-x then !it
	//else just return x_flag(the MSB of x)
	int y_minus_x_flag,x_flag,y_flag,y_minus_x=y+~x+1;
	//flag means the MSB of a number
	//calculate y-x
	y_minus_x=y+~x+1;
	y_minus_x_flag=!!(y_minus_x>>31);//a new way to get the MSB of a number
	x_flag=!!(x>>31);
	y_flag=!!(y>>31);
	return (!y_minus_x_flag&(!(x_flag^y_flag))) | (x_flag&(x_flag^y_flag));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
	//This program takes refrence to the Internet
	//First consider the First 16 bit of x,if x>0xffff then the last 16 bit is useless so we can do right shift
	//After the right shift,what is left is the original First 16 bits
	//t records the answer
	//use (!!x) as a representation of (x!=0)
	//use bit-or to do add operation
	int s,t,u;
	u=x;
	t = (!!(u >> 16)) << 4;
	u >>= t;
	s = (!!(u >> 8)) << 3;
	u >>= s;
	t |= s;
	s= (!!(u >> 4)) << 2;
	u >>= s;
	t |= s;
	s=(!!(u >> 2)) << 1;
	u >>= s;
	t |= s;
	return (t | (u >> 1));
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
	//check whether uf is NaN
	unsigned mask;
	int temp;
	mask=1U<<31;
	temp=uf | mask;
	temp >>= 23;
	if((!(~ temp)) && (!!(uf<<9))  )
		return uf;
	return uf ^ mask;
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
	int flag = (x & 0x80000000), i, val1, val2, len, tempp, temp;//flag equals to (1 << 31) or 0,indicating the sign bit of x
	if(x == 0x80000000)//if x equals to INT_MIN
		return 0xcf000000;//Then we can not take -x, so just return the answer
	if(flag)//flag equals to (1 << 31) or 0, and flag is considered true when flag equals to (1 << 31)
		x = -x;//x now equals to abs(x)
	i = 31;//initialization of i, i will be the first bit of 1(from left to right, except the sign bit)
	do
	{
		if( x >> (--i) & 0x1)
			break;
	}
	while(i);
	if(x == 0)//x equals to zero
		return 0;
	temp = i + 127;//This temp is exp, 127 is the bias
	len = i - 23;//if i is greater than 23, than len is the number of bits that needed to be rounded
	if(len > 0)
	{
		val2 = x & ((0xffffffffU) >> (32 - len) );//Save the bits that will be rounded in val2
		val1 = (x >> len) & 0x007fffff;//val1 is the frac domain
		tempp = 1 << (len - 1);//set tempp to justify the round stat
		if((val2 > tempp) || ((val2 == tempp) && ((val1 & 0x1))))//There is a carry '1' here
			val1++;
	}
	else
		val1 = (x << (-len)) & 0x007fffff;//if len <= 0, which means the 23 bit of frac is enough, we do not need to consider val2

	if(val1 == 0x00800000 )//corner case, special judge
	{
		val1 = 0;
		temp++;
	}
	return flag  | ((temp << 23)) | (val1);
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
  return 2;
}
