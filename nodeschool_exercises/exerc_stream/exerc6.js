var concat = require('concat-stream');

function reverse_data(data){
	return data.toString().split('').reverse().join('');
}

process.stdin.pipe(concat(function (body){
	var buff = reverse_data(body);
	console.log(buff);
}));