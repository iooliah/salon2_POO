#ifndef PERSOANA_H
#define PERSOANA_H
#include <string>
#include <iostream>
#include <memory>

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
    virtual std::shared_ptr<Persoana> clone() const = 0;

    //interfata non-virtuala pentru afisare
    friend std::ostream& operator<<(std::ostream& os, const Persoana& p);

protected:
    virtual void afiseazaVirtual(std::ostream& os) const;
};

#endif // PERSOANA_H
