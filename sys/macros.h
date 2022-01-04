/*
******************************************************************************
** Header file for common used macros
******************************************************************************
*/

#ifndef _MACROS_H_
#define _MACROS_H_



#ifndef TO
#define TO        this_object()
#endif

#ifndef TP
#define TP        this_player()
#endif

#ifndef TI
#define TI        this_interactive()
#endif

#ifndef PO
#define PO        previous_object()
#endif

#ifndef ENV
#define ENV(x)    environment(x)
#endif

#ifndef CAP
#define CAP(x)    capitalize(x)
#endif

#ifndef LOW
#define LOW(x)   lower_case(x)
#endif

#ifndef SF
#define SF(x)             #'x
#endif

#ifndef SYM
#define SYM(x)            'x
#endif

#define SF_COMBINE        #'
#define SF_ASSIGN         #'=
#define SF_EQUAL          #'==
#define SF_NEQUAL         #'!=
#define SF_INDEX          #'[
#define SF_INDEX_END      #'[<
#define SF_RANGE          #'[..]
#define SF_AND            #'&&
#define SF_OR             #'||
#define SF_BITWISE_AND    #'&
#define SF_BITWISE_OR     #'|
#define SF_NEGATE         #'!
#define SF_UNARY_NEGATE   #'negate
#define SF_ADD            #'+
#define SF_SUB            #'-

#define SF_IF             #'?
#define SF_IF_NOT         #'?!
#define SF_WHILE          #'while
#define SF_DO             #'do
#define SF_SWITCH         #'switch

#endif



