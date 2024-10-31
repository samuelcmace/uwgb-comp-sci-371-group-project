#include <iostream>

#include "ExampleClass.h"

int main(int argc, char* argv[]) {

    ExampleClass exampleClass(5);
    std::cout << exampleClass.getExampleVar() << std::endl;

    return 0;

}