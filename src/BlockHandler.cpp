/*
** EPITECH PROJECT
** Created by mathieu on 12-03-20.
** File description:
** N/a
*/

#include "../includes/BlockHandler.hpp"
#include <iostream>

void BlockChain::addBlock(BlockChain *n) {
    _next = n;
    n->_prev = this;
}

BlockChain *BlockChain::get_next() const noexcept { return _next;}

BlockChain *BlockChain::get_prev() const noexcept { return  _prev;}

std::string BlockChain::get_name() const noexcept { return _name;}

std::string BlockChain::get_proof() const noexcept { return _proofOfWork;}
