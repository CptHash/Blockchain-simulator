/*
** EPITECH PROJECT
** Created by mathieu on 12-03-20.
** File description:
** N/a
*/

#include "../includes/BlockHandler.hpp"
#include "../includes/exception.hpp"
#include <iomanip>
#include <vector>
#include <fstream>
#include <iostream>

void insert_blocks(BlockChain *parent, std::vector<std::string> work)
{
    BlockChain *save = parent;
    bool status;

    for (auto &elem: work) {
        status = parent->addBlock(new BlockChain(elem));
        if (status == true)
            parent = parent->get_next();
    }
    parent = save;
}

void take_work(std::string path, BlockChain *head)
{
    std::string line;
    std::ifstream myfile(path);
    std::vector<std::string> work;
    if (myfile.is_open()) {
        while (!myfile.eof()) {
            getline(myfile, line);
            work.push_back(line);
        }
        myfile.close();
        insert_blocks(head, work);
    } else
        std::cout << "Unable to open file" << std::endl;
}

int main (int ac, char **av)
{
    BlockChain *head = new BlockChain("Head");

    if (ac == 2) {
        take_work(av[1], head);
        head->dump();
    }
    return SUCCES;
}