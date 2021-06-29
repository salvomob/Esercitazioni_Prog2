/* 	Appunti del Corso di Programmazione II (M-Z) - Docente Simone Faro
	Università degli Studi di Catania - Dipartimento di Matematica e Informatica
	Corso di Laurea Triennale in Informatica
*/

#include <iostream>
#include <math.h>
using namespace std;

// Una classe per la definizione dei Fattori Nutrizionali
// Esempio di oggetto immutabile costruito con il metodo Builder

// numero elevato di variabili all'interno della classe
// immutabilità grantita?

class NutritionFacts {
private:
    int porzioni, peso, calorie, grassi, sodio, carboidrati;
    // potrebbero essere molti di più
    NutritionFacts() {
        porzioni = 0;
        peso = 0;
        calorie = 0;
        grassi = 0;
        sodio = 0;
        carboidrati = 0;
    }
    
    NutritionFacts(int porzioni, int peso, int calorie, int grassi, int sodio, int carboidrati) {
        this->porzioni = porzioni;
        this->peso = peso;
        this->calorie = calorie;
        this->grassi = grassi;
        this->sodio = sodio;
        this->carboidrati = carboidrati;
    }

public:
    
    class Builder {
    private:
        int porzioni, peso, calorie, grassi, sodio, carboidrati;
    public:
        Builder() {
            porzioni = 0;
            peso = 0;
            calorie = 0;
            grassi = 0;
            sodio = 0;
            carboidrati = 0;
        }
        Builder& setPorzioni(int porzioni) {
            this->porzioni = porzioni;
            return *this;
        }
        Builder& setPeso(int peso) {
            this->peso = peso;
            return *this;
        }
        Builder& setCalorie(int calorie) {
            this->calorie = calorie;
            return *this;
        }
        Builder& setGrassi(int grassi) {
            this->grassi = grassi;
            return *this;
        }
        Builder& setSodio(int sodio) {
            this->sodio = sodio;
            return *this;
        }
        Builder& setCarboidrati(int carboidrati) {
            this->carboidrati = carboidrati;
            return *this;
        }
        NutritionFacts build() {
            //NutritionFacts nf(porzioni,peso,calorie,grassi,sodio,carboidrati);
            NutritionFacts nf;
            nf.porzioni = porzioni;
            nf.peso = peso;
            nf.calorie = calorie;
            nf.grassi = grassi;
            nf.sodio = sodio;
            nf.carboidrati = carboidrati;
            return nf;
        }
    };
    
    int getPorzioni() {return porzioni;}
    int getPeso() {return peso;}
    int getCalorie() {return calorie;}
    int getGrassi() {return grassi;}
    int getSodio() {return sodio;}
    int getCarboidrati() {return carboidrati;}
};

ostream& operator<<(ostream& os, const NutritionFacts& CocaCola) {
    NutritionFacts tmp = CocaCola;
    os << "[";
    os << tmp.getPorzioni() << ", ";
    os << tmp.getPeso() << ", ";
    os << tmp.getCalorie() << ", ";
    os << tmp.getGrassi() << ", ";
    os << tmp.getSodio() << ", ";
    os << tmp.getCarboidrati();
    os << "]";
    return os;
}

int main() {
    NutritionFacts CocaCola = NutritionFacts::Builder().
        setPorzioni(2).
        setCalorie(1023).
        setGrassi(23).
        setCarboidrati(453).
        setPeso(78).
        setSodio(129).
        build();
    
    
    //NutritionFacts CocaCola = tmp.build();
    //NutritionFacts CocaCola(2,78,1023,23,129,453);
    
    cout << CocaCola << endl;
}



