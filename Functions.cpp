#include "Functions.h"

void processValidationForTheFirstCase(std::string fieldMessage, int &field, int validationForMinimum, int validationForMaximum) {
    std::cout << fieldMessage << ": ";
    std::cin >> field;
    while(field < validationForMinimum || field > validationForMaximum) {
        std::cout << "LA OPCION NO ES VALIDA. INGRESAR NUEVAMENTE: ";
        std::cin >> field;
    }
};
void processValidationForTheSecondCase(std::string fieldMessage, int &field, int optionReceived, int firstOptionReceived, int secondOptionReceived, int thirdOptionReceived, int validationForMinimum, int validationForFirstMaximum, int validationForSecondMaximum) {
    std::cout << fieldMessage << ": ";
    std::cin >> field;
    while(((optionReceived == firstOptionReceived || optionReceived == thirdOptionReceived) && field < validationForMinimum || field > validationForFirstMaximum) || (optionReceived == secondOptionReceived && field < validationForMinimum || field > validationForSecondMaximum)) {
        std::cout << "LA OPCION NO ES VALIDA. INGRESAR NUEVAMENTE: ";
        std::cin >> field;
    }
};
void processValidationForTheThirdCase(std::string fieldMessage, int &field, int optionReceived, int firstOptionReceived, int secondOptionReceived, int validationForMinimum, int validationForFirstMaximum, int validationForSecondMaximum) {
    std::cout << fieldMessage << ": ";
    std::cin >> field;
    while((optionReceived == firstOptionReceived && field < validationForMinimum || field > validationForFirstMaximum) || (optionReceived == secondOptionReceived && field < validationForMinimum || field > validationForSecondMaximum)) {
        std::cout << "LA OPCION NO ES VALIDA. INGRESAR NUEVAMENTE: ";
        std::cin >> field;
    }
}