var thr = require('through2');
var stream = thr(write,end);

function write(buff,enc,next){
	this.push(buff.toString().toUpperCase());
	next();
}

function end(done){
	done();
}
process.stdin.pipe(stream).pipe(process.stdout);