#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <stdlib.h>

using namespace std;

void Espacos ( int n)
{
	string E = " ";
	for ( int i = 0; i <  n ; i++)
	{
		cout << E;
	}
}

void Processos( queue<string> p1, queue<string> p2,queue<string> p3,queue<string> p4){
	
	
	if( p1.empty() && p2.empty() && p3.empty() && p4.empty()){
		cout << "\n\n\t-------INSERINDO PROCESSOS!-------\n\n" << endl;
	}else{
		cout << "\n\n\t--------------------LISTA DE PROCESSOS-------------------\n" << endl;
		
		if(!p1.empty()){
		cout << "\tPARTICAO (1):";
		cout << "\t>> NEXT PROCESS :" << p1.front() << endl;
		}
		
		if(!p2.empty()){
		cout << "\tPARTICAO (2):";
		cout << "\t>> NEXT PROCESS :" << p2.front() << endl;
		}
		
		if(!p3.empty()){
		cout << "\tPARTICAO (3):";
		cout << "\t>> NEXT PROCESS :" << p3.front() << endl;
		}
		
		if(!p4.empty()){
		cout << "\tPARTICAO (4):";
		cout << "\t>> NEXT PROCESS :" << p4.front() << endl;
		}
			
		cout << "\n\t--------------------------------------------------------\n" << endl;
	}
	
		
		
		cin.get();
		
}

void Particoes(string aux, int n, int max, string p){
	string part = "PARTICAO " + p;
	
	if ( !aux.compare(part))
		{
			
			for(int i = 0; i < max ; i++){
				cout << "\t|                    |}" << endl;
			}
			
			cout << "\t|     PARTICAO "<< p << "     |} TAMANHO: "<< n << "  bytes" << endl;
			
			for(int i = 0; i < max ; i++){
				cout << "\t|                    |}" << endl;
			}
			
			cout << "\t|--------------------|" << endl; 
			cout << "\t|--------------------|" << endl;
			
		}else
		{
			
			for(int i = 0; i < int(aux.length()/2) ; i++){
				cout << "\t|                    |}" << endl;
			}
			
			int ocioso = int(n-int(aux.length()));
			
			cout << "\t|" << aux;
			Espacos(20 - aux.length());
			cout << "|} TAMANHO: "<< n << " bytes  // UTILIZADO: " << aux.length() << " bytes  // OCIOSO: " << ocioso << endl;
			
			for(int i = 0; i < int(aux.length()/2) ; i++){
					cout << "\t|                    |}" << endl;
				}
			
			if(aux.length() < n){
				
				cout << "\t|--------------------|" << endl; 
				
				for(int i = 0; i < ocioso/2 ; i++){
					cout << "\t|                    |}" << endl;
				}
				
				cout << "\t|LIVRE"; 
				Espacos(15);
				cout << "|} " << ocioso << " bytes OCIOSOS!" << endl;
				
				for(int i = 0; i < ocioso/2 ; i++){
					cout << "\t|                    |}" << endl;
				}
				
				cout << "\t|--------------------|" << endl;
				
			}else{
				
				cout << "\t|--------------------|" << endl;
				
			}
				
		}
}

void Imprime(string aux1, string aux2, string aux3, string aux4)
{	
	system("cls");
	cout << "\t/////INICIALIZACAO DO SISTEMA COMPUTACIONAL/////" << endl;
	cout << "\tTAMANHO DA MEMORIA PRINCIPAL: 64 BYTES"  << endl;
	cout << "\tPARTICOES CRIADAS: 4" << endl;
	cout << "\tALOCACAO PARTICIONADA ESTATICA" << endl;


	cout << "\t|--------------------|" << endl;
	cout << "\t|                    |}" << endl;
	cout << "\t|                    |}" << endl;
	cout << "\t|         SO         |} TAMANHO: 24 bytes" << endl;
	cout << "\t|                    |}" << endl;
	cout << "\t|                    |}" << endl;
	cout << "\t|--------------------|" << endl;
	cout << "\t|--------------------|" << endl;
	
	Particoes(aux1,10,5,"1");
	
	Particoes(aux2,11,6,"2");
	
	Particoes(aux3,4,2,"3");
	
	Particoes(aux4,15,7,"4");

}



int main()
{	        
	cout << "\t/////INICIALIZACAO DO SISTEMA COMPUTACIONAL/////" << endl;
	cout << "\tTAMANHO DA MEMORIA PRINCIPAL: 64 BYTES"  << endl;
	cout << "\tPARTICOES CRIADAS: 4" << endl;
	vector<char> memory (64);

	queue<string> p1, p2, p3, p4;

	string aux4 = "PARTICAO 4";
	string aux1 = "PARTICAO 1";
	string aux2 = "PARTICAO 2";
	string aux3 = "PARTICAO 3";
	

	while(true)
	{
		int flag = 0;

		Imprime(aux1,aux2,aux3,aux4);
		Processos(p1,p2,p3,p4);
		cout << "\tESCALONANDO PROCESSOS: " << endl;
		cout << "\tPARTICAO: \n"<< "\t>>";
		cin >> flag;
		if(flag == -1) break;
		cout << "\tPARTICAO ESCOLHIDA: " << flag << endl;
		cin.ignore();
		string value; 
		cout << "\tPROGRAMA: \n"<< "\t>>";
		cin >> value;
		if(flag == 1) p1.push(value);
		else if(flag == 2) p2.push(value);
		else if(flag == 3) p3.push(value);
		else if(flag == 4) p4.push(value);

	}
	while(true)
	{
		
		Imprime(aux1,aux2,aux3,aux4);
		Processos(p1,p2,p3,p4);
		
		if(!p1.empty())
		{
			aux1 = p1.front();
			p1.pop();
		}
		else
			aux1 = "PARTICAO 1";
		int j = 0;		
		for(int i = 24; i < 34; i++)
		{
			if(j < aux1.length())
				memory[i] = aux1[j++];
		}

		Imprime(aux1,aux2,aux3,aux4);
		Processos(p1,p2,p3,p4);
		
		if(!p2.empty())
		{
			aux2 = p2.front();
			p2.pop();
		}
		else
			aux2 = "PARTICAO 2";
		j = 0;		
		for(int i = 34; i < 49; i++)
		{
			if(j < aux2.length())
				memory[i] = aux2[j++];
		}

		Imprime(aux1,aux2,aux3,aux4);
		Processos(p1,p2,p3,p4);
		
		if(!p3.empty())
		{
			aux3 = p3.front();
			p3.pop();
		}
		else
			aux3 = "PARTICAO 3";
			
		j = 0;		
		for(int i = 49; i < 53; i++)
		{
			if(j < aux3.length())
				memory[i] = aux3[j++];
		}

		
		Imprime(aux1,aux2,aux3,aux4);
		Processos(p1,p2,p3,p4);
		
		if(!p4.empty())
		{
			aux4 = p4.front();
			p4.pop();
		}
		else
			aux4 = "PARTICAO 4";
			
		j = 0;		
		for(int i = 53; i < 64; i++)
		{
			if(j < aux4.length())
				memory[i] = aux4[j++];
		}
		
		
		Imprime(aux1,aux2,aux3,aux4);
		Processos(p1,p2,p3,p4);

		if(p1.empty() && p2.empty() && p3.empty() && p4.empty()){
			
			Imprime("PARTICAO 1","PARTICAO 2","PARTICAO 3","PARTICAO 4");
			cin.get();
			break;
		}
			
	}

	return 0;
}
