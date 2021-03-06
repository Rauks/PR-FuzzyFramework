/* 
 * File:   SugenoDefuzzCondition.h
 * Author: Karl
 *
 * Created on 8 avril 2013, 16:51
 */

#ifndef SUGENODEFUZZCONCLUSION_H
#define	SUGENODEFUZZCONCLUSION_H

#include <stdexcept>
#include <vector>

#include "../core/Expression.h"
#include "../core/NaryExpression.h"
#include "ThenSugeno.h"

namespace fuzzy{
    template<class T>
    class SugenoDefuzzConclusion : public core::NaryExpression<T>{
    private:
        typedef typename std::vector<core::Expression<T>*>::const_iterator const_iterator;
        typedef typename std::vector<core::Expression<T>*>::iterator iterator;
        typedef typename std::vector<T>::const_iterator const_coeffs_iterator;
        typedef typename std::vector<T>::iterator coeffs_iterator;
        const std::vector<T>* _coeff;
    public:
        SugenoDefuzzConclusion(const std::vector<T>* coeff);
        SugenoDefuzzConclusion(const SugenoDefuzzConclusion<T>& o);
        virtual ~SugenoDefuzzConclusion();
        virtual T evaluate(std::vector<core::Expression<T>*>* operands) const;
    };
    
    template<class T>
    SugenoDefuzzConclusion<T>::SugenoDefuzzConclusion(const std::vector<T>* coeff)
    :_coeff(coeff){
    }
    
    template<class T>
    SugenoDefuzzConclusion<T>::SugenoDefuzzConclusion(const SugenoDefuzzConclusion<T>& o)
    :_coeff(o._coeff){
    }
    
    template<class T>
    SugenoDefuzzConclusion<T>::~SugenoDefuzzConclusion(){
    }
    
    /**
     * @param values Vector of inputs Sugeno values.
     * @return Sum of the Sugeno values and conclusion coefiscients
     */
    template<class T>
    T SugenoDefuzzConclusion<T>::evaluate(std::vector<core::Expression<T>*>* values) const{
        const_coeffs_iterator coeffIt = _coeff->begin();
        const_iterator valuesIt = values->begin();
        
        T result = 0;
        while(coeffIt != _coeff->end() && valuesIt != values->end()){
            result += (*coeffIt) * (*valuesIt)->evaluate();
            coeffIt++;
            valuesIt++;
        }
        
        return result;
    }
}

#endif	/* SUGENODEFUZZCONCLUSION_H */

