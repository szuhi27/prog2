#include <iostream>		
#include <cmath>		
#include <fstream>		
using namespace std;

class Binfa{

public:
 Binfa(){
 	aktcsomopont = gyoker;
 }
~Binfa(){
torol(gyoker);
}
Binfa (Binfa&& regi)
{
	gyoker = nullptr;
	*this =std::move(regi);
	//std:cout<<"mozog\n";
}
Binfa& operator= (Binfa&& regi)
{std::swap(gyoker, regi.gyoker);
	return *this;

}


void operator<<(char b){
if(b=='0')
 {if(!aktcsomopont->getbalnulla())
{Csomopont *uj = new Csomopont('0');
aktcsomopont->ujbalnulla(uj);
aktcsomopont = gyoker;
}else
{aktcsomopont=aktcsomopont->getbalnulla();}
}
else{
	if(!aktcsomopont->getjobegy())
{Csomopont *uj = new Csomopont('1');
aktcsomopont->ujjobbegy(uj);
aktcsomopont = gyoker;
}else
{aktcsomopont=aktcsomopont->getjobegy();}
}}
void kiir(void){
melyseg = 0;
kiir(gyoker,std::cout);
}
int getMelyseg(void);
double getAtlag(void);
double getSzoras(void);
friend std::ostream & operator<< (std::ostream & os, Binfa & bf )
{bf.kiir(os);
return os;}
void kiir(std::ostream & os){
melyseg=0;
kiir(gyoker, os);

}
private:
	class Csomopont
	{ public:
		Csomopont(char b='/'):betu (b), balnulla(0), jobbegy(0){};
	~Csomopont(){};
	Csomopont *getbalnulla() const{
		return balnulla;
	}
	Csomopont *getjobegy() const {
		return jobbegy;
	}
	void ujbalnulla(Csomopont *gy){
		balnulla=gy;
	}
	void ujjobbegy(Csomopont *gy){
		jobbegy = gy;
	}
	char getbetu()const{ return betu;}
private:
	char betu;
	Csomopont *balnulla;
	Csomopont *jobbegy;
	Csomopont(const Csomopont&);
	Csomopont & operator=(const Csomopont&);
	};//class vege csomopont
	Csomopont *aktcsomopont;
	int melyseg,atlagosszeg,atlagdb;
	double szorasosszeg;
	Binfa (const Binfa &);
Binfa & operator= (const Binfa &);

	void kiir(Csomopont * elem,std::ostream & os){
		if(elem != NULL)
		{
			++melyseg;
			kiir(elem->getbalnulla(),os);
			for (int i = 0; i < melyseg; ++i)
			os << "---";
			os << elem->getbetu () << "(" << melyseg << ")" << endl;
			kiir (elem->getjobegy(), os);
			--melyseg;
		}	
	}

	void torol(Csomopont * elem){
if(elem != NULL)
{
torol(elem->getbalnulla());
torol(elem->getjobegy());
delete elem;
}
	
}
protected:
	Csomopont* gyoker = new Csomopont();
	int maxmelyseg;
	double atlag, szoras;
void rmelyseg(Csomopont * elem);
void ratlag (Csomopont * elem);
void rszoras(Csomopont * elem);
};//classvege binfa

int Binfa::getMelyseg(void){

	melyseg=maxmelyseg=0;
	rmelyseg(gyoker);
	return maxmelyseg;
}
void Binfa::rmelyseg(Csomopont * elem){
if(elem !=NULL)
{
	++melyseg;
	if(melyseg>>maxmelyseg)
		maxmelyseg=melyseg;
	rmelyseg(elem->getjobegy());
	rmelyseg(elem->getbalnulla());
	--melyseg;
}
}

double Binfa::getAtlag(){
melyseg=atlagosszeg=atlagdb=0;
ratlag(gyoker);
atlag = ((double)atlagosszeg)/atlagdb;
return atlag;
}


void Binfa::ratlag(Csomopont *elem){
	if(elem!=NULL)
	{
		++melyseg;
		ratlag(elem->getjobegy());
		ratlag(elem->getbalnulla());
		--melyseg;
		if(elem->getjobegy()==NULL and elem->getbalnulla()==NULL)
		{
			++atlagdb;
			atlagosszeg+=melyseg;
		}
	}

}

double Binfa::getSzoras(){
atlag= getAtlag();
szorasosszeg = 0.0;
melyseg= atlagdb= 0;
rszoras(gyoker);
if(atlagdb-1>0)
	szoras = sqrt(szorasosszeg/(atlagdb-1));
	else
		szoras = sqrt(szorasosszeg);
	return szoras;


}


void Binfa::rszoras(Csomopont *elem){
if(elem != NULL)
	{++melyseg;
	rszoras(elem->getjobegy());
	rszoras(elem->getbalnulla());
	--melyseg;
	if(elem->getjobegy()==NULL && elem->getbalnulla()==NULL)
{++atlagdb;
szorasosszeg+=((melyseg-atlag)*(melyseg-atlag));}
	}
}


void usage (){
	cout<<"Usage: lzwtree in_file -o out_file "<<endl;;
}

int main (int argc, char *argv[]){
 if (argc != 4)
    {
    
        usage ();
        
        return -1;
    }

    char *inFile = *++argv;

    
    if (*((*++argv) + 1) != 'o')
    {
        usage ();
        return -2;
    }

   
    std::fstream beFile (inFile, std::ios_base::in);


    if (!beFile)
    {
        std::cout << inFile << " nem letezik..." << std::endl;
        usage ();
        return -3;
    }
std::fstream kiFile (*++argv, std::ios_base::out);

    unsigned char b;		
   Binfa binFa;		

while (beFile.read ((char *) &b, sizeof (unsigned char)))
        if (b == 0x0a)
            break;

    bool kommentben = false;

    while (beFile.read ((char *) &b, sizeof (unsigned char)))
    {

        if (b == 0x3e)
        {		
            kommentben = true;
            continue;
        }

        if (b == 0x0a)
        {		
            kommentben = false;
            continue;
        }

        if (kommentben)
            continue;

        if (b == 0x4e)		
            continue;

 
        for (int i = 0; i < 8; ++i)
        {
           
            if (b & 0x80)
            
                binFa << '1';
            else
             
                binFa << '0';
            b <<= 1;
        }

    }
    kiFile <<"Eredeti"<<endl<< binFa;		

    kiFile << "depth = " << binFa.getMelyseg () << std::endl;
    kiFile << "mean = " << binFa.getAtlag () << std::endl;
    kiFile << "var = " << binFa.getSzoras () << std::endl;
Binfa binFa1 =std::move(binFa);

  kiFile <<endl<<"regi mozgatas utan:"<<endl<<endl<< binFa;		

    kiFile << "depth = " << binFa.getMelyseg () << std::endl;
    kiFile << "mean = " << binFa.getAtlag () << std::endl;
    kiFile << "var = " << binFa.getSzoras () << std::endl;





    kiFile << endl<<"Mozgatott fa:"<<endl<<binFa1;		

    kiFile << "depth = " << binFa1.getMelyseg () << std::endl;
    kiFile << "mean = " << binFa1.getAtlag () << std::endl;
    kiFile << "var = " << binFa1.getSzoras () << std::endl;

    kiFile.close ();
    beFile.close ();

    return 0;
}
