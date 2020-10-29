/*
This class defines the Person class
*/

#ifndef Person_h
#define Person_h

class Person
{
public:
    Person(int idNumber, const char* name); //c'tor
    Person(Person& other) = delete; //disable copy c'tor
    ~Person(); //d'tor
    int getIdNumber(); //return the person's ID number
    const char* getName(); //return the person's name
    
private:
    int idNumber;
    char* name;
};

#endif /* Person_h */
