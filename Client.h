#ifndef CLIENT_H
#define CLIENT_H
#include <memory>

class Persoana;

class Client : public Persoana{
private:
    int nrVizite;
    static int numarClienti;
    void afiseazaVirtual(std::ostream& os) const override;

public:
    Client() = default;
    Client(const std::string& nume, const std::string& prenume, const std::string& telefon, int nrVizite = 0);
    ~Client() override;

    int getNrVizite() const;
    void incrementeazaVizite();
    bool esteClientFidel() const;  //>=5 vizite => reducere
    static int getNrClienti();

    std::string getRol() const override;
};






#endif // CLIENT_H
