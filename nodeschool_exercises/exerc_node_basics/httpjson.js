var http = require('http');
var url = require('url');


http.createServer(function(req,res){

	var parsedUrl = url.parse(req.url, true);
	var time = new Date(parsedUrl.query.iso);
	var reply;

	res.writeHead(200, {'content-type':'application/json'});

	if(req.method === 'GET'){

		if(parsedUrl.pathname === '/api/parsetime'){
			reply = JSON.stringify({
				'hour': time.getHours(),
		        'minute': time.getMinutes(),
		        'second': time.getSeconds()
			});
		}
		else if(parsedUrl.pathname === '/api/unixtime'){
			reply = JSON.stringify({
				'unixtime': time.getTime()
			});
		}

		res.write(reply);
		res.end();
	}
	else{
		console.log('Send me a GET!');
		res.end();
	}

}).listen(process.argv[2]);