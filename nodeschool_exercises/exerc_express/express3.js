var express = require('express');
var app = express();

app.get('/home', function http(req,res){

	var send = new Date();

	app.set('views', process.argv[3]);
	
	app.set('view engine','jade');

	res.render('index', {date: send.toDateString()});

}).listen(process.argv[2]);