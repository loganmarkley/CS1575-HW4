/* @file: randomengine.h
 * class for random number generation
 * @C - Galaxy Express Software
 *
 * Version 23.3.0
 *
 */
#ifndef RANDOMENGINE_H
#define RANDOMENGINE_H

#include <cstdlib>

using namespace std;

/* ____________________
  /                    \
  | RandomEngine Class |
  \____________________/

	PURPOSE: Implements a random number generator
	with a dice roller function.

*/
class randomEngine
{
public:

  // PURPOSE: Constructor
  //    initializes random number generation with our special seed.
	randomEngine(){
		srand( 123454321 );
	}


  // PURPOSE: Returns the roll of a 'd'-sided dice.
  // RETURNS: A random number between 1 and 'd' (inclusive),
  //          0 if 'd' is invalid.
	int rollD( int d ){
		return  d > 0  ?  (rand() % d) + 1  :  0;
	}

};


#endif
