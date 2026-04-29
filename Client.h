#ifndef CLIENT_H
#define CLIENT_H

#include "Persoana.h";

class Client : public Persoana{
private:
    int nrVizite;
    static int numarClienti;
    void afiseazaVirtual(std::ostream& os) const override;

public:
    Client();
    Client(const std::string& nume, const std::string& prenume, const std::string& telefon, int nrVizite = 0);
    ~Client() override;

    int getNrVizite() const;
    void incrementeazaVizite();
    bool esteClientFidel() const;  //>=5 vizite => reducere
    static int getNrClienti();

    std::string getRol() const override;
    std::shared_ptr<Persoana> clone() const override;
};






#endif // CLIENT_H
