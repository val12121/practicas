#include <map>
#include <iostream>

class SingleGrade {
  public:
    SingleGrade() : students_{} {}
    SingleGrade(std::string alu, double grade) : students_{{alu, grade}} {} 
    
    //Methods
    friend std::ostream& operator<<(std::ostream& os, const SingleGrade& single) {
      for (const auto& pair : single.students_) {
        os << "alu" << pair.first << ": " << pair.second << std::endl;  
      }
      return os;
    }
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

  private:
    std::map<std::string, double> students_;
};