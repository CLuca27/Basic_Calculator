
#include <iostream> 
#include <string> 
#include <math.h>
using namespace std;
class Calculator{

	double rezultatCurent;
	double* memorieRezultate;
	string* memorieOperatii; 
	string operatie;
	int numarRezultate; 
	int numarOperatii;
public: 
	//constructor default
	Calculator() {
		memorieRezultate = nullptr;
		memorieOperatii = nullptr;
		rezultatCurent = 0;
	    numarRezultate = 0; 
		numarOperatii = 0;
	} 
	//constructor de copiere
	Calculator(const Calculator& c)
	{
		this->rezultatCurent = c.rezultatCurent;
		this->numarRezultate = c.numarRezultate;
		this->numarOperatii = c.numarOperatii;
		if (this->numarRezultate == 0)
			this->memorieRezultate = nullptr;
		else
		{
			this->memorieRezultate = new double[this->numarRezultate];
			for (int i = 0; i < this->numarRezultate; i++)
				this->memorieRezultate[i] = c.memorieRezultate[i];
		}
		if (this->numarOperatii == 0)
			this->memorieOperatii = nullptr;
		else
		{
			this->memorieOperatii = new string[this->numarOperatii];
			for (int i = 0; i < this->numarOperatii; i++)
				this->memorieOperatii[i] = c.memorieOperatii[i];
		}

	} 
	//destructor
	~Calculator() {
		delete[] this->memorieRezultate;
		delete[] this->memorieOperatii;
	} 
	void AdaugareRezultat(double rezultatCurent) //Adauga rezultatul curent in memorie
	{	
		if (numarRezultate == 0)
		{
			
			memorieRezultate = new double[1];
			memorieRezultate[0] = rezultatCurent;
			numarRezultate++;
		} 
		else
		{
			double* aux;
			if (numarRezultate < 10)
			{
				
				aux = new double[++numarRezultate];
				for (int i = 0; i < numarRezultate - 1; i++)
					aux[i] = memorieRezultate[i]; 
			} 
			else
			{
				aux = new double[numarRezultate]; 
				for (int i = 1; i < numarRezultate ; i++)
					aux[i - 1] = memorieRezultate[i]; 

			} 
			aux[numarRezultate - 1] = rezultatCurent;
			delete[] memorieRezultate;
			memorieRezultate = aux;

		}
	} 
	void AdaugareOperatie(string operatieCurenta) //Adauga operatia curenta in memorie
	{
 
			if (numarOperatii == 0)
			{
				memorieOperatii = new string[1]; 
				memorieOperatii[0] = operatieCurenta; 
				numarOperatii++;

			} 
			else
			{
				string* aux;
				if (numarOperatii < 10)
				{
					aux = new string[++numarOperatii];
					for (int i = 0; i < numarOperatii - 1; i++)
						aux[i] = memorieOperatii[i];
					aux[numarOperatii - 1] = operatieCurenta;
				}
				else
				{
					aux = new string[numarOperatii];
					for (int i = 1; i < numarOperatii; i++)
						aux[i - 1] = memorieOperatii[i];
					aux[numarOperatii - 1] = operatieCurenta;
				}
				delete[] memorieOperatii;
				memorieOperatii = aux;
			}
	} 

	void setRezultatCurent(double rezultatCurent)
	{
		this->rezultatCurent = rezultatCurent; 
    }
	double getRezultatCurent()
	{
		return rezultatCurent;
	} // Functii care usureaza proceul de testare a functionalitatii
	void Clear() //Sterge rezultatul curent, revenind la 0
	{
		rezultatCurent = 0;
	} 
	
