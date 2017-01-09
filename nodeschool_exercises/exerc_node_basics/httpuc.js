var http = require('http');

http.createServer(function(req,res){

	if(req.method==='POST'){

		res.writeHead(200, { 'content-type' : 'text/plain' });

		req.on('data', function(chunk){
			res.write(chunk.toString().toUpperCase());
		});
		req.on('end', function(){
			res.end();
		});
	}

}).listen(process.argv[2]);