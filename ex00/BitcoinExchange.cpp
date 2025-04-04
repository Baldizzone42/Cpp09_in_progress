/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 19:20:18 by jormoral          #+#    #+#             */
/*   Updated: 2025/04/04 19:39:06 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	std::cout << "Default constructor" << std::endl;
}

BitcoinExchange::~BitcoinExchange(){
	std::cout << "Destructor" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	//Por completar..
	(void)copy;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &other)
{
	//por completar;
	(void)other;
	return *this;
}