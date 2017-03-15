# 42-printf
Rewrite c printf functions

man 3 stdarg
stdarg -- variable argument lists

A function may be called with a varying number of arguments of varying types. 
The include file <stdarg.h> declares a type (va_list) and defines three macros for stepping through a list of arguments 
whose number and types are not known to the called function.

The called function must declare an object of type va_list which is used by the macros va_start(), va_arg(), va_copy, and va_end().

The va_star() macro must be called first, and it initializes ap, which can be passed to va_arg() for each argument to be processed.
Calling va_end() signals that there are no further arguments, and causes ap to be invalidated. 
Note that each call to va_start() must be matched by a call to va_end(), form within the same function.

The parameter last is the name of the last parameter before the variable argument list

Because the address of this parameter is used in the va_start() macro, it should not be declared as a register variable,
or as a function or as array type.

The va_arg() macro expands to an expression that has the type and value of the next argument in the call.
The parameter ap is the va_list ap initialized by va_start().
Each all to va_arg() modifies ap so that the next call returns the next argument.
The parameter type is a type name specified so that the type of a pointer to an object that has the specified type can be 
obtained simply by adding a * to type.

If there is no next argument, or if type is not compatible with the type of the actual next argument (as promoted according to
the default arguments), random error will occur.

The first use of the va_arg() macro after that of the va_start() macro returns the argument after last. 
Successive invacations return the values of the remainning arguments.

The va_copy() macro copies the state of the variable argument list, src, previously initialized by va_start(),
to the variable argument list, dest, which must not have been previousely initialized by va_start(), without an intervening
call to va_end(). 

After a variable argument list is invalidated by va_end(), it can be reinitialized with va_start() or made a copy of another 
variable argument list with va_copy().
