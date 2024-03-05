#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm(target, RRF_SIGN, RRF_SIGN) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origin)
    : AForm(origin) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(
    const RobotomyRequestForm& origin) {
  if (this != &origin) AForm::operator=(origin);
  return (*this);
}

static void _Robotomized(Bureaucrat const& executor) {
  int num = std::rand() % 2;

  std::cout << "Roughly drilling sound...!! >> ";
  if (num)
    std::cout << executor.getName() << " has been robotomized success!!\n";
  else
    std::cout << executor.getName() << " has been robotomized fail..\n";
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
  try {
    this->validExec(executor);
    _Robotomized(executor);
  } catch (std::exception& e) {
    throw;
  }
}

RobotomyRequestForm::~RobotomyRequestForm() {
  std::cout << this->getName() << " [RobotomyRequestForm] Destructor called\n";
}
