#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// Structure to hold a parsed instruction
struct Instruction {
    string op;
    string arg1;
    string arg2;
};

int main() {
    vector<Instruction> program;
    string line;

    // Read instructions until EOF
    while (getline(cin, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Instruction instr;
        ss >> instr.op >> instr.arg1 >> instr.arg2;
        program.push_back(instr);
    }

    // Register map: A=0, B=1, C=2, D=3, E=4, F=5, P=6
    long long reg[7] = {0}; 
    map<string, int> regMap = {{"A", 0}, {"B", 1}, {"C", 2}, {"D", 3}, {"E", 4}, {"F", 5}, {"P", 6}};

    while (reg[6] >= 0 && reg[6] < program.size()) {
        Instruction current = program[reg[6]];
        string op = current.op;
        bool jumped = false;

        if (op == "LOD") {
            reg[regMap[current.arg1]] = stoll(current.arg2);
        } 
        else if (op == "INC") {
            reg[regMap[current.arg1]]++;
        } 
        else if (op == "ADD") {
            reg[regMap[current.arg1]] += reg[regMap[current.arg2]];
        } 
        else if (op == "MUL") {
            reg[regMap[current.arg1]] *= reg[regMap[current.arg2]];
        } 
        else if (op == "CMP") {
            long long x = reg[regMap[current.arg1]];
            long long y = reg[regMap[current.arg2]];
            if (x == y) reg[2] = 0;
            else if (x > y) reg[2] = 1;
            else reg[2] = -1;
        } 
        else if (op == "JMP") {
            reg[6] = stoi(current.arg1);
            jumped = true;
        } 
        else if (op == "JCZ") {
            if (reg[2] == 0) {
                reg[6] = stoi(current.arg1);
                jumped = true;
            }
        } 
        else if (op == "JCP") {
            if (reg[2] > 0) {
                reg[6] = stoi(current.arg1);
                jumped = true;
            }
        } 
        else if (op == "JCN") {
            if (reg[2] < 0) {
                reg[6] = stoi(current.arg1);
                jumped = true;
            }
        } 
        else if (op == "HLT") {
            break;
        }

        // Increment Program Counter if no jump occurred
        if (!jumped) {
            reg[6]++;
        }
    }

    // Output all 7 registers
    for (int i = 0; i < 7; ++i) {
        cout << reg[i] << (i == 6 ? "" : " ");
    }
    cout << endl;

    return 0;
}