	void Self() //Introduce in memorie rezultaul curent cand nu se efectueaza nicio operatie cu acesta 
		        // Echivalent cu apasarea butonului '=' cand nicio operatie nu este realizata cu rezultatul curent
	{
		operatie = to_string(rezultatCurent); 
		this->AdaugareOperatie(operatie); 
		this->AdaugareRezultat(rezultatCurent);
	} 
	//Curatarea emoriei
	void CuratareMemorie() {
		delete[] memorieOperatii;
		delete[] memorieRezultate;
		memorieOperatii = nullptr; 
		memorieRezultate = nullptr; 
		numarOperatii = 0; 
		numarRezultate = 0;
	}
	void operator=(const Calculator& c)
	{
		this->numarRezultate = c.numarRezultate; 
		this->numarOperatii = c.numarOperatii; 
		this->rezultatCurent = c.rezultatCurent; 
		delete[] this->memorieOperatii;
		if (this->numarOperatii == 0)
			this->memorieOperatii = nullptr; 
		else
		{
			this->memorieOperatii = new string[this->numarOperatii]; 
			for (int i = 0; i < this->numarOperatii; i++)
				this->memorieOperatii[i] = c.memorieOperatii[i];
		} 
		delete[] this->memorieRezultate;
		if (this->numarRezultate == 0)
			this->memorieRezultate = nullptr;
		else
		{
			this->memorieRezultate = new double[this->numarRezultate];
			for (int i = 0; i < this->numarRezultate; i++)
				this->memorieRezultate[i] = c.memorieRezultate[i];
		}
	}
	Calculator operator+(double numarIntrodus) //adunare
	{   
		Calculator aux = *this; 
		string operatie = to_string(rezultatCurent) + " + " + to_string(numarIntrodus);
		aux.rezultatCurent = rezultatCurent + numarIntrodus; 
		aux.AdaugareRezultat(aux.rezultatCurent); 
		aux.AdaugareOperatie(operatie);
		return aux;
	} 
	Calculator operator-(double numarIntrodus) //scadere
	{
		Calculator aux = *this; 
		operatie = to_string(rezultatCurent) + " - " + to_string(numarIntrodus);
		aux.rezultatCurent = rezultatCurent - numarIntrodus; 
		aux.AdaugareRezultat(aux.rezultatCurent); 
		aux.AdaugareOperatie(operatie);
		return aux;
	}
	Calculator operator*(double numarIntrodus) //inmultire
	{
		Calculator aux = *this; 
		operatie = to_string(rezultatCurent) + " * " + to_string(numarIntrodus);
		aux.rezultatCurent = rezultatCurent * numarIntrodus;
		aux.AdaugareRezultat(aux.rezultatCurent);
		aux.AdaugareOperatie(operatie);
		return aux;
	} 
	Calculator operator/(double numarIntrodus) //impartire
	{
		if (numarIntrodus == 0)
		{
			cout << "Nu se poate imparti la 0 !" << endl;
			return *this;
		}
		else
		{
			Calculator aux = *this; 
			operatie = to_string(rezultatCurent) + " / " + to_string(numarIntrodus);
			aux.rezultatCurent = rezultatCurent / numarIntrodus; 
			aux.AdaugareRezultat(aux.rezultatCurent); 
			aux.AdaugareOperatie(operatie);
			return aux;
		}
	} 
	Calculator operator!() //operatia de negatie 
	{
		operatie = "negate(" + to_string(rezultatCurent) + ')';
		rezultatCurent = 0 - rezultatCurent;
		AdaugareRezultat(rezultatCurent);
		AdaugareOperatie(operatie);
		return *this ;
	}
	double& operator[](int index) //aduce in rezultatul curent o valoare din memorie
	{
		
		if (index >= 0 && index < numarRezultate)
		{
			rezultatCurent = memorieRezultate[index]; 
			return memorieRezultate[index]; /*Nu era obligatoriu sa returnez o referinta la adresa de memorie,
			                                insa am vrut sa patrez logica operatorului '[]'
			                                Aplicatia de calculator(din Windows) actualizeaza valoarea curenta cu rezultatul din memorie */
        }
	
	}
	void Radical()
	{
		if (rezultatCurent < 0)
			cout << "Operatie invalida !" << endl;
		else
		{
			operatie = "sqrt(" + to_string(rezultatCurent) + ')';
			rezultatCurent = sqrt(rezultatCurent);  
			AdaugareOperatie(operatie);
			AdaugareRezultat(rezultatCurent);
		}
	}
	void Putere(double putere) //ridicarea la putere
	{
		operatie = to_string(rezultatCurent) + " ^ " + to_string(putere);
		rezultatCurent = pow(rezultatCurent, putere);
		AdaugareOperatie(operatie); 
		AdaugareRezultat(rezultatCurent);
	} 
	void Inversare()
	{
		if (rezultatCurent == 0)
			cout << "Nu se poate imparti la 0 !" << endl;
		else
		{
			operatie = "1/(" + to_string(rezultatCurent) + ')';
			rezultatCurent = 1 / rezultatCurent; 
			AdaugareOperatie(operatie); 
			AdaugareRezultat(rezultatCurent);
		}
			
	} 
	friend void AfisareMemorieOperatii(Calculator r);

};  
void AfisareMemorieOperatii(Calculator r)
{
	if (r.numarOperatii == 0)
		cout << "Nu e nimic salvat in memorie pana acum !" << endl; 
	else
	{
		for (int i = 0; i < r.numarOperatii; i++)
		{
			cout << r.memorieOperatii[i] << " = " << endl;
			cout << r.memorieRezultate[i] << endl;
		}
	} 
}
int main() { 
    Calculator c1; 
	c1.setRezultatCurent(2); //Introducem un numar si incepem sa efectuam operatiile definite mai sus
	c1.Self();
	c1 = c1 + 2.5553; //0
	c1 = c1 * 90; //1
	c1 = c1 - 1000.9995; //2 <- rezultaul pe care il aducem
	c1 = c1 / 0.1; //3
	c1[2]; //Aducerea in rezultatul curent a valorii obtinute la operatia 3, salvata in memorie 
	c1.Radical(); 
	c1.Inversare();
	!c1; 
	AfisareMemorieOperatii(c1);  //Demonstrarea functionalitatii operatiilor si afisarea acestora in memorie
	c1.Clear(); //Resetam valoarea curenta la 0 
	cout << c1.getRezultatCurent() << endl; //Demonstratie ca valoarea a fost resetata 
				 
 /*Luam cazurile particulare in care functiile de inversare, impartire si
   de obtinere a radacinei patrate nu pot fi efectuate folosind rezultatul curent*/ 
	c1.Inversare();
	c1 = c1 / 0;
	c1 = c1 - 1.55555; 
	c1.Radical(); 
	c1.CuratareMemorie(); //Eliberam memoria
	AfisareMemorieOperatii(c1); 
	return 0;
} 

