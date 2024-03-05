#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>

#include "AForm.hpp"
#define SCF_SIGN 145
#define SCF_EXEC 137

class AForm;
class Bureaucrat;

class ShrubberyCreationForm : public AForm {
 private:
  ShrubberyCreationForm();

 public:
  ShrubberyCreationForm(std::string target);
  ShrubberyCreationForm(const ShrubberyCreationForm& origin);

  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& origin);

  void execute(Bureaucrat const& executor) const;

  ~ShrubberyCreationForm();
};

#endif
