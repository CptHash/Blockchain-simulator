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
#include <vector>

enum speak {
    TALK,
    SILENCE
};

class Data {
    public:
        Data();
        ~Data();
        std::vector<std::string> get_transactions() const;
    private:
        std::vector<std::string> transactions; //Crypted by private keys

};

class BlockChain {
    public:
        BlockChain(std::string proof);
        ~BlockChain() {};
        bool addBlock(BlockChain *n, speak);
        BlockChain *get_next() const noexcept;
        BlockChain *get_prev() const noexcept;
        std::string get_name() const noexcept;
        int get_id() const noexcept;
        std::string get_proof() const noexcept;
        std::string get_sha256() const noexcept;
        std::string get_date() const noexcept;
        void dump();
    private:
        int _id;
        std::string _name;
        std::string _creationDate;
        std::string _proofOfWork = "None";
        std::string _sha256;
        BlockChain *_next = nullptr;
        BlockChain *_prev = nullptr;
};

#endif //TEMPLATE_MACROS_HPP
