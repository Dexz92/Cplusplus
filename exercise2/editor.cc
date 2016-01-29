#include "editor.h"

#include <string>
#include <vector>

using namespace std;

string::size_type Editor::find_left_par(string::size_type pos) const {
	char right = text[pos];
	char left;
	if(right == ')'){
		left = '(';
	}else if(right == '}'){
		left = '{';
	}else if(right == ']'){
		left = '[';
	}else{
		return string::npos;
	}
	vector<string::size_type> container;
	string::size_type counter = 0;
	while(counter < text.size()){
		if(text[counter] == left){
			container.push_back(counter);
		}else if(text[counter] == right){
			if(container.empty()){
				return string::npos;
			}else if(counter == pos){
				return container.back();
			}else{
				container.pop_back();
			}
		}
		++counter;
	}
	return string::npos;
}
