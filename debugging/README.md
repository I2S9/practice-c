# Introduction to Debugging

For big projects with much more lines of code, debugging is a notion very crucial for developpers. 
It can be defined as a process of searching solutions to fix the code.

## Problems of coding
I. Compilation Errors

When we forgot some semicolons, commas and so one and so forth, it's named a compilation error. 
The compiler will going to pinpoint exactly where the line that things went wrong and why.
It's very easy to fix the problem in this case.

Nevertheless, for these types of errors, the compiler won't tell us the origin of the error : 

II. Logical Errors

This type of errors is when our program is running but it doesn't display the things that we want.
It seems to be working ok but we haven't the result that we expected.
To fix it we need to inspect all of our code and the debugging process won't really help us.

III. Runtime Errors

During the execution of the program, we do something and it causes runtime errors. We will probably get some notifications 
that a program has crashed but that's not usually a good thing to like to try looking out for a solution once the program 
has crashed and you want to reproduce the problem and see what happened.

There are techniques to solve and fix these errors.
