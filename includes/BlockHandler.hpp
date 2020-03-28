/*
** EPITECH PROJECT
** Created by mathieu on 12-03-20.
** File description:
** N/a
*/

#ifndef TEMPLATE_MACROS_HPP
#define TEMPLATE_MACROS_HPP

#define ERROR 84
#define SUCCES 0

#include <iostream>

class BlockChain {
    public:
        BlockChain(std::string name = "Default") : _name(name){};
        ~BlockChain() {};
        void addBlock(BlockChain *n);
        BlockChain *get_next() const noexcept;
        BlockChain *get_prev() const noexcept;
        std::string get_name() const noexcept;
        std::string get_proof() const noexcept;
    private:
        std::string _name;
        std::string _proofOfWork;
        BlockChain *_next = nullptr;
        BlockChain *_prev = nullptr;
};

#endif //TEMPLATE_MACROS_HPP
