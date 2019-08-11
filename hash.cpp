/*********************************************************
 * This is the Hash class file. Using the vector created
 * in the FileProcessing class, it hashes all words in a 
 * 2D vector of vectors account for any collisions. It 
 * also has functions to search for a queried word.
 *********************************************************/

#include "hash.h"
#include <vector>
#include <istream>
#include <string>


using namespace std;
static const int PRIME = 16908799;

// Default constructor
Hash::Hash()
{
	hash.resize(100000);
}

// Function: hashStr
// Parameters: string of word queried
// Returns: int of hash key
// Does: hashes the inputted query word. 
int Hash::hashStr(string word)
{
	int hashVal = 0;
	for (size_t i = 0; i < word.length(); i++) {
    	hashVal = (127 * hashVal + word[i]) % PRIME;
 	}
 	hashVal = hashVal % hash.size();
 	return hashVal;

}

// Function: insertInHash
// Parameters: string of word queried, hash key, vector of entry nodes
// Returns: nothing
// Does: inserts entry into the hash table at the vector corresponding
// to the key. If a collision happens, another vector is used to identify
// the word.
void Hash::insertInHash(Entry entry, int hashNum)
{
	// push entry into bucket
	hash[hashNum].push_back(entry);
}

// Function: search
// Parameters: string of word queried, vector of entry nodes
// Returns: nothing
// Does: Searches through hash table. If query contained, all entry
// information is outputted.
void Hash::search(string word)
{
	int keyToSearch = hashStr(word);
	int bucketNum = getBucket(keyToSearch, word);
	int len = hash[keyToSearch].size();

	for (int i = 0; i < len; i++){
		//if (keyToSearch == containedKey){
		 	cout << hash[keyToSearch].at(i).word << ": ";
		 	cout << hash[keyToSearch].at(i).frequency << endl; 
		//}
	}
	return;
}

// Function: getBucket
// Parameters: string of word queried, hash number, and entry object
// Returns: int of bucket number
// Does: Checks for collisions, incrementing i until word is reached 
// to identify spot of bucket for word.
int Hash::getBucket(int hashNum, string word)
{
	for (int i = 0; i < hash[hashNum].size(); i++){
		if (hash[hashNum].at(i).word == word){
			return i;
		}
	}
	// if not found
	return -1;
}	

void Hash::remove(int hashNum, string Word) 
{
	// iterate thropguh to find then add that var to begin
	// myvector.erase (myvector.begin()+5);
}

// Function: Expand
// Parameters: string of word queried
// Returns: int of hash key
// Does: hashes the inputted query word. 
void Hash::expand()
{

}
