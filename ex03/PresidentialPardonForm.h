#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "Form.h"

class PresidentialPardonForm : public Form
{
public:
    PresidentialPardonForm( const std::string& target );
    PresidentialPardonForm( const PresidentialPardonForm& other );
    ~PresidentialPardonForm();

    PresidentialPardonForm& operator=( const PresidentialPardonForm& other );
    
    void execute( const Bureaucrat& executor ) const;

private:
    std::string target;

    PresidentialPardonForm();
};

#endif
