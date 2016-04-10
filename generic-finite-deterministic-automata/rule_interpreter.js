'use strict';

const createTable = ( pathDelta, states ) => {

	const fs = require ( 'fs' );

	let buf = fs.readFileSync( __dirname+ '/' +pathDelta, 'utf8' );

	let table = buf.split(/[\s\n]+/);
	let cont = 0;

	let rule = [];

	for ( let i = 0 ; i < states.length ; i++ ) {

		rule[i] = [];

		for ( let j = 0 ; j < states.length ; j++ ) {

			rule[i][j] = table[cont];

			cont++;

		}

	}

	return rule;

}

exports.create = createTable;