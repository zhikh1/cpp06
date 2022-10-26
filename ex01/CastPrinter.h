/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastPrinter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:05:33 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/25 21:53:44 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string>
#include <iostream>
#include <sstream>

enum NumType{
	ERR = 0,
	INT,
	FLOAT,
	DOUBLE
};

class CastPrinter
{
public:
	CastPrinter();
	CastPrinter( const CastPrinter& other );
	~CastPrinter();
	CastPrinter& operator=( const CastPrinter& other );

	int		toInt(std::string str, bool print_en = true);
	float	toFloat(std::string str);
	double	toDouble(std::string str);
	char	toChar(std::string str);

private:
	NumType getNumType(const std::string &str);
	NumType	getNanInfType(const std::string &str);
};
