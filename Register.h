//
// Created by Nick on 8/9/2020.
//

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_REGISTER_H
#define PSEUDO_ASSEMBLY_INTERPRETER_REGISTER_H


class Register {
    bool value[32];

public:
    void copy(Register to_copy) {
        for (int i = 0; i < 32; ++i) {
            value[i] = to_copy.value[i];
        }
    }
};


#endif //PSEUDO_ASSEMBLY_INTERPRETER_REGISTER_H
