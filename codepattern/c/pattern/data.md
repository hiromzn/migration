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

