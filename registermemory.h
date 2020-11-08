#ifndef REGISTERMEMORY_H
#define REGISTERMEMORY_H

#include "Register.h"


class RegisterMemory
{
public:
    RegisterMemory();

    friend class ALU;
    friend class Processor;
    friend class CU;

private:
    Register CPSR;
    array <Register, 16> registers;
    Register extra_registers[3];



};

#endif // REGISTERMEMORY_H
