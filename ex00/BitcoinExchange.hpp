/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:10:23 by jormoral          #+#    #+#             */
/*   Updated: 2025/04/05 20:03:37 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
#include <sstream>
#include <string>

class BitcoinExchange
{
	private:
		std::string str;
		std::map<std::string, float>csv;
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange& operator=(const BitcoinExchange &other);
		void readcsv(BitcoinExchange &store);

		void parse_input(char *s1, BitcoinExchange &store);
};




#endif