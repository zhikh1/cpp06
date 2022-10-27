/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nomargen <nomargen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:36:16 by nomargen          #+#    #+#             */
/*   Updated: 2022/10/25 21:01:55 by nomargen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <stdint.h>
#include "structs.h"

uintptr_t	serialize(Data *ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}

int	main( void ){
	Data		*etalon_data = new Data;
	Data		*ser_data;
	uintptr_t	tmp;

	etalon_data->data = "Etalon Data content";

	std::cout << "Data before serialization = " << etalon_data->data << std::endl;
	tmp = serialize(etalon_data);
	ser_data = deserialize(tmp);
	std::cout << "Data after  serialization = " << ser_data->data << std::endl;
}
