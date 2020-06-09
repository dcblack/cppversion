# cppversion
Determine what version of C++ compiler you are compiling with and what the host OS is.

Everything in this project is effectively self-contained in the single source-file `version.cpp` and two header files (for convenience if incorporating in other programs) including the instructions.

The header files output macros CPPVERSION_STREAM and OSVERSION_STREAM, which are compatible for use in any C++ stream I/O syntax.

Note that it has been updated to make it compatible with SystemC usage.

Read, compile, execute, and enjoy! If you have any comments, observed bugs (please tell me your configuration), or suggestions for improvement, feel free to submit an issue.
