#include <iostream>
using namespace std;

int DM[10000];

void fun1(int& reg0, int& reg1, int& reg2){
    reg2 = 40;
    if(reg0 < reg2){
        reg1 = reg0 - reg2;
    } else{
        reg1 = 0;
    }
}

void fun2(int& reg0, int& reg1, int& reg2){
    int reg3 = reg0 * reg1;
    int reg4 = (reg2 * reg1);
    reg3 = reg3 + reg4;
}

int main(){
    int reg0, reg1, reg2, reg3;
    int reg4 = 5000;
    int reg5 = 5004; 
    int reg6 = 5008;
    
    DM[reg4] = 1;
    DM[reg5] = 2;
    DM[reg6] = 4;

    
    reg0 = DM[reg4];
    reg1 = DM[reg5];
    reg2 = DM[reg6];
    
    cout << "Register 0: " << reg0 << endl;
    cout << "Register 1: " << reg1 << endl;
    cout << "Register 2: " << reg2 << endl;
    cout << "_________________________________________________\n";
    
    reg3 = reg0 + reg1;
    cout << "Completing: add $t3,$t0,$t1 \n";
    cout << "Register 3: " << reg3 << endl << endl;
    
    reg3 = reg3 + reg2;
    cout << "Completing: add $t3,$t3,$t2 \n";
    cout << "Register 3: " << reg3 << endl << endl;
    
    DM[5008] = reg3;
    cout << "Completing: sw $t3, 0($t4) \n";
    cout << DM[5008] << endl << endl;
    
    
    reg6 = DM[5000];
    cout << "Completing: addi $t6,$zero,5000 \n";
    cout << "Register 6: " << reg6 << endl << endl;
    
    reg0 = DM[5000];
    cout << "Completing: lw $t0,0($t6) \n";
    cout << "Register 0: " << reg0 << endl;
    cout << "_________________________________________________\n";
    
    fun1(reg0, reg1, reg2);
    cout << "After completing fun1: " << endl;
    cout << "Register 0: " << reg0 << endl;
    cout << "Register 1: " << reg1 << endl;
    cout << "Register 2: " << reg2 << endl << endl;
    
    cout << "After completing: add $t2,$zero, $t1: " << endl;
    reg2 = reg1;
    cout << "Register 2: " << reg2 << endl << endl;
    cout << "After completing: addi $t1,$zero,10: " << endl;
    reg1 = 10;
    cout << "Register 1: " << reg1 << endl;
    cout << "_________________________________________________\n";
    
    fun2(reg0, reg1, reg2);
    cout << "After completing fun2: " << endl;
    cout << "Register 3: " << reg3 << endl;
    cout << "Register 4: " << reg4 << endl << endl;
    
    
    cout << "Completing: addi $t6,$zero,5040 \n";
    reg6 = 5040;
    cout << "Register 6: " << reg6 << endl << endl;
    cout << "Completing: sw $t3,0($t6): " << endl;
    DM[5040] = reg3; 
    cout << "DM[5040]: " << DM[5040] << endl;
    cout << "_________________________________________________\n";
    
    reg1 = 2;
    cout << "Completing: addi $t1,$zero,2" << endl;
    cout << "Register 1: " << reg1 << endl << endl;
    cout << "Done";
    cout << "_________________________________________________\n";
    
    cout << "Register Values: " << endl;
    cout << "Register 0: " << reg0 << endl;
    cout << "Register 1: " << reg1 << endl;
    cout << "Register 2: " << reg2 << endl;
    cout << "Register 3: " << reg3 << endl;
    cout << "Register 4: " << reg4 << endl;
    cout << "Register 5: " << reg5 << endl;
    cout << "Register 6: " << reg6 << endl;
    
    return 0;
    
}