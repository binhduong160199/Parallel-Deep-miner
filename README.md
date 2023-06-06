# Parallel-Deep-miner

This is an exercise in the course OOP (C++) in FH Technikum Wien 

Object Oriented Programming

Exercise examples
parallel deep miner

Use the fourth example as a base and extend it with parallel execution
of the robot movements. Now only the computer should be able to compete against itself.
The following points must be observed:
• Use threads and mutexes to ensure error-free concurrency.
• Use STL classes for data structures.
• Use interfaces as parent classes and polymorphism for your objects.
• Use sensible classes. In doing so, pay attention to the correct use of access modifiers, getters/setters, the various constructors and destructors, and the sensible structuring of functions and data. Form yours
Classes in a corresponding diagram.
• Check all parameter passing to functions and user input for ¨
Errors and prevent your program from crashing in the event of invalid input
works correctly, entries should be repeated until they are correct
and only then can the flow of the game continue.
• Test your code extensively and take boundary conditions into account.
step 1
See example 4, but there should be at least 5 robots in the game world at the same time, this one
should be implemented as threads and use mutexes to set race conditions
impede. At the beginning of the execution, enter the sum of the degradable values of the
game world and at the end the sum of the robot points. These sums must be equal
otherwise values were degraded incorrectly.
1
Level 2
Your program should now also measure the time that each individual thread and your program
total for execution. Research how to measure time in C++
is possible (see chrono library).
level 3
Enhance the robots with the ability to hit each other while collecting too
to fight. If a robot is on an adjacent or the same square,
perform an attack on the other robot before mining stats.
This should, of course, run error-free in spite of the parallelism. How you design the rules is up to you, but a robot shouldn't get out of the game with a single attack
game can be taken, or if so, then only with a very low probability.

After that, i wrote a unittest and exception and operation overloading too for the exercise 
