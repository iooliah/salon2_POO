#ifndef PROGRAMARE_H
#define PROGRAMARE_H
#include "Serviciu.h"
#include "Angajat.h"
#include "Client.h"
#include "Coafor.h"
#include <memory>
#include <string>
#include <vector>

class Programare{
private:
    Client client;
    Angajat angajat;
    std::shared_ptr<Serviciu> serviciu;  //pointer la baza => apel virtual
    std::string data;
    std::string ora;
    plata tipPlata;

    static bool esteAcelasiClient(const Client& c1, const Client& c2);

public:
    Programare() = default;
    Programare(const Client& client, const Angajat& angajat, std::shared_ptr<Serviciu> serviciu, const std::string& data, const std::string& ora, plata tipPlata);

    //copy and swap
    Programare(const Programare& other);
    Programare& operator=(Programare other);
    friend void swap(Programare& a, Programare& b) noexcept;
    ~Programare() = default;

    const Client& getClient() const;
    const Angajat& getAngajat() const;
    const std::string& getData() const;
    const std::string& getOra() const;
    plata getTipPlata() const;

    void setData(const std::string& data);
    void setOra(const std::string& ora);
    void setTipPlata(plata tipPlata);

    bool areServiciuCuTimpSuplimentar() const;             //pentru dynamic_pointer_cast
    std::string descriereProgramare() const;

    //calcule cu apel virtual prin pointer de baza
    float calcCostFinal(const std::vector<Programare>& toateProgramarile) const;

    static int numaraProgramariClientZi(const std::vector<Programare>& programari, const Client& client, const std::string& data);
    static float calcIncasariZi(const std::vector<Programare>& programari, const std::string& data);

    friend std::ostream& operator<<(std::ostream& os, const Programare& p);
};


#endif // PROGRAMARE_H
