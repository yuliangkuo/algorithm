/*
 * 191. Number of 1 Bits 
 * https://leetcode.com/problems/number-of-1-bits/description/
 *
 Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

 For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
 */


/*
 *  Trivial way: given a variable 1 and shift left one by one and do '&' with n to increase counter.  
 *  Quick way: turn the least-signature 1 bit to become zero repeatedlly and do incerment until no zero.
 */

/**
 * @param n   The input n
 * @return    The number of 1 bits
 * */
int hammingWeight(uint32_t n) {

    // Trivial Way
    /*
    unsigned m = 1;
    int i, count = 0;
    
    for(i=0; i<32;i++) {
        if(m & n)
            count++;
        m = m << 1;
    }
    */    

    // Quick way
    int count = 1;
    uint32_t m = n;

    // Consider the case that there is only one 1
    if ( n == 0 ) return 0; 

    while (m=(m & (m-1))) {
        count++;
    }

    return count;

}
