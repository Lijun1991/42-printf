# 42-printf
 Rewrite c printf functions
 
 man 3 stdarg
 stdarg -- variable argument lists
 
 USE STDARG
 
 To use a function with a variable number of arguments, you must first of all include the library that will help your deal with the processing of the varying arguments, stdarg.h. You must therefore include this library in your program with a #include statement, along with your library references, like the following:
 
   #include <stdarg.h>
 
 To declare a function that will use a variable number of arguments, you must make sure you have at least one defined argument in the argument list; that is, a specific argument with a name and type associated with it. You can have as many real arguments as you would like; you just have to have at least one.
 
 Following the last defined argument, you should place the C-symbol that indicates your use of a variable number of arguments, the ellipsis, or ... (three periods in a row). An example would look like this:
 
   type functionName (defined_args, ...)
 
 You control the access of the variable arguments with the following definitions/functions/macros provided in stdarg. All of these references must only appear inside the body of a function that will have a variable number of arguments (as denoted by the ellipsis):
 
 va_list varname;
 This is the name of a structure that will maintain the information about the variable argument list, and it is therefore used in each of the following functions/macros. NOTE that the va stands for variable arguments. And example might be:
   va_list args;
 
 va_start (varname, last_defined_arg)
 This function initializes the processing of the variable argument list. The first parameter corresponds to the variable name you used when you defined the va_list structure. The second parameter corresponds to the variable name of the last defined argument in the argument list in the function's definition.
 This function must be called before you try to reference any of the variable arguments. If it is called more than one time inside a function, the processing of the list of variable arguments will start over again at the first variable argument. An example would be:
 
   void foo (int num, ...)
   {
     va_list args;
 
     va_start (args, num);
 
 va_arg (varname, typename)
 This function is the one you use to access the value of each variable argument. The first parameter corresponds to the variable name you used when you defined the va_list structure. The second parameter corresponds to the type of the value that is passed.
 This is why you have not only have to be able to predeterine the number of arguments that will be passed, but also the type of each individual argument.
 
 The va_arg() function will return to you to the corresponding value of the next variable argument in turn. This simply means that the first time va_arg() is called, it will return the value of the first variable argument passed in this invocation of the function, the second time it is called it will return the value of the second variable argument passed, and so forth. Here are some examples:
 
   int num1 = va_arg(args,int);
   float num2 = va_arg(args,float);
 
 va_end (varname)
 This function you call at the very end of your function, right before you return. It's job is to place the system stack in order, and prepare to return to the calling routine. It only has to be called once and it doesn't have to be called each time you'd like to reuse the argument list. Here is an example:
   va_end (args);
 
 You simply combine this declaration and three function/macro calls to properly process the variable argument list. The following sections show several example programs that utilize variable parameter lists using the various methods previously described.
 
 
 
  #include <stdio.h>
 
      int
      printf(const char * restrict format, ...);
      
   the printf() family of functions produces output according to a format as described below. 
   
   Extended locale versions of these functions are ducumented in printf_l(3). see xlocale(3)
   
   These functions write the output under the control of a format string that specifies how subsequent arguments
   (or arguments accessed via the variable-length argument facilities of stdarg(3)) are converted for output.
   
   The format string is composed of zero or more directives: ordinary characters (not %), which are copied unchanged to 
   the output stream; and conversion specifications, each of which results in fetching zero or more subsequent arguments.
   Each conversion specification is introduced by the % charactor. The arguments must correspond properly 
   (after type promotion) with the cnoversion specifier. After the %, the following appear in sequence.
   
   
   
   c the int argument is converted to an unsigned char, and the resulting character is written.
     If the l(ell) modifier is used, the wint_t argument shall be converted to a wchar_t, and the (potentially multi-byte)
     sequence representing the single wide character is written, including any shift sequences. If a shift sequence is used,
     the shift state is also restored to the original state after the character.
     
     
     
     A ducumentation better than man 3 printf 
     https://linux.die.net/man/3/printf
    
      What is struct bits filed?
      https://www.tutorialspoint.com/cprogramming/c_bit_fields.htm
  
 
  
    The difference between wint_t and wchar_t 
      wchar_t	Type used for a code unit in wide strings, usually an unsigned 16 bit or 32 bit value. No specific interpretation is specified for these code units; the C standard only requires that wchar_t be wide enough to hold the widest character set among the supported system locales.[5] Theoretically, wchar_t can be the same size as char, and thus not capable of holding UTF-32 or UTF-16 code points.[6]
       wint_t	Integer type that can hold any value of a wchar_t as well as the value of the macro WEOF. This type is unchanged by integral promotions. Usually a 32 bit signed value.
    
    All of the Unicode values map to 0x0000 to 0x10FFFF
    best recource to how unicode encoded:   https://en.wikipedia.org/wiki/UTF-8
    
    wcrtomb:	Converts a wide character to its multibyte representation, given state


  Endianness?
  The difference between float and double?
  what can you use to hold ULLONG_MAX ????????
  

  Colors in terminal:
  http://jafrog.com/2013/11/23/colors-in-terminal.html
  
