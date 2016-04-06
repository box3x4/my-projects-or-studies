'use strict';

const rule = require ('./automata_rules');

const tape = process.argv[2];
let tape_head = 0;

const state = ['q0','q1','q2','q3'];
let current_state = 0;

if ( typeof tape === 'string' ) {

	while ( true ) {

		current_state += rule.accept ( tape[tape_head], state[current_state] );
		
		if( tape_head === tape.length && current_state === 0)
			break;
		else if ( tape[tape_head] != '0' && tape[tape_head] != '1' )
			break;
		else
			tape_head++;
		
	}

	if ( tape_head != 0 )
		if ( tape_head === tape.length && current_state === 0 )
				console.log ( 'tape accepted' );
		else
			console.log ( 'tape not accepted' );
	else
		console.log ( 'tape not accepted' );

} else
	console.log ( 'tape accepted' );