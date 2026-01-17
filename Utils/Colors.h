#ifndef COLORS_H
#define COLORS_H

#include <iostream>

// Text Color functions
inline void Red()     { std::cout << "\033[1;31m"; }
inline void Yellow()  { std::cout << "\033[1;33m"; }
inline void Blue()    { std::cout << "\033[0;34m"; }
inline void Green()   { std::cout << "\033[0;32m"; }
inline void Purple()  { std::cout << "\033[0;35m"; }
inline void White()   { std::cout << "\033[0;37m"; }
inline void Cyan()    { std::cout << "\033[0;36m"; }
inline void ResetTextColor() { std::cout << "\033[0m"; }

#endif
