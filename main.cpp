#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main(int argc, char* argv[]){
	if(argc != 2){
		std::cout << "Please input a file." << std::endl;
		return 0;
	}
	else{
		string filename = argv[1];
		ifstream infile;
		Hash hash;
		process_file(infile, hash, filename)

	}
		return 0;
	}


process_file() {
	infile.open(filename.c_str());
	if (!infile.is_open()) {
        cerr << "Unable to open file " << filename << "\n";
        return;
    }
    else{
	while (!infile.eof()){
		string instr;
		getline(infile, instr);
		stringstream iss(instr); 
		//Use string stream to read each word with its frequency
		while (iss >> instr){
			// Trim word
			string newStr = stringTrim(instr);
			int len = instr.length();
			if (len == 0) continue;
			// Make whole word lowercase
			for (size_t i = 0; i < instr.length(); i++)
				instr[i] = tolower(instr[i]);
			// Hash word
			int hashNum = hash.hashStr(newStr);
			// Insert each word into hash table with values
			Entry entry;
			entry.sentence = sentence;
			entry.word = query;
			entry.filepath = filename;
			entry.key = hashNum;
			entry.lineNum = line_num;
			filepaths.push_back(entry);
			hash.insertInHash(entry, hashNum, filepaths);
		}
	}
	infile.close();
	return;
}

