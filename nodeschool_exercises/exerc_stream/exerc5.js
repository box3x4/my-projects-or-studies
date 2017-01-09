var thr = require('through2');
var split = require('split');
var cont = 0;

var stream = thr(function kek(buff,enc,next){
	var line = buff.toString();
	this.push(cont%2 === 0 ? line.toLowerCase() + '\n' : line.toUpperCase() + '\n');
	cont++;
	next();
});
process.stdin.pipe(split()).pipe(stream).pipe(process.stdout);