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
      if (i < v.size() - 1) {
        ofs << ",";
      }
    }
    ofs << std::endl;
  }
}
 
int main(int argc, char* argv[])
{
  std::vector<std::vector<std::string>> ct;
 
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [read_csv_file] [write_csv_file]"
              << std::endl;
    return 1;
  }
 
  std::string in_csv = argv[1];
  std::string out_csv = argv[2];
 
  if (in_csv == out_csv) {
    std::cerr << "Error: same read/write csv files." << std::endl;
    return 2;
  }
 
  read_csv(ct, in_csv);
  print_csv(ct);
  write_csv(ct, out_csv);
 
  return 0;
}