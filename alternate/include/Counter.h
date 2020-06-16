//
// Created by Maurik Holtrop on 6/15/20.
//
/*
 * Simple class to facilitate counting of cuts with the ability to store the counts in the output file.
 */

#ifndef HPSTR_COUNTER_H
#define HPSTR_COUNTER_H

#include "TObject.h"
#include <iostream>
#include <iomanip>

class Counter : public TObject {

public:
    int pass;
    int fail;
    std::string name;

public:
    Counter(std::string n="test"){
        pass=0;
        fail=0;
        name = n;
    }
    Counter(Counter *c){
        pass= c->pass;
        fail= c->fail;
        name= c->name;
    }

    ~Counter(){};
    bool Test(bool t){ ///< Implements a Test(). Store a pass if true.
        if(t) pass++;
        else  fail++;
        return(t);
    }
    bool ATest(bool t){ ///< Implements an anti-Test, Store a pass if false.
        if(t) fail++;
        else  pass++;
        return(t);
    }

    void PrintOut(int num_evt) const{ ///< Print the number of passes and fails on one line, including a \% pass.

        std::cout << std::setw(25) << std::left << name << std::right
             << " pass: " << std::setw(6) << pass
             << " = " << std::fixed << std::showpoint << std::setprecision(4) << std::setw(8)
             << (100.*(double)pass)/(pass+fail)
             << "%  fail: " << std::setw(6) << fail
             << " = " << std::setw(8) << (100.*(double)fail)/(pass+fail);
        if(num_evt>0) std::cout << "% Overall: "<< std::setw(8) << 100.*(double)pass/num_evt <<"%" << std::endl;
        else std::cout << std::endl;
    }

    void Print(Option_t *options="") const{ ///< Print the number of passes and fails on one line.

        std::cout << std::setw(25) << std::left << name << std::right
             << " pass: " << std::setw(6) << pass
             << " = " << std::fixed << std::showpoint << std::setprecision(4) << std::setw(8)
             << (100.*(double)pass)/(pass+fail)
             << "%  fail: " << std::setw(6) << fail
             << " = " << std::setw(8) << (100.*(double)fail)/(pass+fail);
        std::cout << std::endl;
    }

    ClassDef(Counter,1);
};


#endif //HPSTR_COUNTER_H
