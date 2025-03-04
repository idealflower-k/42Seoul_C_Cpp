#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

class Bureaucrat {
 private:
  const std::string name;
  int grade;
  void validGrade(int grade);
  Bureaucrat();

 public:
  class GradeTooHighException : public std::exception {
   public:
    const char* what() const throw();
  };
  class GradeTooLowException : public std::exception {
   public:
    const char* what() const throw();
  };

  Bureaucrat(std::string _name, int _grade);
  Bureaucrat(const Bureaucrat& origin);

  Bureaucrat& operator=(const Bureaucrat& origin);

  std::string getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();
  void signForm(AForm& form);
  void executeForm(AForm const& form);

  ~Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& bureaucrat);

#endif
