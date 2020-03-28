/*
** EPITECH PROJECT
** Created by mathieu on 12-03-20.
** File description:
** N/a
*/

#include "../includes/BlockHandler.hpp"
#include "../includes/exception.hpp"
#include <iostream>

void insert_blocks(BlockChain *parent, int nbr)
{
    BlockChain *save = parent;
    for (int i = 0; i < nbr; i++) {
        parent->addBlock(new BlockChain(std::to_string(i)));
        parent = parent->get_next();
    }
    parent = save;
}

int main ()
{
    BlockChain *parent = new BlockChain("test");

    insert_blocks(parent, 3);

    for (; parent != nullptr; parent = parent->get_next())
        std::cout << parent->get_name() << std::endl;
    return SUCCES;
}