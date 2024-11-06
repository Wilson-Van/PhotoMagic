// Copyright 2024 Wilson Van
#ifndef FIBLFSR_H
#define FIBLFSR_H

#include <iostream>
#include <string>
namespace PhotoMagic {

class FibLFSR {
 public:
    // Constructor to create LFSR with the given initial seed
    explicit FibLFSR(std::string seed) : _reg(seed) {}
    // Simulate one step and return the new bit as 0 or 1
    int step();
    // Simulate k steps and return a k-bit integer
    int generate(int k);
    std::string getReg() const;

 private:
    // member variable that holds the register
    std::string _reg;
};
std::ostream& operator<<(std::ostream&, const FibLFSR& lfsr);
}  // namespace PhotoMagic
#endif
