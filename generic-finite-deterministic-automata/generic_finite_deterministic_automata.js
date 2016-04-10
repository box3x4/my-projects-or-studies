'use strict';

Array.prototype.contains = function(element){
    return this.indexOf(element) > -1;
};

const rule = require ( './automata_rules' );
const rule_interpreter = require ( './rule_interpreter' );

const tape = process.argv[2].split('');
let tape_head = 0;

const begin = process.argv[6];

const state = process.argv[3].split ( ',' );
let current_state = state.indexOf(begin);

const alfab = process.argv[4].split ( ',' );

const finals = process.argv[5].split ( ',' );

const table_rules = rule_interpreter.create ( process.argv[7], state );

while ( tape_head != tape.length ) {

	if ( !( alfab.contains( tape[tape_head] ) ) )
		break;
	
	current_state = rule.accept( tape[tape_head]
		 	, current_state
		 	, table_rules );

	if ( current_state === -1 )
		break;

	tape_head++;

}

if ( tape_head === tape.length 
	&& finals.contains ( state[current_state] ) ) 
	console.log('sim');
else
	console.log('nao');