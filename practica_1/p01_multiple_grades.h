#include <iostream>
#include <map>

class MultipleGrades {
  public:
    MultipleGrades() {}
    MultipleGrades(std::string alu, double grade) : students_{{alu, grade}} {}
    
    bool Search (std::string alu) {
      auto aux = this->students_.find(alu);
      if (aux != this->students_.end()) {
        return true;
      }
      return false;
    }
    void Add(std::string alu, double grade) {
      if (!Search(alu)) {
        this->students_.insert(std::make_pair(alu, grade));
      } else {
        auto aux = this->students_.find(alu);
        if (grade > aux->second) { aux->second = grade; }
      }
    }
    friend std::ostream& operator<<(std::ostream& os, const MultipleGrades& multiple) {
      std::string previous_alu;
      for (const auto& pair : multiple.students_) {
        if (pair.first != previous_alu) {
          os << "alu" << pair.first << ": " << pair.second << std::endl;  
        }
      }
      return os;
    }

  private:
    std::multimap<std::string, double> students_;
};