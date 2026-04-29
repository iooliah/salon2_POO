#ifndef EXCEPTII_H
#define EXCEPTII_H
#include <stdexcept>
#include <string>

class SalonExceptii : public std::runtime_error{
public:
    explicit SalonExceptii(const std::string& mesaj);
};

class ClientInexistentExceptie : public SalonExceptii{
public:
    ClientInexistentExceptie();
};

class AngajatInexistentExceptie : public SalonExceptii{
public:
    AngajatInexistentExceptie();
};

class ProgramareInvalidaExceptie : public SalonExceptii{
public:
    explicit ProgramareInvalidaExceptie(const std::string& mesaj);
};



#endif
