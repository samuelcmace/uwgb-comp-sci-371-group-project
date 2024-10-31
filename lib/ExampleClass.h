#ifndef EXAMPLE_CLASS_H
#define EXAMPLE_CLASS_H

class ExampleClass {
private:
    int exampleVar;
public:
    ExampleClass(int value);
    int getExampleVar() const;
    void setExampleVar(int value);
};

#endif
