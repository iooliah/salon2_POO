#ifndef PERSOANA_H
#define PERSOANA_H
#include <string>
#include <iostream>

class Persoana {
protected:
    std::string nume;
    std::string prenume;
    std::string telefon;

public:
    Persoana() = default;
    Persoana(const std::string& nume, const std::string& prenume, const std::string& telefon);
    virtual ~Persoana() = default;

    const std::string& getNume() const;
    const std::string& getPrenume() const;
    const std::string& getTelefon() const;
    std::string getNumeComplet() const;

    //interfata non-virtuala
    void afiseaza(std::ostream& os) const;

    virtual std::string getRol() const = 0;

    //clone
    virtual std::unique_ptr<Persoana> clone() const = 0;

    //interfata non-virtuala pentru afisare
    friend std::ostream& operator<<(std::ostream& os, const Persoana& p);

    virtual std::string getRol() const = 0;

protected:
    virtual void afiseaza(std::ostream& os) const;
};

//operator <<
//std::ostream& operator<<(std::ostream& os, const Persoana& p);


#endif // PERSOANA_H

//+ personal curatenie POATE
