//	Author: Shravam Patel
//	IIT Mandi

#include <bits/stdc++.h>
using namespace std;

void encryptKey(string& key) {
	char ch = 0;
	for(int i = 0; i < key.size(); i++) {
		ch ^= key[i];
	}
	for(int i = 0; i < key.size(); i++) {
		key[i] ^= ch;
	}
}

void encrypt(fstream& fin, string key, fstream& fout) {
	char msg;
	int cnt = 0;
	while (fin >> noskipws >> msg) {
    	msg ^= key[cnt%key.size()];
    	cnt++;
    	fout << msg;
	}
}

int main(int argc, char** argv) {
	
	if( argc < 3 ) {
		cout<<"Usage: filename key"<<endl;
		return 0;
	}

	fstream fin(argv[1], fstream::in);
	if( !fin.is_open() ) {
		cout<<"Error in opening file "<<argv[1]<<endl;
		return 0;
	}
	
	string outputFileName = "D-";
	outputFileName += argv[1];
	
	fstream fout(outputFileName, fstream::out);
	string key = argv[2];
	encryptKey(key);
	encrypt(fin, key, fout);
	return 0;
}