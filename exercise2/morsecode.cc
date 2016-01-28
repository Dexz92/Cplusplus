#include "morsecode.h"

#include <fstream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

MorseCode::MorseCode() {
	ifstream infile("morse.def");
	string code;
	char decode;
	string line;
	while(getline(infile,line)){
		istringstream iss(line);
		iss >> decode;
		iss >> code;
		myMap.insert(make_pair(decode,code));
	}
}

string MorseCode::encode(const string& text) const {
	string encodedText;
	map<char,string>::iterator it;
	for(char ch : text){
		encodedText.append(myMap.find(ch)->second);
	}
	return encodedText;
}

string MorseCode::decode(const string& code) const {
	string decodedWord;
	string decodedText;
	string temp;
	istringstream iss(code);
	while(iss >> decodedWord){
		for(auto it = myMap.begin(); it != myMap.end(); ++it){
			if(it->second == decodedWord){
				temp = it->first;
				decodedText.append(temp);
			}
		}
	}
	return decodedText;
}
