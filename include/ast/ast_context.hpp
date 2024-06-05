#ifndef AST_CONTEXT_HPP
#define AST_CONTEXT_HPP

#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iostream>

// An object of class Context is passed between AST nodes during compilation.
// This can be used to pass around information about what's currently being
// compiled (e.g. function scope and variable names).

struct Variable {
    std::string type_;
    int offset_;      //type offset
    int stackoffset_; // offset from stack pointer

    // Default constructor
    Variable() : type_(""), offset_(0), stackoffset_(0) {}
    Variable(std::string type, int offset, int stackoffset) : type_(type), offset_(offset), stackoffset_(stackoffset) {}
};

struct Function {

    // Intialise default values so can construct
    std::map<std::string, Variable> localSymbolTable ={};


    //  int frameSize; // fix to 128
};
class Context
{
        // NEED TO:
        // Make symbol table - this should be a unordered map or map
        // Scopes / stack can be implemented using a vector of symbol tables (maps) which are push_backed and poped to traverse


    private:

        // Use vector to manage the function call stack
        std::vector<Function> functionStack;
        int frameSize = 128;

        // return flag to say if we are assigning or returning
        // either store on stack or load to a0
        bool returnFlag = 0;

        // flag to do nothing if we get an empty func e.g int g();
        bool externalFunc = 0;

        // if in scope
        bool inScope = 0;

        // save id we are storing to
        std::string varID;

        // label num for function
        int labelNum = 0;

        // label num for iterators
        int itLabelNum = 0;

        // label num for if-else
        int ifLabelNum = 0;

        // label num for switches
        int swLabelNum = 0;

        // array id
        std::string arrayID;

        // array size
        int arraySize;

        // while flag, true if we are in while
        bool whileFlag = 0;

        // for flag, true if we are in for
        bool forFlag = 0;

        // switch flag if we want to break
        bool switchFlag = 0;

        // store name of function and number of params (in future it should store the offsets of different params)
        std::map<std::string, int> functionList;

        // Define the RISC-V Register File
        // https://riscv.org/wp-content/uploads/2015/01/riscv-calling.pdf
        // 1 = used / cannot be used
        // 0 = available
        int RegisterFile[32] = {

            1,                              // x0 - zero - hard-wired zero
            1,                              // x1 - ra - return address
            1,                              // x2 - sp - stack pointer
            1,                              // x3 - gp - global pointer
            1,                              // x4 - tp - thread pointer
            0, 0, 0,                        // x5-7 - t0-2 - temporaries
            1,                              // x8 - s0/fp - saved register/frame pointer
            1,                              // x9 - s1 - saved register
            0, 0,                           // x10-11 - a0-1 - function arguments/return values
            0, 0, 0, 0, 0, 0,               // x12-17 - a2-7 - function arguments
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1,   // x18-27 - s2-11 - saved registers
            0, 0, 0, 0,                     // x28-31 - t3-6 - temporaries

        };

        std::string RegisterNames[32] = {
            "zero",
            "ra",
            "sp",
            "gp",
            "tp",
            "t0", "t1", "t2",
            "s0",
            "s1",
            "a0", "a1",
            "a2", "a3", "a4", "a5", "a6", "a7",
            "s2", "s3", "s4", "s5", "s6", "s7", "s8", "s9", "s10", "s11",
            "t3", "t4", "t5", "t6",

        };


    public:

        int sp = 0;

        void makeUsed(int i) {RegisterFile[i] = 1;}
        void makeFree(int i) {RegisterFile[i] = 0;}



        // allocate any register
        std::string allocateRegister(std::ostream& stream) {
            for (int i=0; i<32; i++) {

                if(RegisterFile[i] == 0) {
                    makeUsed(i);
                    std::string regName = RegisterNames[i];
                    stream << "mv " << regName << ", zero" << std::endl;
                    std::cout << "allocating " << regName << std::endl;
                    return regName;

                }
            }
            return "ERROR:RegFileFull";
        }

        // deallocate register
        void deallocateRegister(std::string regName) {
            for(int i=0; i<32; i++) {
                if(RegisterNames[i] == regName) {
                    std::cout << "Made " << regName << " free" << std::endl;
                    makeFree(i);
                }
            }
        }

        // Search for free argument register
        int allocateParameter() {
            for (int i=10; i<17; i++) {

                if (RegisterFile[i] == 0) {
                    makeUsed(i);
                    return i-10;
                }
            }

            return -1;
        }

        // when leaving function scope, deallocate all arg registers
        void deallocateParameters() {
            for (int i=10; i<17; i++) {

                if (RegisterFile[i] == 1) {
                    makeFree(i);
                }
            }
        }

        // Search for free temporary register
        int allocateTemp(std::ostream& stream) {
            for (int i=5; i<8; i++) {

                if (RegisterFile[i] == 0) {
                    makeUsed(i);
                    stream << "mv t" << i-5 << ", zero" << std::endl;
                    return i-5;
                }
            }

            for (int j=28; j<31; j++) {

                if (RegisterFile[j] == 0) {
                    makeUsed(j);
                    stream << "mv t" << j-25 << ", zero" << std::endl;
                    return j-25;
                }
            }

            return -1;
        }

