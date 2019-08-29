#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi process, memory;
vi allocation;

int memory_size;

int Verify(){
	int v = 0;
	for (int i = 0; i < allocation.size() ; i++){
		if( allocation[i] != -1){
			v++;	
		}
	}
	if ( v == 0)
		return 1;
		// VAZIO!
	else
		return 0;
		// ALGUMA PARTE ALOCADA
}

int Vazio(int size){
	
	int n = (int) ((size/100));
			
	if ( n%2 != 0)
		n++;
				
	if ( n == 0)
		n = 1;
	
	if( size > 0 ){
		cout << "\t|--------------------|" << endl;
		for (int i =0; i < n ; i++){
			cout << "\t|                    |}" << endl;
		}
		cout << "\t|  "<< size <<" bytes LIVRES " << endl;
		for (int i =0; i < n ; i++){
			cout << "\t|                    |}" << endl;
		}
		cout << "\t|--------------------|" << endl;
	}
	
	
}

void Processos (){
	cout << "\n\t-------LISTA DE PROCESSOS--------\n" << endl;
	
	for (int i = 0; i < process.size() ; i++){
			cout << "\t{PROCESS " << i + 1 << " - " << process[i] << " bytes} " << endl;
		}
	cout << "\n\t---------------------------------\n" << endl;
}

void Espacos (){
	int n = allocation.size();
	cout << "\n";
	cout << "\t--------------------------------------------------\n" ;
	cout << "\tParticoes Disponiveis:\n" << endl;
	for(int i = 0; i < n ; i++){
		if(allocation[i] == -1){
			cout << "\tParticao " << i+1 << " --> Tamanho: " << memory[i] << "bytes" << endl;
		}
	}
	cout << "\t--------------------------------------------------\n\n" ;
}

vi Remove (int p, vi Vetor){
	vi aux;
	int j = 0;
	// encontra o valor na posicao P, e adiciona todos os valores depois dele em aux
	for(int i = p+1 ; i < Vetor.size() ; i++){
		aux.push_back(Vetor[i]);
		j++;
	}
	// remove de process todos os valores depois de p
	for(int i = 0 ; i < j ; i++){
		Vetor.pop_back();
	}
	//remove p
	Vetor.pop_back();
	//coloca de volta  os valores em process.
	for(int i = 0 ; i < aux.size() ; i++){
		Vetor.push_back(aux[i]);
	} 
	
	return Vetor;
}

void Organiza(){
	//procura por vizinhos vazios e mescla
	for( int i = 0; i < allocation.size()-1 ; i++){
		if(allocation[i] == -1 && allocation[i+1] == -1){
			allocation = Remove(i+1,allocation);
			memory[i] += memory[i+1];
			memory = Remove(i+1,memory);
		}
	}
}



void Imprime ( int size ){
	int x;
	system("clear");
	//system("cls");
	Processos();
	
	Organiza();
	
	cout << "\t|--------------------|" << endl;
	cout << "\t|                    |}" << endl;
	cout << "\t|                    |}" << endl;
	cout << "\t|         SO         |}" << endl;
	cout << "\t|                    |}" << endl;
	cout << "\t|                    |}" << endl;
	cout << "\t|--------------------|" << endl;
	
	if( Verify() == 1){
		Vazio(size);	
	}
	else{
		int i = 0;
		while( i < allocation.size() ){
			if( allocation[i] == 0){
				int n = (int) ((memory[i]/100));
			
				if ( n%2 != 0)
					n++;
					
				if ( n == 0)
					n = 2;
				
				if( memory[i] > 0){
					cout << "\t|--------------------|" << endl;
					for (int j =0; j < n ; j++){
						cout << "\t|                    |}" << endl;
					}
					
					cout << "\t|PROCESSO " << i+1 << "-" << memory[i] << " bytes|}" << endl;
					
					for (int j =0; j < n ; j++){
						cout << "\t|                    |}" << endl;
					}
					cout << "\t|--------------------|" << endl;
					i++;
				}
			}else{
				Vazio(memory[i]);
				i++;
			}
			
		}
		
	}
	
	cin.get();
	
}

