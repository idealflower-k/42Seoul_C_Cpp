#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>

#include "AForm.hpp"

#define RRF_SIGN 72
#define RRF_EXEC 45

class Aform;
class Bureaucrat;

class RobotomyRequestForm : public AForm {
 private:
  RobotomyRequestForm();

 public:
  RobotomyRequestForm(std::string target);
  RobotomyRequestForm(const RobotomyRequestForm& origin);

  RobotomyRequestForm& operator=(const RobotomyRequestForm& origin);

  void execute(Bureaucrat const& executor) const;

  ~RobotomyRequestForm();
};

#endif
