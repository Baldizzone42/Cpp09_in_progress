/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 09:54:08 by jormoral          #+#    #+#             */
/*   Updated: 2025/04/06 20:55:38 by jormoral         ###   ########.fr       */
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
	}
	/* for (std::map<std::string, float>::iterator it = store.csv.begin(); it != store.csv.end(); ++it) {    
		std::cout << "Fecha: " << it->first << " Valor: " << it->second << std::endl;
	} */
}
int parse_date(std::string line)
{
	int n = 0;
	int under = 0;
	int i = 0;
	int pipe = 0;
	while(line[i] && line[i] != '|')
	{
		if((line[i] >= '0' && line[i] <= '9' ) || line[i] == '-')
		{
			if(line[i] == '-')
				under++;
			else
				n++;			
		}
		i++;
	}
	if(line[i] == '|')
			pipe++;
	if(n == 8 && under == 2 && pipe == 1)
		return 0;
	return(std::cout << "Error: Bad date\n"), 1;
}

bool isdigit(char c)
{
	if(c >= '0' && c <= '9')
		return true;
	return false;
}

int parse_amount(std::string line)
{
	std::string amount = line.substr(13 , line.size());
	int dot = 0;
	for(int i = 0; amount[i]; i++)
	{
		if(amount[i] == '.' && isdigit(amount[i + 1]) && isdigit(amount[i - 1]))
			i++,dot++;
		if(amount[i] < '0' || amount[i] > '9' || dot > 1)
			return (std::cout << "Error: Bad amount of bitcoins\n"), 1;
	}
	float n = atof(amount.c_str());
	if(n > 1000 || n <= 0)
		return(std::cout << "Error: Bad amount of bitcoins\n"), 1;
	return 0;
}

void BitcoinExchange::parse_line(std::string line)
{
	int famount = -1;
	int fdate = parse_date(line);
	if(!fdate)
		famount = parse_amount(line);
	std::string *date = new std::string[4];
	if(!fdate && !famount)
	{	
		date[0] = line.substr(0, 4);
		date[1] = line.substr(5, 2);
		date[2] = line.substr(8, 2);
		date[3] = line.substr(13, line.size());
		//mas parseo de fecha se viene
		
		std::cout << "Year:" << date[0];
		std::cout << " Monthl:" << date[1];
		std::cout << " Day:" << date[2];
		std::cout << " Value:" << date[3] << std::endl;
	}
	delete []date;
}

void BitcoinExchange::parse_input(char *s1, BitcoinExchange &store)
{
	std::ifstream input(s1);
	std::string infile;
	(void)store;
	int i = 0;
	while(std::getline(input, infile, '\n'))
	{
		if(infile == "date | value" && i == 0)
			continue;
		else
			store.parse_line(infile);
		i++;
	}
}
//if(infile.empty())
			//std::cout << infile << std::endl;

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
	store.parse_input(argv[1], store);
	
	return 0;
}