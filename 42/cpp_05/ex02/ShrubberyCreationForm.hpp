#ifndef SHRUB__
#define SHRUB__

#include "./AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target;
    public:
        ShrubberyCreationForm();
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& f);

        ShrubberyCreationForm(std::string target);
		void	execute(Bureaucrat const & executor) const;
        
};

#endif
