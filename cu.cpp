#include "cu.h"
#include "Processor.h"
#include "consts.h"
#include <QDebug>


using namespace std;

CU::CU()
{
    processor = new Processor();

    registerMemory = new RegisterMemory;
}

void CU::execute(QVector <QString> codeLines) {

    Parser::remove_surrounding_spaces(codeLines);

    collect_markers(codeLines);

    for(int i = 0; i < codeLines.size(); i++) {
        if (codeLines[i] == MARKER_LINE) continue;


        auto operands = parser->split_operands(codeLines[i].toStdString());
        processor->process_command(operands, i);
    }
}

void CU::collect_markers(QVector <QString> &codeLines) {
    for (int i = 0; i < codeLines.size(); i++) {
        if(codeLines[i].back() == ':') {
            branches[codeLines[i].left(codeLines.size())] = i;
            codeLines[i] = MARKER_LINE;

            qDebug() << "Placed marker on line " << i;
        }
    }
}

bool CU::execute_branch(string &condition) {
    if(condition == "") {
        return true;
    }
    else if (condition == "eq") {
        return registerMemory->CPSR.value[Flags::Z] == 1;
    }
    else if (condition == "ne") {
        return registerMemory->CPSR.value[Flags::Z] == 0;
    }
}

