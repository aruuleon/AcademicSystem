#include <iostream>
#include <cstring>
#include "System.h"
#include "SuperAdministrator.h"
#include "Administrator.h"
#include "Teacher.h"
#include "Student.h"
#include "UserLogin.h"
#include "GenericFile.h"

int main() {
    System system("UNIVERSIDAD TECNOLOGICA NACIONAL", "Argentina", "Buenos Aires");
    system.runProgram();
    return 0;
}