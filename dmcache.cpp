#include <iostream>
#include <string>
#include <bitset>
#include <fstream>



using namespace std;

int main(){
	int i, j;
	/*********initialize memory block/cache line********/
	string cache[32][2];      //cache[32][0]; stores the tag and cache[32][1] stores if dirty bit or not
	string memory[8]; 	//stores data, it is indexed by the offset we recieve from cacheline

	for (i = 0; i < 32; i++){
		for (j = 0; j < 2; j++){
			cache[i][j] = "0";
		}
	}

	/**********get data from test file/ convert the cache line************/
	ifstream fs;
	fs.open("dmtest300.txt");
	int offset, index, tag;
	int cacheLine, ops, data;

	while (fs >> hex >> cacheLine >> ops >> data){

		offset = cacheLine & 7;
		index = (cacheLine & 248) >> 3;
		tag = (cacheLine & 65280) >> 8;
		cout << offset << " " << index << " " << tag << endl;
	}



	fs.close();



	/*************cache-write-in**************/


	/************return cache file***************/
	system("pause");
	return 0;
}