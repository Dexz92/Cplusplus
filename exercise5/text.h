#ifndef TEXT_H
#define TEXT_H

#include "Textiterator.h"
#include <string>
#include <vector>

class Text {
public:
	using iterator = Textiterator;
	iterator begin() {
		return iterator(&lines,0);
	}
	iterator end() {
		return iterator(&lines,lines.size());
	}
	void addLine(const std::string& line) { lines.push_back(line); }
private:
	std::vector<std::string> lines;
};

#endif
