#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>

#define PR_TYPE_SIZE( type )	printf( "sizeof(%s) = %lu\n", #type, sizeof( type ) )

#define CHECK_PRINTF( prtype, dtype, data ) \
	{ \
		char pr_str[500]; \
		sprintf( pr_str, "%" prtype, (dtype)data ); \
		if ( strcmp( pr_str, EXP_ ## data ) ) { \
			printf( "mismatch" ); \
			printf( ": fmt:%s, (%s)data:%s", prtype, #dtype, #data ); \
			printf( " -> %s (expect:%s)\n", pr_str, EXP_ ## data ); \
		} else { \
			printf( "OK" ); \
			printf( ": fmt:%s, (%s)data:%s", prtype, #dtype, #data ); \
			printf( "\n" ); \
		} \
	}

#define PR_STRVAR(a)	printf( #a ": %s\n", a )

void check_fmt_d()
{
	int			MINUS=-1;
	float		F_MINUS=(float)-1;
	double		D_MINUS=(double)-1;

	char		EXP_INT_MAX[100];
	char		EXP_LONG_MAX[100];
	char		EXP_LLONG_MAX[100];
	char		EXP_FLT_MAX[FLT_MAX_10_EXP + 20];
	char		EXP_DBL_MAX[DBL_MAX_10_EXP + 20];

	char		EXP_MINUS[100];
	char		EXP_F_MINUS[100];
	char		EXP_D_MINUS[100];

	sprintf( EXP_INT_MAX, "%d", INT_MAX );
	sprintf( EXP_LONG_MAX, "%ld", LONG_MAX );
	sprintf( EXP_LLONG_MAX, "%lld", LLONG_MAX );
	sprintf( EXP_FLT_MAX, "%f", FLT_MAX );
	sprintf( EXP_DBL_MAX, "%lf", DBL_MAX );
	sprintf( EXP_MINUS, "%d", MINUS );
	sprintf( EXP_F_MINUS, "%f", F_MINUS );
	sprintf( EXP_D_MINUS, "%lf", D_MINUS );

	PR_TYPE_SIZE ( int );
	PR_STRVAR( EXP_INT_MAX );

	PR_TYPE_SIZE ( long );
	PR_STRVAR( EXP_LONG_MAX );

	PR_TYPE_SIZE ( long long );
	PR_STRVAR( EXP_LLONG_MAX );

	PR_TYPE_SIZE ( float );
	PR_STRVAR( EXP_FLT_MAX );

	PR_TYPE_SIZE ( double );
	PR_STRVAR( EXP_DBL_MAX );

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat"
	CHECK_PRINTF( "d", int, INT_MAX );
	CHECK_PRINTF( "d", long, LONG_MAX );
	CHECK_PRINTF( "d", long long, LLONG_MAX );

	CHECK_PRINTF( "d", int, MINUS );
	CHECK_PRINTF( "d", long, MINUS );
	CHECK_PRINTF( "d", long long, MINUS );

	CHECK_PRINTF( "ld", int, INT_MAX );
	CHECK_PRINTF( "ld", long, LONG_MAX );
	CHECK_PRINTF( "ld", long long, LLONG_MAX );
	CHECK_PRINTF( "ld", int, MINUS );
	CHECK_PRINTF( "ld", long, MINUS );
	CHECK_PRINTF( "ld", long long, MINUS );


	CHECK_PRINTF( "lld", int, INT_MAX );
	CHECK_PRINTF( "lld", long, LONG_MAX );
	CHECK_PRINTF( "lld", long long, LLONG_MAX );
	CHECK_PRINTF( "lld", int, MINUS );
	CHECK_PRINTF( "lld", long, MINUS );
	CHECK_PRINTF( "lld", long long, MINUS );

	CHECK_PRINTF( "f", float, FLT_MAX );
	CHECK_PRINTF( "lf", double, DBL_MAX );
	CHECK_PRINTF( "f", float, F_MINUS );
	CHECK_PRINTF( "lf", double, D_MINUS );
#pragma GCC diagnostic pop
}

int main()
{
	check_fmt_d();
}
