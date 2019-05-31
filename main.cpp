#include <QCoreApplication>
#include <QString>
#include <QDebug>

using namespace std;
// Abstract base class
class Oferta {
public:
    virtual const QString getOfertaPodstawowa() = 0;
    virtual const QString getDodatki() = 0;
    void print() {
        qDebug() << getOfertaPodstawowa() << getDodatki();
    }
    virtual ~Oferta(){qDebug() <<"Oferta usunięta";}
};
// Klasa konkretna
class OszczednaOferta : public Oferta {
public:
    const QString getOfertaPodstawowa() {
        return "Abonament 20zł";
    }
    const QString getDodatki() {
        return "Pakiet 60 minut i 30 sms-ów";
    }
    ~OszczednaOferta(){ qDebug() <<"Oszczędna oferta usunięta"; }
};
// Klasa konkretna
class SredniaOferta : public Oferta {
public:
    const QString getOfertaPodstawowa()
    {
        return "Abonament 50zł";
    }
    const QString getDodatki()
    {
        return "Pakiet 1000 minut i 1000 sms-ów";
    }
    ~SredniaOferta(){ qDebug() <<"Średnia oferta usunięta";}
};
// Klasa konkretna
class DrogaOferta : public Oferta {
public:
    const QString getOfertaPodstawowa() {
        return "Abonament 40zł";
    }
    const QString getDodatki() {
        return "Pakiet 300 minut i 200 sms-ów";
    }
    ~DrogaOferta(){ qDebug() <<"Droga oferta usunięta";}
};
// Abstract Factory returning a Oferta
class OfertaFactory {
public:
    Oferta* getOferta(const QString type)
    {
        if ( type == "Oszczędna" ) return new OszczednaOferta();
        else if ( type == "Średnia" ) return new SredniaOferta();
        else if ( type == "Droga" ) return new DrogaOferta();
        return NULL;
    }
    ~OfertaFactory(){
    }
};
int main()
{
    OfertaFactory* myFactory = new OfertaFactory();
    Oferta* myOferta1 = myFactory->getOferta("Oszczędna");
    myOferta1->print();
    Oferta* myOferta2 = myFactory->getOferta("Średnia");
    myOferta2->print();
    Oferta* myOferta3 = myFactory->getOferta("Droga");
    myOferta3->print();
    delete myOferta1;
    delete myOferta2;
    delete myOferta3;
    return 0;
}
