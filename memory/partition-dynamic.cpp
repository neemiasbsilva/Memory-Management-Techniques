#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi process, memory;
vi allocation;

int main(){
	int n; cin >> n;
	int size = 2000;
	for(int i = 0; i < n; i++){
		int temp; cin >> temp;
		process.push_back(temp);	
	}
	//memory.push_back(2000);
	allocation.assign(n, -1);
	for(int i = 0; i < n; i++){
		if(size >= process[i]){
			memory.push_back(process[i]);
			size -= process[i];
			allocation[i] = i;
		}
	}

	cout << "\nProcess Number\tProcess Size\tBlock Memory\n"; 
    for (int i = 0; i < n; i++) 
    { 
        cout << "\t " << i+1 << "\t\t\t\t" 
             << process[i] << "\t\t\t\t"; 
        if (allocation[i] != -1) 
            cout << allocation[i] + 1; 
        else
            cout << "Not Allocated"; 
        cout << endl; 
    } 

	return 0;
}