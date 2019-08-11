#ifndef HASH_HPP
#define HASH_HPP

#include <string>
#include <iostream>

// struct of entry nodes to be inserted in the hash table
struct Entry {
	string word;
	int frequency;
}; 

class Hash{
public:
	// default constructor
	Hash();
	// function to hash words
	int hashStr(string instr);
	// function to search for queries
	void search(string word, vector<Entry> &filepaths);
	// expand function to expand hash table
	void expand();
	// function to print each component of the structure
	void printEntry(vector<Entry> &filepaths, int i);
	// function to insert in the hash table from the buffer vector
	void insertInHash(Entry entry, int hashNum, vector<Entry> &filepaths);
private:
	// function to get the bucket of the collision
	int getBucket(int hashNum, string word);
	// vector of vector of linked list of entries for the hash tables
	vector<vector<list<Entry> > > hash;
	// vector of a string of sentences to speed up time
	vector<string> sentences;
	// load factor to use for the expand function
	int loadFactor;
};

#endif
