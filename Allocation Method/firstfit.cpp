#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi blockSize, processSize;
//store block id of the block allocated to a process
vi allocation;

void firstfit(int n, int qtd){
	allocation.assign(qtd, -1);

    for (int i = 0; i < qtd; i++) 
    { 
        for (int j = 0; j < n; j++) 
        { 
            if (blockSize[j] >= processSize[i]) 
            { 
                allocation[i] = j;  
                blockSize[j] -= processSize[i]; 
  
                break; 
            } 
        } 
    } 

    cout << "\nProcess Number\tProcess Size\tBlock Memory\n"; 
    for (int i = 0; i < qtd; i++) 
    { 
        cout << "\t " << i+1 << "\t\t\t\t" 
             << processSize[i] << "\t\t\t\t"; 
        if (allocation[i] != -1) 
            cout << allocation[i] + 1; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, qtd; cin >> n >> qtd;

	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		blockSize.push_back(temp);
	}

	for(int i = 0; i < qtd; i++){
		int temp; cin >> temp;
		processSize.push_back(temp);
	}

	firstfit(n, qtd);

	return 0;
}