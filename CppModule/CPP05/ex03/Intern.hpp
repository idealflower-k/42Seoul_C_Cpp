#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class Bureaucrat;

class Intern {
 private:
 public:
  Intern();
  Intern(const Intern& origin);
  Intern& operator=(const Intern& origin);

  class HaveNotForm : public std::exception {
   public:
    const char* what() const throw();
  };

  AForm* makeForm(std::string form, std::string target);

  ~Intern();
};

#endif
