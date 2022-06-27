#include "csv.h"
 
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
  // print_csv(ct);
  write_csv(ct, out_csv);
 
  return 0;
}