#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "hash.h"

const string QUIT = ":q";
const string PUT = ":p";
const string REMOVE = ":r";
const string GET = ":g";

void process_file(ifstream &infile, Hash hash, string filename);

int main(int argc, char* argv[]) {
	if(argc != 2){
		cout << "Please input a file." << std::endl;
		return 0;
	}
	else {
		string filename = argv[1];
		ifstream infile;
		Hash hash;
		process_file(infile, hash, filename);

		string command;
		cout << "Welcome to Word Frequency Database." << endl;
		cout << "':p word frequency' adds to the database." << endl;
		cout << "':r word' removes from the database." << endl;
		cout << "':g' gets from the database" << endl;
		cout << "':q' quits." << endl;
		cin >> command;

		while (command != QUIT) {
			string instr;
			if (command == PUT) {
				string instr;
				getline(cin, instr);
				stringstream iss(instr); 
				string text_word;
				iss >> text_word;
				int hashNum = hash.hashStr(text_word);
				int freq;
				iss >> freq;
				// Insert each word into hash table with values
				Entry entry;
				entry.frequency = freq;
				entry.word = text_word;

				hash.insertInHash(entry, hashNum);
			}
			else if (command == REMOVE) {
				string instr;
				getline(cin, instr);
				stringstream iss(instr); 
				string text_word;
				iss >> text_word;
				int hashNum = hash.hashStr(text_word);

				hash.remove(hashNum, text_word);
			}
			else if (command == GET) {
				string instr;
				getline(cin, instr);
				stringstream iss(instr); 
				string text_word;
				iss >> text_word;

				hash.search(text_word);
			}
			else if (command == QUIT) {
				return 0;
			}
			else {
				cout << "Command not recognized." << endl;
			}
			cin >> command;
		}
		return 0;
	}
}


void process_file(ifstream &infile, Hash hash, string filename) {
	infile.open(filename.c_str());
	if (!infile.is_open()) {
		cout << "Unable to open file " << filename << "\n";
		return;
	}
	else{
		while (!infile.eof()){
			string instr;
			getline(infile, instr);
			stringstream iss(instr); 
			string text_word;
			iss >> text_word;
			int hashNum = hash.hashStr(text_word);
			int freq;
			iss >> freq;

			// Insert each word into hash table with values
			Entry entry;
			entry.frequency = freq;
			entry.word = text_word;
			hash.insertInHash(entry, hashNum);
		}
	}
	infile.close();
	return;
}

