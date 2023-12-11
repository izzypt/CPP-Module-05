# CPP-Module-05

This module is designed to help you understand Try/Catch and Exceptions in CPP. 

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

# Creating custom exceptions


In C++, you can create custom exceptions by deriving a new class from the standard exception class (std::exception) or one of its derived classes. 

Here's a simple example:

```cpp
#include <iostream>
#include <stdexcept>

// Custom exception class derived from std::exception
class MyException : public std::exception
{
  public:
      // Constructor with a custom error message
      MyException(const char* message) : message_(message) {}
  
      // Override the what() function to provide the error message
      const char* what() const noexcept override {
          /* c_str() is used to obtain a pointer to the internal character array of the std::string.
             This is often useful when you need to pass the content of a C++ string to a function or API that expects a null-terminated C-style string (const char*) */
          return message_.c_str();
      }
  
  private:
      std::string message_;
  };
  
  int main() {
      try {
          // Throw the custom exception with a specific message
          throw MyException("This is a custom exception");
      } catch (const MyException& e) {
          // Catch the custom exception and print the error message
          std::cerr << "Caught custom exception: " << e.what() << std::endl;
      } catch (const std::exception& e) {
          // Catch other exceptions derived from std::exception
          std::cerr << "Caught standard exception: " << e.what() << std::endl;
      }
  
      return 0;
}
```
- In this example, the MyException class is derived from std::exception, and it has a constructor that takes a custom error message as a parameter.
- The what() function is overridden to return the custom error message.
- In the main function, we throw an instance of MyException with a specific message, and then we catch it in the catch block. Note that catching by reference (const MyException& e) is recommended to avoid slicing the object.
