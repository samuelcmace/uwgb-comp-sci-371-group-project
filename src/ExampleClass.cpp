#include "ExampleClass.h"

ExampleClass::ExampleClass(int value) {
    this->exampleVar = value;
}

void ExampleClass::setExampleVar(int value) {
    this->exampleVar = value;
}

int ExampleClass::getExampleVar() const {
    return this->exampleVar;
}
