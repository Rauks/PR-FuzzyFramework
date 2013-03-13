/* 
 * File:   ThenMin.h
 * Author: Karl
 *
 * Created on 13 mars 2013, 11:02
 */

#ifndef THENMIN_H
#define	THENMIN_H

#include "Then.h"

namespace fuzzy{
    template<class T>
    class ThenMin : public Then{
    public:
        virtual T evaluate(core::Expression<T>* left, core::Expression<T>* right);
    };
    
    template<class T>
    T evaluate(core::Expression<T>* left, core::Expression<T>* right){
        T lt = left->evaluate();
        T rt = right->evaluate();
        return (lt < rt)?lt:rt;
    }
}

#endif	/* THENMIN_H */
