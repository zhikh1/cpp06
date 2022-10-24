/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 21:29:45 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/24 22:03:49 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ShrubberyCreationForm.h"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : Form( "ShrubberyCreationForm", 145, 137 ), target( target ) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other ) : Form( other ), target( other.target ) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( ShrubberyCreationForm& other ) {
    (void)other;
    return *this;
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
    if ( this->getSigned() == false )
        throw Form::NotSignedException();
    else if ( executor.getGrade() > this->getGradeToExecute() ) {
        throw Form::GradeTooLowException();
    }

    std::string name_str(this->getName() + "_shrubbery");
    char name_ch[name_str.length() + 1];
    strcpy(name_ch, name_str.c_str());
    std::ofstream fout( name_ch );

    fout << "    ____________ ¶¶¶_______¶¶¶¶" << std::endl;
    fout << "__________¶¶¶¶¶¶¶¶¶¶__¶¶¶¶¶¶" << std::endl;
    fout << "_________ ¶¶____¶¶¶¶__¶¶__¶¶¶" << std::endl;
    fout << "_________¶¶¶¶¶¶¶___¶¶¶¶¶____¶¶¶¶¶¶¶¶¶¶¶¶¶¶" << std::endl;
    fout << "________¶¶__¶¶¶_____¶¶¶________¶_¶____¶¶¶¶¶" << std::endl;
    fout << "________¶¶_________________¶¶¶¶¶___¶¶¶¶¶__¶" << std::endl;
    fout << "________¶¶__________________¶¶¶¶___¶¶¶¶___¶" << std::endl;
    fout << "______¶__ ¶_________________¶¶¶___________¶¶" << std::endl;
    fout << "_____¶¶_¶¶¶_______________________________¶¶¶" << std::endl;
    fout << "_¶¶¶¶¶¶¶¶¶_________¶____________________¶__¶¶" << std::endl;
    fout << "¶¶¶¶___¶¶______¶¶¶¶¶______¶_¶¶¶_________¶¶¶¶¶¶¶" << std::endl;
    fout << "¶¶_______________¶¶_______¶¶¶¶______________¶¶¶¶" << std::endl;
    fout << "¶¶¶________________________¶¶_________________¶¶" << std::endl;
    fout << "_¶¶¶ _________________¶¶__________________¶____¶¶" << std::endl;
    fout << "__¶¶ _____¶________¶¶¶¶¶_______________¶¶¶¶¶___¶¶" << std::endl;
    fout << "__¶¶ __¶¶¶¶_________¶¶¶¶________________¶¶¶¶____¶¶" << std::endl;
    fout << "_¶¶___¶¶¶¶¶______________________________¶¶_____¶¶" << std::endl;
    fout << "¶¶¶_____¶¶_____¶¶¶_¶¶¶¶¶¶_¶¶¶¶_¶¶¶___¶¶________¶¶¶" << std::endl;
    fout << "¶¶ ______________¶_¶___¶¶__¶_¶_¶¶¶¶¶¶¶¶_______¶¶¶¶" << std::endl;
    fout << "¶¶¶_____¶¶¶¶¶¶¶¶___¶¶___¶_¶¶¶_¶¶_¶¶¶¶¶______¶¶¶¶" << std::endl;
    fout << "_¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶¶__¶¶__¶_¶¶¶¶¶____¶¶¶¶¶¶¶¶¶¶¶" << std::endl;
    fout << "___¶¶¶¶________¶¶¶¶¶_¶¶¶¶___¶¶______¶¶¶¶¶¶¶¶" << std::endl;
    fout << "_________________¶¶¶__¶¶¶_¶¶¶" << std::endl;
    fout << "__________________¶¶______¶¶" << std::endl;
    fout << "__________________¶¶__¶¶__¶¶¶¶¶¶¶¶¶¶" << std::endl;
    fout << "______________ ¶¶¶¶¶_¶¶¶¶_¶¶¶¶_¶¶¶¶¶¶¶¶" << std::endl;
    fout << "__________¶¶¶¶¶¶¶¶¶__¶¶___¶________¶¶¶¶¶¶¶¶¶¶" << std::endl;
    fout << "__¶¶¶¶¶¶¶¶¶¶¶¶ ___¶¶__¶___¶____________¶¶¶¶¶¶¶¶¶¶" << std::endl;
    fout << "¶¶¶¶¶¶¶¶¶¶_______¶¶¶______¶______________________" << std::endl;
    fout << "________________ ¶¶_______¶¶_____________________" << std::endl;
    fout << "________________¶¶________¶¶¶____________________" << std::endl;
    fout << "______________¶¶¶__¶¶¶¶__¶¶_¶J¶__________________" << std::endl;
    fout << "______________¶¶__¶¶__¶¶__¶__¶K¶________________" << std::endl;
    fout << "____________ ¶¶__¶¶____¶¶_¶___¶¶_________________" << std::endl;
    fout.close();
}
