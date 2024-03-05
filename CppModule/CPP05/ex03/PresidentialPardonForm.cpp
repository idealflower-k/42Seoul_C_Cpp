#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm(target, PPF_SIGN, PPF_EXEC) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm& origin)
    : AForm(origin) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(
    const PresidentialPardonForm& origin) {
  if (this != &origin) AForm::operator=(origin);
  return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
  try {
    this->validExec(executor);
    std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox\n";
  } catch (std::exception& e) {
    throw;
  }
}

PresidentialPardonForm::~PresidentialPardonForm() {
  std::cout << this->getName()
            << " [PresidentialPardonForm] Destructor called\n";
}
