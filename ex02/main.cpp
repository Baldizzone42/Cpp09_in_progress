/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:52:14 by jormoral          #+#    #+#             */
/*   Updated: 2025/04/12 22:04:12 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"




int* fusion_array(int *a, int *b, size_t npairs)
{
	int *temp = new int[npairs * 2];
	size_t i = 0;
	size_t j = 0;
	while(i < npairs)
	{
		temp[j] = a[i];
		i++;
		j++;
	}
	i = 0;
	while(i < npairs)
	{
		temp[j] = b[i];
		i++;
		j++;
	}
	return temp;
}


PmergeMe* fusion_list(PmergeMe *merge, size_t npairs)
{
	PmergeMe *result = new PmergeMe;
	std::list<int*>::iterator it = merge->Og.begin();
	std::list<int *>::iterator itsecond =merge->Og.begin();
	std::list<int*>::iterator itend = merge->Og.end();
	std::list<int*>tactico;
	itsecond++;
	while(it != itend)
	{
		if(itsecond != itend)
		{ /// arreglar por que da tamaño 4 a todos los nodos cuando es posible que uno solo tenga 2 ints
			int *temp = new int[npairs];
			temp = fusion_array((*it), (*itsecond), npairs);
			tactico.push_back(temp);
			
			it++;
			itsecond++;
		}
		if(itsecond == itend && merge->Og.size() % 2 != 0)
		{
			tactico.push_back((*it));
			break;
		}
		if(itsecond == itend)
			break;
		it++;
		itsecond++;
	}
	merge->Og.clear();
	result->Og = tactico;
	
	return result;
}

bool max_n(std::list<int*>::iterator it, std::list<int *>::iterator itsecond)
{
	int itmax = 0;
	int itsecondmax = 0;
	int i = 0;
	int j = 0;
	while((*it)[i])
	{
		if(itmax < (*it)[i])
			itmax = (*it)[i];
		i++;
	}
	while((*itsecond)[j])
	{
		if(itsecondmax < (*itsecond)[j])
			itsecondmax = (*itsecond)[j];
		j++;
	}
	if(itmax > itsecondmax && i == j)
			return true;
	return false;
}


void sort(PmergeMe *merge, size_t npairs)
{ 	
	//max_n(it, itsecond)
	std::list<int*>::iterator it = merge->Og.begin();
	std::list<int*>::iterator itsecond = merge->Og.begin();
	std::list<int*>::iterator itend = merge->Og.end();
	while(itsecond != itend)
	{
		itsecond++;
		if(itsecond != itend && (*it)[npairs - 1] > (*itsecond)[npairs - 1])
		{
			int *temp = (*it);
			(*it) = (*itsecond);
			(*itsecond) = temp;
		}
		else if(itsecond == itend)
			break;
		it++,it++;
		itsecond++;
	}
}

void print_sort(PmergeMe *merge, int npairs)
{
		std::list<int*>::iterator it = merge->Og.begin();
		std::list<int*>::iterator itsecond = merge->Og.begin();
		itsecond++;
		std::list<int*>::iterator e = merge->Og.end();
		size_t n = 0;
		while(it != e)
		{
			int i = 0;
			std::cout << "[ ";
			while(i < npairs)
			{
				if(!(*it)[i] && itsecond == e) 
					break;
				std::cout << (*it)[i] << " ";
				i++;
			}
			n++;
			it++;
			itsecond++;
			std::cout << "]";
		}
		/* if(n >= (merge->Og.size())  && n % 2 != 0)
				print_sort(merge + n, 1);
		else */
			std::cout << std::endl;
}

int main(int argc, char **argv)
{
	std::list<std::string>split;
	PmergeMe *merge = new PmergeMe();
	if(argc == 1)
		return 1;
	int i = 1;
	while(argv[i])
	{
		std::string arg = argv[i];
		int *temp = new int[1];
		temp[0] = atoi(arg.c_str());
		merge->Og.push_back(temp);
		i++;
	}
	size_t size_merge = merge->Og.size();
	size_t npairs = 1;
	int level = 0;
	while(size_merge >= npairs)
	{
		level++;
		std::cout << "Sequence after sorting " << level << std::endl;
		sort(merge, npairs);
		print_sort(merge, npairs);
		merge = fusion_list(merge, npairs);
		npairs = npairs * 2;
		std::cout << "Fusion " << level << std::endl;
		print_sort(merge, npairs);
		size_merge = merge->Og.size();
		/* std::cout <<"Tamaño total merge: " << size_merge << std::endl;
		std::cout << "Npairs: " << npairs << std::endl; */
	}
	return 0;
	
}
