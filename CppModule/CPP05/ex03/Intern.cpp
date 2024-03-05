#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& origin) { (void)origin; }

Intern& Intern::operator=(const Intern& origin) {
  if (this != &origin) return (*this);
  return (*this);
}

AForm* Intern::makeForm(std::string form, std::string target) {
  AForm* res = NULL;
  std::string forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm",
                          "PresidentialPardonForm"};
  int idx = -1;

  while (idx < 3 && form.compare(forms[++idx])) {
  }

  switch (idx) {
    case 0:
      res = new ShrubberyCreationForm(target);
      break;
    case 1:
      res = new RobotomyRequestForm(target);
      break;
    case 2:
      res = new PresidentialPardonForm(target);
      break;
    default:
      throw Intern::HaveNotForm();
  }
  std::cout << "Intern creates " << form << "\n";
  return (res);
}

const char* Intern::HaveNotForm::what() const throw() {
  return ("Have Not Form\n");
}

Intern::~Intern() { std::cout << "[Intern] Destructor called\n"; }
