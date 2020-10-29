
#include <stdio.h>
#include <string.h>
#include "Person.h"


Person::Person(int idNumber, const char* name)
{
    this->idNumber = idNumber;
    int nameLen = strlen(name) + 1;
    this->name = new char[nameLen];
    strcpy(this->name, name);
}

Person::~Person()
{
    delete[] this->name;
}

int Person::getIdNumber()
{
    return idNumber;
}

const char* Person::getName()
{
    return name;
}
