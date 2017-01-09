var http = require('http');
var fs = require('fs');


http.createServer(function(req,res){
	res.writeHead(200, { 'Content-Type' : 'text/plain' });

	var read = fs.createReadStream(process.argv[3]);

	read.pipe(res);

}).listen(process.argv[2]);