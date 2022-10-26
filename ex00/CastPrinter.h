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

	int		toInt(const std::string &str);
	float	toFloat(const std::string &str);
	double	toDouble(const std::string &str);
	char	toChar(const std::string &str);

private:
	NumType isCorrectNum(const std::string &str);
	NumType	isNanInf(const std::string &str);
};
