Get Next Line

Reading a line from a file descriptor is far too tedious.

Summary:
This project is about programming a function that returns a line
read from a file descriptor.

Version: 12.2

Contents

I

II

III

IV

V

Goals

Common Instructions

Mandatory part

Bonus part

Submission and peer-evaluation

2

3

5

7

8

1

Chapter I

Goals

This project will not only allow you to add a highly useful function to your collection,
but it will also teach you an important concept in C programming: static variables.

2

Chapter II

Common Instructions

• Your project must be written in C.

• Your project must be written in accordance with the Norm.

If you have bonus
files/functions, they are included in the norm check, and you will receive a 0 if
there is a norm error.

• Your functions should not quit unexpectedly (segmentation fault, bus error, dou-
ble free, etc.) except for undefined behavior. If this occurs, your project will be
considered non-functional and will receive a 0 during the evaluation.

• All heap-allocated memory must be properly freed when necessary. Memory leaks

will not be tolerated.

• If the subject requires it, you must submit a Makefile that compiles your source
files to the required output with the flags -Wall, -Wextra, and -Werror, using cc.
Additionally, your Makefile must not perform unnecessary relinking.

• Your Makefile must at contain at least the rules $(NAME), all, clean, fclean and

re.

• To submit bonuses for your project, you must include a bonus rule in your Makefile,
which will add all the various headers, libraries, or functions that are not allowed in
the main part of the project. Bonuses must be placed in _bonus.{c/h} files, unless
the subject specifies otherwise. The evaluation of mandatory and bonus parts is
conducted separately.

• If your project allows you to use your libft, you must copy its sources and its
associated Makefile into a libft folder. Your project’s Makefile must compile
the library by using its Makefile, then compile the project.

• We encourage you to create test programs for your project, even though this work
does not need to be submitted and will not be graded. It will give you an
opportunity to easily test your work and your peers’ work. You will find these tests
especially useful during your defence. Indeed, during defence, you are free to use
your tests and/or the tests of the peer you are evaluating.

• Submit your work to the assigned Git repository. Only the work in the Git repos-
itory will be graded. If Deepthought is assigned to grade your work, it will occur

3

Get Next Line

Reading a line from a file descriptor is far too tedious.

after your peer-evaluations. If an error happens in any section of your work during
Deepthought’s grading, the evaluation will stop.

4

Chapter III

Mandatory part

Function name
Prototype
Turn in files

Parameters
Return value

External functs.
Description

get_next_line
char *get_next_line(int fd);
get_next_line.c, get_next_line_utils.c,
get_next_line.h
fd: The file descriptor to read from
Read line:
NULL: there is nothing else to read, or an error
occurred
read, malloc, free
Write a function that returns a line read from a
file descriptor

correct behavior

• Repeated calls (e.g., using a loop) to your get_next_line() function should let

you read the text file pointed to by the file descriptor, one line at a time.

• Your function should return the line that was read.

If there is nothing left to read or if an error occurs, it should return NULL.

• Make sure that your function works as expected both when reading a file and when

reading from the standard input.

• Please note that the returned line should include the terminating \n character,
except when the end of the file is reached and the file does not end with a \n
character.

• Your header file get_next_line.h must at least contain the prototype of the

get_next_line() function.

• Add all the helper functions you need in the get_next_line_utils.c file.

A good start would be to know what a static variable is.

5

Get Next Line

Reading a line from a file descriptor is far too tedious.

• Because you will have to read files in get_next_line(), add this option to your

compiler call: -D BUFFER_SIZE=n
It will define the buffer size for read().
The buffer size value will be adjusted by your peer evaluators and the Moulinette
to test your code.

We must be able to compile this project with and without the -D
BUFFER_SIZE flag in addition to the usual flags. You may choose any
default value you prefer.

• You will compile your code as follows (a buffer size of 42 is used as an example):

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c

• get_next_line() exhibits undefined behavior if the file associated with the file
descriptor is modified after the last call, while read() has not yet reached the end
of the file.

• get_next_line() also exhibits undefined behavior when reading a binary file. How-

ever, you can implement a logical way to handle this behavior if you want to.

Does your function still work if the BUFFER_SIZE value is 9999?
it is 1?

10000000? Do you know why?

If

Read as little data as possible each time get_next_line() is called.
If a newline character is encountered, return the current line
immediately.
Don’t read the whole file and then process each line.

Forbidden

• You are not allowed to use your libft in this project.

• lseek() is forbidden.

• Global variables are forbidden.

6

Chapter IV

Bonus part

This project is straightforward and does not support complex bonus features. However,
we trust your creativity. If you have completed the mandatory part, consider attempting
this bonus section.

Here are the bonus part requirements:

• Develop get_next_line() using only one static variable.

• Your get_next_line() can manage multiple file descriptors at the same time.

For example, if you are reading from file descriptors 3, 4, and 5, you should be able
to read from a different file descriptor with each call, without losing track of the
reading state of each file descriptor or returning a line from a different one.
This means you should be able to call get_next_line() to read from fd 3, then fd
4, then fd 5, then again from fd 3, then fd 4, and so forth, without losing track of
the reading state for each file descriptor.

Append the _bonus.[c\h] suffix to the bonus part files.
It means that, in addition to the mandatory part files, you will turn in the 3 following
files:

• get_next_line_bonus.c

• get_next_line_bonus.h

• get_next_line_utils_bonus.c

"Perfect" means the mandatory part has been integrally

The bonus part will only be assessed if the mandatory part is
perfect.
done and works without malfunctioning.
the mandatory requirements, your bonus part will not be evaluated at
all.

If you have not passed ALL

7

Chapter V

Submission and peer-evaluation

Submit your assignment in your Git repository as usual. Only the content inside your
repository will be evaluated during the defense. Make sure to double-check the file names
for accuracy.

When writing your tests, remember that:
1) Both the buffer size and the line size can be of very different
values.
2) A file descriptor does not only point to regular files.
Be thorough and cross-check your work with your peers.
comprehensive set of diverse tests for the defense.

Prepare a

Once passed, do not hesitate to add your get_next_line() to your libft.

/=∂/\/\[](_)§ /\/\@|V †|-|@¯|¯ /-/!570®1<|-\£1_`/ ¢@/\/\ε vv!7}{ ???

8


