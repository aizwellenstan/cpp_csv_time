#include "csv.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
 
void read_csv(std::vector<std::vector<std::string>>& ct,
              const std::string& filename)
{
  std::string str;
  std::string buf;
  std::ifstream ifs(filename);
 
  while (std::getline(ifs, str)) {
    std::istringstream is(str);
    std::string str;
    std::vector<std::string> v;
 
    while (std::getline(is, buf, ',')) {
      v.push_back(buf);
    }
    ct.push_back(v);
  }
}
 
void print_csv(std::vector<std::vector<std::string>>& ct)
{
  for (std::vector<std::string>& v : ct) {
    for (std::size_t i = 0; i < v.size(); i++) {
      std::cout << v.at(i);
      if (i < v.size() - 1) {
        std::cout << ",";
      }
    }
    std::cout << std::endl;
  }
}
 
void write_csv(std::vector<std::vector<std::string>>& ct,
               const std::string& filename)
{
  std::ofstream ofs(filename);
 
  for (std::vector<std::string>& v : ct) {
    for (std::size_t i = 0; i < v.size(); i++) {
      ofs << v.at(i);
      
      // if col2 is zero skip row
      if (v.at(1) == "0") break;
      if (i < v.size() - 1) {
        ofs << ",";
      }
    }
    ofs << std::endl;
  }
}