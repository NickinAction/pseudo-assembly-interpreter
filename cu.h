#ifndef CU_H
#define CU_H

#include "Processor.h";


class CU
{
public:
    CU();

    Processor* processor;
    Parser* parser;
    RegisterMemory* registerMemory;

    void setParser(Parser* parser) {
        this->parser = parser;
    }

    void execute(QVector <QString> codeLines);

private:

    QMap <QString, int> branches;
    void collect_markers(QVector <QString> &codeLines);
    bool execute_branch(string& condition);


};

#endif // CU_H
