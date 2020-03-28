/*
** EPITECH PROJECT
** Created by mathieu on 12-03-20.
** File description:
** N/a
*/

#include "../includes/BlockHandler.hpp"
#include <ctime>
#include <unistd.h>
#include <iomanip>
#include <iostream>

BlockChain::BlockChain(std::string proof = "None") : _proofOfWork(proof), _id(0)
{
    time_t curr_time;
    tm * curr_tm;
    char date_str[100];

    time(&curr_time);
    curr_tm = localtime(&curr_time);

    strftime(date_str, 50, "%m:%d:%Y %T", curr_tm);
    _creationDate = date_str;
    //sleep(1);
};

void BlockChain::dump()
{
    BlockChain *n = this;
    int nbr = 0;

    std::cout << std::endl;
    for (; n != nullptr; n = n->get_next()) {
        std::cout <<
        "id:" << std::setw(8) << std::setfill('0') << n->get_id()
        << "       proofOfWork:" << std::setw(20) << std::setfill(' ') << n->get_proof()
        << "       Status:" << _accepted
        << "       Creation:" << _creationDate
                <<std::endl;
        nbr++;
    }
    std::cout << "Blocks accepted: " << nbr << std::endl;
}

bool BlockChain::addBlock(BlockChain *n)
{
    if (n->_proofOfWork != "None" && n->_proofOfWork[0] == 'n') {
        n->_prev = this;
        n->_id = this->get_id() + 1;
        _next = n;
        return true;
    } else
        std::cout << "Block " << n->_id << " was rejected with the proof \""
        << n->_proofOfWork << "\"." << std::endl;
    return false;
}

int BlockChain::get_id() const noexcept { return  _id;}

BlockChain *BlockChain::get_next() const noexcept { return _next;}

BlockChain *BlockChain::get_prev() const noexcept { return  _prev;}

std::string BlockChain::get_date() const noexcept { return _creationDate;}

std::string BlockChain::get_name() const noexcept { return _name;}

std::string BlockChain::get_proof() const noexcept { return _proofOfWork;}
