//
// Created by Maurik Holtrop on 6/14/20.
//

#ifndef HPSTR_BASEANA_H
#define HPSTR_BASEANA_H

#include <TObject.h>

class BaseAna : TObject{

    BaseAna(){};
    ~BaseAna(){};

public:
    int i;

ClassDef(BaseAna,1);
};


#endif //HPSTR_BASEANA_H
