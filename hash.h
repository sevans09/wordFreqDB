#ifndef HASH_HPP
#define HASH_HPP

#include <string>
#include <iostream>
#include <vector>

using namespace std;

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
	void search(string word);
	// expand function to expand hash table
	void expand();
	// function to insert in the hash table from the buffer vector
	void insertInHash(Entry entry, int hashNum);
private:
	// function to get the index of the collision bucket
	int getBucket(int hashNum, string word);
 	// vector of vector of linked list of entries for the hash tables
	vector<vector<Entry> > hash;
	// load factor to use for the expand function
	int loadFactor;
};

#endif