        void deallocateTemp(int reg) {
            if (reg > 2) {
                makeFree(reg+25);
            } else {
                makeFree(reg+5);
            }

        }


        // Get register name
        std::string nameReg(int i) {

            std::string regChar = RegisterNames[i];

            if(regChar == "a") {return regChar + std::to_string(i-10);}            // a0-7 (x10-17)
            if((regChar == "t")&&(i<8)) { return regChar + std::to_string(i-5);}   // t0-2 (x5-7)
            if((regChar == "t")&&(i>27)) { return regChar + std::to_string(i-25);} // t3-6 (x28-31)

        }

        int getFrameSize() {
            return frameSize;
        }


        void pushToStack(const Function& func) {
            functionStack.push_back(func);
        }

        std::vector<Function> getScopeStack() {
            return functionStack;
        }
        void enterFunction(std::ostream &stream) {
            // Allocate stack space for the frame
            stream << "addi sp, sp, -" << getFrameSize() << std::endl;
            // Save the return address and frame pointer if used
            stream << "sw ra, " << (getFrameSize() - 4) << "(sp)" << std::endl;
            stream << "sw fp, " << (getFrameSize() - 8) << "(sp)" << std::endl;
            // Update frame pointer to the new base of the stack frame
            stream << "addi fp, sp, " << getFrameSize() << std::endl;
            // Update your stack pointer management
            sp -= getFrameSize();
            // sp += 1; // use .back - gives last element in vector
        }

        void exitFunction(std::ostream &stream) {
            if (!functionStack.empty()) {
                // functionStack.pop_back();
                // sp -= 1;
                // add label when exiting just to prevent subsequent returns

                const Function& func = functionStack.back(); //  <-- not sure if this is needed
                stream << makeLabel() << ":" << std::endl;
                // Restore saved registers
                stream << "lw ra, " << (getFrameSize() - 4) << "(sp)" << std::endl;
                stream << "lw fp, " << (getFrameSize() - 8) << "(sp)" << std::endl;
                // Deallocate stack space
                stream << "addi sp, sp, " << getFrameSize() << std::endl;
                // Return to caller
                stream << "ret" << std::endl;
                stream << "nop" << std::endl; // because pipelined or something
                // Update your stack pointer management
                sp += getFrameSize();
                functionStack.pop_back();

                deallocateParameters();
                labelNum++;
            }
        }

        std::string makeLabel() {
            return "EXITFUNC" + std::to_string(labelNum);
        }

        std::string getItLabNum() {
            return std::to_string(itLabelNum);
        }

        std::string getIfLabNum() {
            return std::to_string(ifLabelNum);
        }

        std::string getSwLabNum() {
            return std::to_string(swLabelNum);
        }

        void updateItLab() {itLabelNum++;}
        void updateIfLab() {ifLabelNum++;}
        void updateSwLab() {ifLabelNum++;}

        void enterScope() {
            if(functionStack.size() != 0) {

                // Function newScope;
                pushToStack(functionStack.back());
                scopeFlagTrue();
            } else {
                std::cout << "Scope stack is " << functionStack.size() << std::endl;
            }
        }

        void exitScope() {
            functionStack.pop_back();
            scopeFlagFalse();
        }

        std::map<std::string, Variable>& getScopeSymTable() {
            // Function currFunction = functionStack.back();
            // return currFunction.localSymbolTable;
            return functionStack.back().localSymbolTable;
        }

        // get offset of variable depending on type
        int getOffset(std::string type) {
            if (type == "int") {
                return -4;
            }

            // if in doubt assume int
            return -4;
        }

        // gets the next free stack location for storing type
        int getStackOffset(std::map<std::string, Variable> currSymTable, std::string type) {
            int stackOffset = (currSymTable.size()-1)*getOffset(type) - 12;
            return stackOffset;
        }

        void addToSymbolTable(std::map<std::string, Variable>& scopeSymbolTable, std::string identifier, Variable var) {
            scopeSymbolTable.insert({identifier, var});
        }

        void retTrue() { returnFlag = 1;}
        void retFalse() { returnFlag = 0;}
        bool& getRetFlag() { return returnFlag;}

        void exFuncTrue() { externalFunc = 1;}
        void exFuncFalse() { externalFunc = 0;}
        bool& getExFuncFlag() { return externalFunc;}

        void scopeFlagTrue() { inScope = 1;}
        void scopeFlagFalse() { inScope = 0;}
        bool& getscopeFlag() { return inScope;}

        void updateVarID(std::string x) {varID = x;}
        std::string& getVarID() { return varID;}

        void updateArrayID(std::string x) {arrayID = x;}
        std::string& getArrayID() { return arrayID;}

        void updateArraySize(int x) {arraySize = x;}
        int& getArraySize() { return arraySize;}

        void whileTrue() { whileFlag = 1;}
        void whileFalse() { whileFlag = 0;}
        bool& getWhileFlag() { return whileFlag;}

        void forTrue() { forFlag = 1;}
        void forFalse() { forFlag = 0;}
        bool& getForFlag() { return forFlag;}

        void switchTrue() { switchFlag = 1;}
        void switchFalse() { switchFlag = 0;}
        bool& getSwitchFlag() { return switchFlag;}
};

#endif
