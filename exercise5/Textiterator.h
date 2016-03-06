#ifndef TEXTITERATOR_H
#define TEXTITERATOR_H

#include <string>
#include <vector>

class Textiterator{
public:
  Textiterator(std::vector<std::string>* l,size_t line) : lines(l), current_line(line), current_pos(0){}

  bool operator!=(const Textiterator& rhs) const{
    return lines != rhs.lines || current_line != rhs.current_line || current_pos != rhs.current_pos;
  }

  char& operator*() const {
    return (*lines)[current_line][current_pos];
  }

  Textiterator& operator++(){
    if(current_pos != (*lines)[current_line].size() - 1){
      ++current_pos;
    }else{
      current_pos = 0;
      ++current_line;
    }
    return *this;
  }
private:
  std::vector<std::string>* lines;
  size_t current_line;
  std::string::size_type current_pos;
};

#endif
