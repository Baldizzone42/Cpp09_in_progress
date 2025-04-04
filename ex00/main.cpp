/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:54:08 by jormoral          #+#    #+#             */
/*   Updated: 2025/04/04 22:48:52 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void BitcoinExchange::readcsv(BitcoinExchange &store)
{
	std::ifstream csv("data.csv");
	if(!csv.is_open()){
		std::cerr << "Error opening file\n"; exit (1);}
	std::getline(csv, store.str, '\n');
	while(std::getline(csv, store.str, '\n'))
	{
		size_t start = 0;
		size_t dlt = store.str.find(',');
		size_t end = store.str.find('\n');
		std::string date = store.str.substr(start, dlt - start);
		std::string value = store.str.substr(dlt + 1, end - 1);
		store.csv[date] = atof(value.c_str());
		//std::strof()
	}
	for (std::map<std::string, float>::iterator it = store.csv.begin(); it != store.csv.end(); ++it) {    
		std::cout << "Fecha: " << it->first << " Valor: " << it->second << std::endl;
	}

}


int main(int argc, char **argv)
{
	if(argc != 2)
	{
		std::cerr << "Error: could not open file.\n";
		return 1;
	}
	(void)argv;
	BitcoinExchange store;
	store.readcsv(store);
	return 0;
}