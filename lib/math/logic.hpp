#ifndef _LOGIC_HPP_
#define _LOGIC_HPP_

/**
 * @brief Negation
*/
#define NOT(A) !A

/**
 * @brief Conjuction
*/
#define AND(A, B) (A && B)

/**
 * @brief Disjunction
*/
#define OR(A, B) (A || B)

/**
 * @brief Negated conjuction
*/
#define NAND(A, B) NOT(AND(A, B))

/**
 * @brief Negated disjunction
*/
#define NOR(A, B) NOT(OR(A, B))

/**
 * @brief Exclusive disjunction
*/
#define XOR(A, B) OR(AND(A, NOT(B)), AND(NOT(A), B))

/**
 * @brief Negated exclusive disjunction
*/
#define XNOR(A, B) NOT(XOR(A, B))

/**
 * @brief Implication
*/
#define IMPLY(A, B) OR(NOT(A), B)

/**
 * @brief Negated implication
*/
#define NIMPLY(A, B) NOT(IMPLY(A, B))

/**
 * @brief Equivalence
*/
#define EQUI(A, B) (A == B)

/**
 * @brief Negated equivalence
*/
#define NEQUI(A, B) (A != B)

#endif // _LOGIC_HPP_