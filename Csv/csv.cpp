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
  int startTime = 0;
  int time;
  int nhour,nmin,nsec;
  for (std::vector<std::string>& v : ct) {
    for (std::size_t i = 0; i < v.size(); i++) {
      // if col2 is zero skip row
      if (v.at(1) == "0") break;

      if (i==0 && v.at(0) != "Timecode") {
        int hour,min,sec;
        std::stringstream sstrm;
        sstrm << v.at(0);

        sstrm >> hour;
        sstrm.get(); // get colon
        sstrm >> min;
        sstrm.get(); // get colon
        sstrm >> sec;
        sstrm.get(); // get colon

        // std::cout << hour << std::endl;
        // std::cout << min << std::endl;
        // std::cout << sec << std::endl

        time = hour*60*60+min*60+sec;
        if (startTime == 0) startTime = time;
        sec = time - startTime;
        int h, m, s;
        
        h = (sec/3600); 
        
        m = (sec -(3600*h))/60;
        
        s = (sec -(3600*h)-(m*60));
        
        // printf("H:M:S - %d:%d:%d\n",h,m,s);
        // std::cout << startTime << std::endl;

        std::string frame = v.at(0).substr(v.at(0).size() - 7);
        std::ostringstream newTime;
        newTime << h << ":" << m << ":" << s << frame;
        v.at(0) = newTime.str();
        std::cout << newTime.str() << std::endl;
      }
      

      ofs << v.at(i);
      // std::cout << v.at(0);

      

      if (i < v.size() - 1) {
        ofs << ",";
      }
    }
    ofs << std::endl;
  }
}