// Copyright 2024 Wilson Van

#include "FibLFSR.hpp"


int PhotoMagic::FibLFSR::step() {
    // Right most bit variable
    int rmb = 0;
    bool first_xor_gate, second_xor_gate, third_xor_gate;
    first_xor_gate = _reg[0] != _reg[2];
    if (first_xor_gate) {
        second_xor_gate = _reg[3] == '0';
    } else {
        second_xor_gate = _reg[3] == '1';
    }
    if (second_xor_gate) {
        third_xor_gate = _reg[5] == '0';
    } else {
        third_xor_gate = _reg[5] == '1';
    }
    if (third_xor_gate) {
        rmb = 1;
    }
    for (int i = 0; i < static_cast<int>(_reg.size() - 1); i++)
        _reg[i] = _reg[i+1];
    _reg[_reg.size() - 1] = (rmb + 48);
    return rmb;
}

int PhotoMagic::FibLFSR::generate(int k) {
    int result = 0;
    for (int i = 0; i < k; i++) {
        result *= 2;
        result += this->step();
    }
    return result;
}

std::string PhotoMagic::FibLFSR::getReg() const {
    return this->_reg;
}

std::ostream& PhotoMagic::operator<< (std::ostream& out,
                                      const PhotoMagic::FibLFSR& fib) {
    out << fib.getReg();
    return out;
}
