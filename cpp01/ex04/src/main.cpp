/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:48:29 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/04 10:54:05 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

bool isSpaces(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!isspace(str[i]))
            return false;
    }
    return true;
}
#include <iostream>
#include <string>

std::string replaceAll(const std::string &text, const std::string &s1, const std::string &s2)
{
    if (s1.empty())
        return text;

    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = text.find(s1, pos)) != std::string::npos)
    {
        result.append(text.substr(pos, found - pos));
        result.append(s2);
        pos = found + s1.length();
    }

    result.append(text.substr(pos));

    return result;
}


void processFile(const std::string &filename, const std::string &s1, const std::string &s2) 
{
    std::ifstream ifs(filename.c_str());
    std::string newFile = filename + ".replace";
    std::ofstream ofs(newFile.c_str());

    if (!ifs || !ofs) {
        std::cout << "error3\n";
        return;
    }
    std::string line;
    while (std::getline(ifs, line)) 
	{
		std::cout << line << std::endl;
        std::string replaced = replaceAll(line, s1, s2);
        ofs << replaced << "\n";
    }
}


int main(int ac, char **av) 
{

	if(ac != 4)
	{
		std::cout << "Usage: ./program filename s1 s2\n"; 
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	
	if(isSpaces(filename) || isSpaces(s1))
	{
		std::cout << "error2\n"; 
		return 1;
	}
	processFile(filename, s1, s2);

	return 0;
}
