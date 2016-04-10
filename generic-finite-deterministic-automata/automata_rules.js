'use strict';

const accept = function ( alfa, current, delta ) {

	for ( let i = 0 ; i < delta.length ; i++ )
		if ( alfa === delta[current][i] )
			return i;

	return -1;

}

exports.accept = accept;