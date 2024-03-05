#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

#define PPF_SIGN 25
#define PPF_EXEC 5

class AForm;
class Bureaucrat;

class PresidentialPardonForm : public AForm {
 private:
  PresidentialPardonForm();

 public:
  PresidentialPardonForm(std::string target);
  PresidentialPardonForm(const PresidentialPardonForm& origin);

  PresidentialPardonForm& operator=(const PresidentialPardonForm& origin);

  void execute(Bureaucrat const& executor) const;

  ~PresidentialPardonForm();
};

#endif
