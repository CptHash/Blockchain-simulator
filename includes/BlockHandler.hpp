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
        BlockChain(std::string proof);
        ~BlockChain() {};
        bool addBlock(BlockChain *n);
        BlockChain *get_next() const noexcept;
        BlockChain *get_prev() const noexcept;
        std::string get_name() const noexcept;
        int get_id() const noexcept;
        std::string get_proof() const noexcept;
        std::string get_date() const noexcept;
        void dump();
    private:
        int _id;
        bool _accepted = false;
        std::string _name;
        std::string _creationDate;
        std::string _proofOfWork = "None";
        BlockChain *_next = nullptr;
        BlockChain *_prev = nullptr;
};

#endif //TEMPLATE_MACROS_HPP
