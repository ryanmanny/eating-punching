#include "Band.h"

int main(void)
{
	//scrubVerbs();
	ofstream generatedNames("generatedNames.txt", ios_base::app); //opens file in append mode to keep track of full history
	string bandName;

	cout << " [x] Constructing BandGen" << endl;
	BandGen band;
	cout << " [x] WordLists loaded" << endl;

	generatedNames << endl;

	char c = '\0';
	do {
		bandName = band();
		cout << bandName << endl;
		generatedNames << bandName << endl;

		cout << "Want another band name? (y/n) ";
		cin >> c;
	} while(c == 'y' || c == 'Y');

}

//we just want "ing verbs"
void scrubVerbs()
{
	ifstream infile("wordLists/31kverbs.txt");
	ofstream outfile(verbFile);

	string s;
	string last; //last 3 letters of ye string

	cout << " [x] Scrubbing VerbList of non-\"ing\" verbs" << endl;

	while (!infile.eof())
	{
		infile >> s;

		//cout << "Processing " << s << endl;
		last = s.substr(s.length() - 3, 3);

		//only copies strings that have "ing" within
		// I can't think of any 5 letter gerunds.
		if (s.length() > 5 && last.find("ing") != string::npos) //figure out what the difference between string::npos and s.end() are
		{
			outfile << s << endl;
			//cout << s << " is legit" << endl;
		}
	}
	cout << " [x] VerbList scrubbed" << endl;
	infile.close();
	outfile.close();
}
