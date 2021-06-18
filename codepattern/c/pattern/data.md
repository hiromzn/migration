# pattern
## description
- bad usage of sizeof( CONSTANT value ) : for char memset()
## check
### compiler
- cadv
### id
- remark #4356-D
### message
    - operand of sizeof is a constant rvalue, this might not be what you intended
### code
```
char  foo[MAX + 1];
memset( foo, 0x00, sizeof( MAX ) );
```
### fix
```
memset( foo, 0x00, sizeof( foo ) );
```

# pattern
## description
- bad usage of sizeof( CONSTANT value ) : for varchar memset()
## check
### compiler
- cadv
### id
- remark #4356-D
### message
    - operand of sizeof is a constant rvalue, this might not be what you intended
### code
```
varchar foo[MAX + 1];
memset( &foo, 0x00, sizeof( MAX ) );
```
### fix
```
memset( foo.arr, 0x00, foo.len );
```
### comment
- varchar is defined in Pro*C
- reference URL : 
  - https://docs.oracle.com/cd/E57425_01/121/LNPCC/GUID-33AC6FC8-EA9D-4C7F-ADAC-D01A0DF4E281.htm
- memo
```
VARCHARはC言語の構造体
    VARCHAR   username[20];
    
プリコンパイラは上の宣言を、配列および長さを持つ次の構造体に展開する。
    struct 
    { 
        unsigned short  len; 
        unsigned char   arr[20]; 
    } username;

sample code:
    printf("Username is %.*s\n", username.len, username.arr);
```

# pattern
## description
- bad usage of sizeof( CONSTANT value ) : for compare memory memcmp()
## check
### compiler
- cadv
### id
- remark #4356-D
### message
    - operand of sizeof is a constant rvalue, this might not be what you intended
### code
```
char  foo[MAX + 1];
if ( memcmp( foo, "", sizeof( MAX) ) == 0 ) // NULL check
```
### fix
```
// check first char is ZERO
if ( foo[0] == '\0' )
// or
if ( ! foo[0] )
```

