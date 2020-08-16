//
// Created by Nick on 8/9/2020.
//

#ifndef PSEUDO_ASSEMBLY_INTERPRETER_REGISTER_H
#define PSEUDO_ASSEMBLY_INTERPRETER_REGISTER_H


class Register {
public:
    static const int size = 32;
    Register() {
        for (bool & i : this->value) {
            i = false;
        }
    }
    bool value[size]{};
    void copy(Register to_copy) {
        for (int i = 0; i < size; ++i) {
            value[i] = to_copy.value[i];
        }
    }
};


#endif //PSEUDO_ASSEMBLY_INTERPRETER_REGISTER_H
