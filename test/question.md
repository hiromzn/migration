
which is better code ???


main.c:

int main()
{
	char dumm1[10];

	char mychar_a[];
	char mychar_b[10];
	char *mychar_c;

	struct mystr_a {
		enum enum_a {
			int	enum_int_data;
			char *enum_char_p;
		};
		int str_int_data;
		char str_char_1;
		char *str_char_2;
	}

	char dumm2[10];

	mychar_c = malloc(10);


	/***************************/
	/* select A or B or C */
	/***************************/

	/*
		A : portable code (same behavior on 32/64 bit and different endian system)
		B : no error, but different behavior between 32bit executable and 64bit executable.
		C : no error, but different behavior between different endian system.
	*/

	/* Question 1 - XX */
		printf( "%x\n", mychar_a );			/* Q_01 : A/B/C */
		printf( "%x\n", *mychar_a );
		printf( "%x\n", mychar_a[1] );
		
		printf( "%x\n", mychar_b );
		printf( "%x\n", *mychar_b );
		printf( "%x\n", mychar_b[1] );
		printf( "%x\n", mychar_b[10] );

		printf( "%x\n", mychar_c );
		printf( "%x\n", *mychar_c );
		printf( "%x\n", mychar_c[1] );
		printf( "%x\n", mychar_c[10] );


		int				s_int = -1;
		unsigned int	u_int = 1;

		long			s_long = -1;
		unsigned long	u_long = 1;

		s_long = s_int;
		u_long = s_int;

		printf( "%x\n", s_long );
		printf( "%x\n", u_long );

	/***************************/
	/* write answer and your thinking .... */
	/***************************/

	/*
		Is there problem the following code ?
		If yes, what is problem ?
	*/




	return 0;
}

