#include "map.h"

#include <iostream>
#include <map>


// using namespace s21;

int main() {
  s21::map<int, std::string> my_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};
  std::map<int, std::string> std_map{
      std::make_pair(42, "foo"), std::make_pair(3, "bar"),
      std::make_pair(33, "aboba"), std::make_pair(3, "ba")};

  my_map.insert_or_assign(1,"one");
  std_map.insert_or_assign(1,"one");
  my_map.insert_or_assign(2,"two");
  std_map.insert_or_assign(2,"two");
  my_map.insert_or_assign(22,"twotwo");
  std_map.insert_or_assign(22,"twotwo");
  my_map.insert_or_assign(-22,"-twotwo");
  std_map.insert_or_assign(-22,"-twotwo");
  my_map.insert_or_assign(22,"three");
  std_map.insert_or_assign(22,"three");
  my_map.insert_or_assign(22234,"two3two");
  std_map.insert_or_assign(22234,"two3two");
  my_map.insert_or_assign(12,"onetwo");
  std_map.insert_or_assign(12,"onetwo");
  my_map.insert_or_assign(-12,"-onetwo");
  std_map.insert_or_assign(-12,"-onetwo");
  
  auto my_iter = my_map.begin();
  auto std_iter = std_map.begin();

  while (std_iter != std_map.end()) {
    std::cout << (*my_iter).first << " = " << (*std_iter).first << std::endl;
    std::cout << (*my_iter).second << " = " << (*std_iter).second << std::endl;
    ++my_iter;
    ++std_iter;
  }
}
