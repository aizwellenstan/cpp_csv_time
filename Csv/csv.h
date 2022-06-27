#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void read_csv(std::vector<std::vector<std::string>>& ct,
              const std::string& filename);

void print_csv(std::vector<std::vector<std::string>>& ct);

void write_csv(std::vector<std::vector<std::string>>& ct,
               const std::string& filename);