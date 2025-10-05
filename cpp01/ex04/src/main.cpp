/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kosakats <kosakats@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 12:48:29 by kosakats          #+#    #+#             */
/*   Updated: 2025/10/05 18:20:38 by kosakats         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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
    if (!ifs)
    {
        std::cout << "error3\n";
        return;
    }

    std::ostringstream buffer;
    buffer << ifs.rdbuf();
    std::string content = buffer.str();

    std::string replaced = replaceAll(content, s1, s2);

    std::string newFile = filename + ".replace";
    std::ofstream ofs(newFile.c_str());
    if (!ofs)
    {
        std::cout << "error3\n";
        return;
    }

    ofs << replaced;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Usage: ./program filename s1 s2\n";
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    if (s1.empty())
    {
        std::cout << "error2\n";
        return 1;
    }

    processFile(filename, s1, s2);
    return 0;
}

