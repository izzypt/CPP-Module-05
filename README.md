# CPP-Module-05
Repetition and Exceptions

# C++ Exceptions

C++ includes a new, improved mechanism for capturing and handling errors called **exceptions**.

An **exception** is “a case in which a rule or principle does not apply.” 

Exception is also defined as an objection to something. 

Either definition works: An exception is an unexpected (and presumably objectionable) condition that occurs during the execution of the program.

<hr>

When executing C++ code, different errors can occur: 

- coding errors made by the programmer, 
- errors due to wrong input,
- or other unforeseeable things.

When an error occurs, C++ will normally stop and generate an error message. 

The technical term for this is: C++ will throw an exception (throw an error).

# Exception handling in C++ 

Consists of three keywords: ```try```, ```throw``` and ```catch```:

The ```try``` statement allows you to define a block of code to be tested for errors while it is being executed.

The ```throw``` keyword throws an exception when a problem is detected, which lets us create a custom error.

The ```catch``` statement allows you to define a block of code to be executed, if an error occurs in the try block.

```cpp
try {
  // Block of code to try
  throw exception; // Throw an exception when a problem arise
}
catch () {
  // Block of code to handle errors
} 
```
An exception is thrown by using the throw keyword from inside the try block. Exception handlers are declared with the keyword catch, which must be placed immediately after the try block.