void Alocar (){
	int n = process.size();
	int j = 0;
	int proc,part;
	int res;
	vi auxal, auxmem;
	
	cout << "\n\t\t----ESPACO TOTAL DISPONIVEL:" << memory_size << "----\n"<< endl;
	
	Espacos();
	
	cout << "\t--------------------------------------------------\n" ;
	cout << "\tProcessos Disponiveis:\n" << endl;
	
	for (int i = 0; i < n ; i++){
		cout << "\t" <<  i+1 << " - " << process[i] << " bytes" << endl;
	}
	cout << "\t--------------------------------------------------\n" ;
	
	cout << "\n\tProcesso: " << endl;
	cout << "     > " ;
	cin >> proc;
	proc--;
	cout << "\tParticao: " << endl;
	cout << "     > " ;
	cin >> part;
	part--;
	
	// Se tiver livre, e tiver espaco suficiente
	if(allocation[part] == -1 && memory[part] >= process[proc]){
		
		// coloco todos os posteriores a posicao a ser inserida em vetores auxiliares
		for( int k = part+1 ; k < allocation.size() ; k++){
			auxal.push_back(allocation[k]);
			auxmem.push_back(memory[k]);
			j++;
		}
		
		// Removo todos os posteriores a posicao na qual vou inserir
		for( int k = 0 ; k < j ; k++){
			allocation.pop_back();
			memory.pop_back();
		}
		
		// A particao foi alocada
		allocation[part] = 0;
		// Salvo a quantidade de memoria que ficará livre
		res = memory[part] - process[proc];
		// Aloco o processo na memora
		memory[part] = process[proc];
		// Adiciono a particao livre
		allocation.push_back(-1);
		// Coloco a particao livre na memoria
		memory.push_back(res);
		// Somo a quantidade de memoria livre
		memory_size -= process[proc];
		
		// Adiciono novamente os elementos 
		for( int k = 0 ; k < j ; k++){
			allocation.push_back(auxal[k]);
			memory.push_back(auxmem[k]);
		}
		
		// Removo o processo da lista de processos
		process = Remove(proc,process);
		
		cout << "ALOCADO!" << endl;
		cin.get();
		
		
	}else{
		// Se ja estiver alocado ou a memoria for insuficiente
	
			system("clear");
			//system("cls");
			cout << "\n\t--------------------IMPOSSIVEL ALOCAR!--------------------"<< endl;
			
			cin.get();		
			cin.get();
	}
}

void Desalocar (){
	int n = allocation.size();
	int part;
	
	cout << "\t--------------------------------------------------\n" ;
	cout << "\tParticoes Alocadas:\n" << endl;
	
	for(int i = 0; i < n ; i++){
		if(allocation[i] == 0){
			cout << "\t" << i+1 << " - Tamanho: " << memory[i] << "bytes" << endl;
		}
	}
	cout << "\t--------------------------------------------------\n" ;
	
	cout << "     > " ;
	cin >> part;
	part--;
	// desaloco no vetor de alcoacao
	allocation[part] = -1;
	// somo no tamanho total na memoria
	memory_size += memory[part];
}

int Menu(){
	int op;
	cout << endl;
	cout << "\t-----------------------------------" << endl;
	cout << "\t| 1 - Alocar                      |" << endl;
	cout << "\t| 2 - Finalizar Processo          |" << endl;
	cout << "\t| 3 - Adicionar Processos a Fila  |" << endl;
	cout << "\t|-1 - Encerrar                    |" << endl;
	cout << "\t-----------------------------------" << endl;
	cout << "     > " ;
	cin >> op;
	return op;
}

int main(){
	int n=0,temp = 0,m, flag = 0; 
	memory_size = 2000;
	memory.push_back(memory_size);
	allocation.push_back(-1);
	cout << "\t/////INICIALIZACAO DO SISTEMA COMPUTACIONAL/////" << endl;
	cout << "\tTAMANHO DA MEMORIA PRINCIPAL: " << memory_size << " bytes" << endl;
	cout << "\tALOCACAO PARTICIONADA DINÂMICA" << endl;
	cin.get();
	
	m = Menu();
	
	
	while(m != -1){
		if( m == 1){
			if( process.size() < 1){
				system("clear");
				//system("cls");
				cout << "\n\t\t--------- NAO EXISTEM PROCESSOS PARA SEREM ALOCADOS! ---------" << endl;
				cin.get();
				flag = 0;
			}else{
				Alocar();
				flag = 1;
			}
		}else{
			if ( m == 2){
				if( Verify() == 1){
					system("clear");
					//system("cls");
					cout << "\n\t\t--------- MEMORIA TOTALMENTE VAZIA! ---------" << endl;
					cin.get();
					flag = 0;
				}else{
					Desalocar();
					flag = 1;
				}
			}else {
				if( m == 3){
					cout << "\n\tINSERINDO PROCESSOS:" << endl;
					cout << "\tQuantidade: ";
					cin >> n;
					
					for (int i = 0; i < n ; i++){
						cout << "\tPROCESSO "<< i+1 << ": "<< endl;
						cout << "     > " ;
						cin >> temp;
						process.push_back(temp);	
					}
					flag = 1;
				}
			}
		}
		
		if( flag == 1)
			Imprime(memory_size);
		
		m = Menu();
	}

	return 0;
}
