/* DOCUMENTATION
 *
 * This program determines what version of cpp you have installed.
 *
 * Compile and execute the file normally. If you are not sure how to do this,
 * I have built into this source code some simple command-line scripts that are
 * useable in a terminal shell for GCC and clang.  For example to test GCC try
 * typing exactly (copy/paste works):
 *
 *     grep "^[^ ].*Using GCC" cppversion.cpp | sh -
 *
 * NOTE
 *
 * This is compatible with SystemC (e.g., for use on EDAplayground.com) if you
 * define the macro SYSTEMC at compile-time.
 *
 * LICENSE
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * COPYRIGHT 2020 by David C Black
 *
 */

#include <iostream>
#include <iomanip>
#include <string>

void horizontal_seperator( void ) {
  std::cout << "\n" << std::string( 80, '#' ) << "\n" << std::endl;
}

#ifdef SYSTEMC
#include <systemc>
int sc_main( int argc, char* argv[] )
#else
int main( void )
#endif
{
  int exit_status = 0; // assume success

  horizontal_seperator();

#if defined(__clang__)
  std::cout << "Compiled with Clang/LLVM version " << __clang_major__ << "." << __clang_minor__ << "." << __clang_patchlevel__ << std::endl;

#elif defined(__ICC) || defined(__INTEL_COMPILER)
  std::cout << "Compiled with Intel ICC/ICPC version " << __ICC << std::endl;

#elif defined(__GNUC__) || defined(__GNUG__)
  std::cout << "Compiled with GNU GCC/G++ version " << __GNUC__ << "." << __GNUC_MINOR__ << "." << __GNUC_PATCHLEVEL__ << std::endl;

#elif defined(__HP_cc) || defined(__HP_aCC)
  std::cout << "Compiled with Hewlett-Packard C/aC++ version " << __HP_cc << std::endl;

#elif defined(__IBMC__) || defined(__IBMCPP__)
  std::cout << "Compiled with IBM XL C/C++ version " << __IBMCPP__ << std::endl;

#elif defined(_MSC_VER)
  std::cout << "Compiled with Microsoft Visual Studio version " << _MSC_FULL_VER << std::endl;

#elif defined(__PGI)
  std::cout << "Compiled with Portland Group PGCC/PGCPP version " << __PGIC__ << "." << __PGIC_MINOR__ << "." << __PGIC_PATCHLEVEL__ << std::endl;

#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
  std::cout << "Compiled with Oracle Solaris Studio version " << std::hex << __SUNPRO_CC << std::endl;

#else
  std::cerr << "Unknown compiler!" << std::endl;
  exit_status = 1;

#endif

  horizontal_seperator();

  return exit_status;
}

/* Execution scripts (choose based on C++ invocation that works for you):

c++     -o cppversion cppversion.cpp && ./cppversion ; echo Using c++
g++     -pedantic -Wall -o cppversion cppversion.cpp && ./cppversion ; echo Using GCC
g++     -pedantic -Wall -o cppversion cppversion.cpp && ./cppversion ; echo Using g++
clang++ -pedantic -Wall -o cppversion cppversion.cpp && ./cppversion ; echo Using llvm
clang++ -pedantic -Wall -o cppversion cppversion.cpp && ./cppversion ; echo Using clang
clang++ -pedantic -Wall -o cppversion cppversion.cpp && ./cppversion ; echo Using clang++

Note: add -DSYSTEMC if using with SystemC.

 */
