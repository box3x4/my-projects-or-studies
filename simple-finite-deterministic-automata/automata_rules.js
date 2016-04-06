'use strict';

const accept = function ( alfa, state ) {

	if ( state === 'q0' && alfa === '1' )
		return 1;
	else if ( state === 'q0' && alfa === '0' )
		return 2;
	else if ( state === 'q0' )
		return 0;

	if ( state === 'q1' && alfa === '1' )
		return -1;
	else if ( state === 'q1' && alfa === '0' )
		return 2;

	if ( state === 'q2' && alfa === '1' )
		return 1;
	else if ( state === 'q2' && alfa === '0' )
		return -2;

	if ( state === 'q3' && alfa === '1' )
		return -1;
	else if ( state === 'q3' && alfa === '0' )
		return -2;

}

exports.accept = accept;