/* The following function will print a non-negative number, n, to
  the base b, where 2<=b<=10,  This routine uses the fact that
  in the ANSCII character set, the digits O to 9 have sequential
  code values.  */

printn(n,b) {
	extrn putchar;
	auto a;

	if(a=n/b) /* assignment, not test for equality */
		printn(a, b); /* recursive */
	putchar(n%b + '0');
}

/* The following program will calculate the constant e-2 to about
   4000 decimal digits, and print it 50 characters to the line in
   groups of 5 characters.  The method is simple output conversion
   of the expansion
     1/2! + 1/3! + ... = .111....
   where the bases of the digits are 2, 3, 4, . . . */

main() {
	extrn putchar, n, v;
	auto i, c, col, a;

	i = col = 0;
	while(i<n)
		v[i++] = 1;
	while(col<2*n) {
		a = n+1 ;
		c = i = 0;
		while (i<n) {
			c =+ v[i] *10;
			v[i++]  = c%a;
			c =/ a--;
		}

		putchar(c+'0');
		if(!(++col%5))
			putchar(col%50?' ': '*n');
	}
	putchar('*n*n');
}

v[2000];
n 2000;



/* The following function is a general formatting, printing, and
   conversion subroutine.  The first argument is a format string.
   Character sequences of the form `%x' are interpreted and cause
   conversion of type 'x' of the next argument, other character
   sequences are printed verbatim.   Thus

    printf("delta is %d*n", delta);

    will convert the variable delta to decimal (%d) and print the
    string with the converted form of delta in place of %d.   The
    conversions %d-decimal, %o-octal, *s-string and %c-character
    are allowed.

    This program calls upon the function `printn'. (see section
    9.1) */
    	
printf(fmt, x1,x2,x3,x4,x5,x6,x7,x8,x9) {
	extrn printn, char, putchar;
	auto adx, x, c, i, j;

	i= 0;	/* fmt index */
	adx = &x1;	/* argument pointer */
loop :
	while((c=char(fmt,i++) ) != '%') {
		if(c == '*e')
			return;
		putchar(c);
	}
	x = *adx++;

	
	switch (c = char(fmt,i++)) {

	case 'd': /* decimal */
	case 'o': /* octal */ 
		if(x < O) {
			x = -x ;
			putchar('-');
		}
		printn(x, c=='o'?8:10); 
		goto loop;

	case 'c' : /* char */
		putchar(x);
		goto loop;

	case 's': /* string */
		while((c=char(x, j++)) != '*e')
			putchar(c);
		goto loop;
	}
	putchar('%') ;
	i--;
	adx--;
	goto loop;

}