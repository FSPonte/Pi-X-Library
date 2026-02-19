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

/**
 * @brief Less than
*/
#define LESSER(A, B) (A < B)

/**
 * @brief Greater than
*/
#define GREATER(A, B) (A > B)

/**
 * @brief Less than or equal to
*/
#define LESS_EQUI(A, B) (A <= B)

/**
 * @brief Greater than or equal to
*/
#define GREATER_EQUI(A, B) (A >= B)

/**
 * @brief Bitwise negation
*/
#define BIT_NOT(A) ~A

/**
 * @brief Bitwise conjuction
*/
#define BIT_AND(A, B) (A & B)

/**
 * @brief Bitwise disjunction
*/
#define BIT_OR(A, B) (A | B)

/**
 * @brief Bitwise negated conjuction
*/
#define BIT_NAND(A, B) BIT_NOT(BIT_AND(A, B))

/**
 * @brief Bitwise negated disjunction
*/
#define BIT_NOR(A, B) BIT_NOT(BIT_OR(A, B))

/**
 * @brief Bitwise exclusive disjunction
*/
#define BIT_XOR(A, B) (A ^ B)

/**
 * @brief Bitwise negated exclusive disjunction
*/
#define BIT_XNOR(A, B) BIT_NOT(BIT_XOR(A, B))

/**
 * @brief Left shift
*/
#define LEFT_SHIFT(A, B) (A << B)

/**
 * @brief Right shift
*/
#define RIGHT_SHIFT(A, B) (A >> B)

#endif // _LOGIC_HPP_