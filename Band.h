#include "includes.h"
#include "WordList.h"

void scrubVerbs(void);

class WordList;

class BandGen
{
public:
	BandGen() //load all the words ("oh boy")
	{
		rand.seed((unsigned int) chrono::system_clock::now().time_since_epoch().count()); //seed rand with current time

		formats = uniform_int_distribution<int>(1,FORMATS);

		//vector<string> = { nounFile, verbFile, adjectiveFile } a bit too fancy
		nouns = WordList(nounFile);
		verbs = WordList(verbFile);
		adjectives = WordList(adjectiveFile);
		names = WordList(nameFile);
	}

	string gen(void)
	{
		//gets random format
		int format = formats(rand);
		string s;

		//TODO: automatically populate this by looking at parts of speech in existing band names
		switch(format)
		{
			case 1: //Talking Heads
				s = verbs(rand) + " " + nouns(rand);
				break;
			case 2: //King Crimson
				s = nouns(rand) + " " + adjectives(rand);
				break;
			case 3: //Rush
				s = nouns(rand);
				break;
			case 4: //Young the Giant
				s = adjectives(rand) + " the " + nouns(rand);
				break;
			case 5: //The Beatles
				s = "The " + nouns(rand);
				break;
			case 6: //A Tribe Called Quest
				s = "A " + nouns(rand) + " called " + nouns(rand);
				break;
			case 7: //Cute is what we Aim for
				s = nouns(rand) + " is what we " + verbs(rand) + " for";
				break;
			case 8: //Bachman-Turner Overdrive
				s = names(rand) + "-" + names(rand) + " " + nouns(rand);
				break;
			case 9: //Emerson, Lake and Palmer
				s = names(rand) + ", " + names(rand) + " and " + names(rand);
				break;
			case 10: //Eating Punching (the classic)
				s = verbs(rand) + " " + verbs(rand);
				break;
			case 100: //B-52s, still in beta
				s = "";
				break;
		}
		return s;
	}

	string operator() (void) //just calls gen
	{
		return this->gen();
	}
private:
	default_random_engine rand;

	WordList nouns;
	WordList verbs;
	WordList adjectives;
	WordList names;

	uniform_int_distribution<int> formats; //used for selecting the format to use
	uniform_int_distribution<int> tailNumber; //used for bands with numbers in the name like Blink-182 or the B-52s
};
