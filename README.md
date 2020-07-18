# C-20-New_Features
Showcases some interesting functionality of a feature introduced in C++20 called "Concepts". **Note:** at the time of coding, this had to be compiled with GCC 9 with the flag `-fconcepts`.

In its most simple form, Concepts are syntactic sugar for employing type traits. They offer an alternative to SFINAE. Both SFINAE and Concepts result in drastically reduced compiler errors vs unconstrained template errors.

C++20 introduces the keyword `requires` as a way of imposing constraints on template parameters.
