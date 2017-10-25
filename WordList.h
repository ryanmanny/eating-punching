#include "includes.h"

class WordList
{
public:
	vector<string> words;
	uniform_int_distribution<int> distribution; //used for rand, size of wordList

	WordList() //empty constructor needed for private data member initialization I think
	{

	}
	WordList(const string & fileName)
	{
		string s;

		//cout << "Loading " << fileName << endl;
		//cin.ignore();

		//reads all words in file into vector
		ifstream infile(fileName);
		if (infile.is_open())
		{
			while (!infile.eof())
			{
				infile >> s;		//read from file
				words.push_back(s);	//add to vector
			}
			infile.close();
		}

		//creates distribution between 1 and size
		distribution = uniform_int_distribution<int>(0,words.size());
	}

	//returns a random word from the list using r random engine
	string operator() (default_random_engine r)
	{
		return words.at(distribution(r));
	}
};
